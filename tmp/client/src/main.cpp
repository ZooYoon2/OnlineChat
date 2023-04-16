#include "TextChat.h"
#include "channel.h"
#include "view.h"
#include <sstream>

SOCKET mSocket;
std::mutex mSend_mtx;
SOCKADDR_IN mServ_addr;

int main_server_init() {
	//주소체계, SOCK_STREAM 연결형, SOCK_DGRAM 비연결형
	mSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	mServ_addr.sin_family = AF_INET;
	mServ_addr.sin_addr.S_un.S_addr = inet_addr(IPADDRESS);
	mServ_addr.sin_port = htons(PORTNO);

	if (mSocket == INVALID_SOCKET) {
		printf("소켓 에러번호 : %d", WSAGetLastError());
		WSACleanup();
		return 1;
	}
	return 0;
}
void main_server_connet() {
	if (connect(mSocket, (LPSOCKADDR)&mServ_addr, sizeof(mServ_addr)) == SOCKET_ERROR) {
		WSACleanup();
	}
}
ptRoomList recv_channel_list() {
	ptRoomList result;
	result.cnt = 0;

	struct PacketHeader ptSend;
	ptSend.Code = 1;
	ptSend.Type = SELECT_ROOM;
	ptSend.PayloadSize = 0;

	mSend_mtx.lock();
	send(mSocket, (char*)&ptSend, sizeof(struct PacketHeader), 0);
	mSend_mtx.unlock();

	int recvSize;
	struct PacketHeader* ptRecv = (struct PacketHeader*)malloc(sizeof(struct PacketHeader));
	do {
		recvSize = recv(mSocket, (char*)ptRecv, sizeof(struct PacketHeader), 0);
		printf("Noop %d\n", ptRecv->Type);
	} while (ptRecv->Type != channelCode::SELECT_ROOM);
	if (recvSize <= 0) {
		exit;
	}
	else {
		printf("%d", ptRecv->PayloadSize);
		if (ptRecv->PayloadSize > 0) {
			char* data = (char*)malloc(ptRecv->PayloadSize);
			recvSize = recv(mSocket, data, ptRecv->PayloadSize, 0);
			std::stringstream st;
			st.write(data, ptRecv->PayloadSize);
			result.deserialize(st);
			free(data);
		}
	}
	free(ptRecv);
	return result;
}

int send_create_room(char* name, int max_user) {
	ptRoom result;
	struct cs_ptCreateRoom ptData;
	ptData.name = name;
	ptData.max_user = max_user;

	std::stringstream dataStream;
	ptData.serialize(dataStream);
	std::string strData = dataStream.str();
	std::vector<char> dataChars(strData.begin(), strData.end());
	dataChars.push_back('\0');
	int dataSize = dataChars.size();

	struct PacketHeader ptHeader;
	ptHeader.Code = 1;
	ptHeader.Type = CREATE_ROOM_RQ;
	ptHeader.PayloadSize = dataSize;

	mSend_mtx.lock();
	send(mSocket, (char*)&ptHeader, sizeof(struct PacketHeader), 0);
	send(mSocket, &dataChars[0], dataSize, 0);
	mSend_mtx.unlock();

	int recvSize;
	struct PacketHeader* ptRecv = (struct PacketHeader*)malloc(sizeof(struct PacketHeader));
	recvSize = recv(mSocket, (char*)ptRecv, sizeof(struct PacketHeader), 0);
	if (recvSize <= 0) {
		exit;
	}
	else {
		if (ptRecv->Type == channelCode::CREATE_ROOM_OK) {
			char* data = (char*)malloc(ptRecv->PayloadSize);
			recvSize = recv(mSocket, data, ptRecv->PayloadSize, 0);
			if (recvSize <= 0) {
				exit;
			}
			std::stringstream st;
			st.write(data, ptRecv->PayloadSize);
			result.deserialize(st);
			free(data);
			free(ptRecv);
			return 1;
		}
		if (ptRecv->Type == channelCode::CREATE_ROOM_ERROR) {
			free(ptRecv);
			return 0;
		}
	}
}

void server_close() {
	printf("서버 연결 종료\n");
	quick_exit(0);
}

int main() {

	WORD wVersionRequired;//원속버전
	WSADATA wasData; //원속정보
	wVersionRequired = MAKEWORD(2, 2);
	if (WSAStartup(wVersionRequired, &wasData) != 0) {
		printf("WSAStartup Error");
		WSACleanup();
	}
	while (main_server_init());
	setup();
	main_server_connet();
	menu();

}
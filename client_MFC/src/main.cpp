#include "pch.h"
#include "main.h"
#include <sstream>

SOCKET mSocket;
std::mutex mSend_mtx;
SOCKADDR_IN mServ_addr;

void check_connect_state(CStatic* t_state) {
	struct PacketHeader ptSend;
	ptSend.Code = 1;
	ptSend.Type = CONNECT_OK;
	ptSend.PayloadSize = 0;
	int recvSize;
	int c;
	while (1) {
		mSend_mtx.lock();
		send(mSocket, (char*)&ptSend, sizeof(struct PacketHeader), 0);
		mSend_mtx.unlock();
		recvSize = recv(mSocket, (char*)&c, sizeof(int), 0);
		if (recvSize <= 0) {
			t_state->SetWindowText(_T("접속 끊김"));
		}
		else {
			t_state->SetWindowText(_T("접속"));
		}
		Sleep(10000);
	}
}

int main_server_init() {
	//주소체계, SOCK_STREAM 연결형, SOCK_DGRAM 비연결형
	mSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	mServ_addr.sin_family = AF_INET;
	mServ_addr.sin_addr.S_un.S_addr = inet_addr(IPADDRESS);
	mServ_addr.sin_port = htons(MAIN_PORTNO);

	if (mSocket == INVALID_SOCKET) {
		printf("소켓 에러번호 : %d", WSAGetLastError());
		WSACleanup();
		return 0;
	}
	return 1;
}
int main_server_connet() {
	if (connect(mSocket, (LPSOCKADDR)&mServ_addr, sizeof(mServ_addr)) == SOCKET_ERROR) {
		WSACleanup();
		return 0;
	}
	return 1;
}
int main_server_login(char* name) {
	struct PacketHeader ptSend;
	ptSend.Code = 1;
	ptSend.Type = channelCode::LOGIN_RQ;

	struct cs_ptLogin ptData;
	ptData.name = name;

	//추후 auto(template) 함수로 변경
	std::stringstream dataStream;
	ptData.serialize(dataStream);
	std::string strData = dataStream.str();
	std::vector<char> dataChars(strData.begin(), strData.end());
	dataChars.push_back('\0');
	int dataSize = dataChars.size();

	ptSend.PayloadSize = dataSize;

	mSend_mtx.lock();
	send(mSocket, (char*)&ptSend, sizeof(struct PacketHeader), 0);
	send(mSocket, &dataChars[0], dataSize, 0);
	mSend_mtx.unlock();

	int recvSize;
	struct PacketHeader* ptRecv = (struct PacketHeader*)malloc(sizeof(struct PacketHeader));
	recvSize = recv(mSocket, (char*)ptRecv, sizeof(struct PacketHeader), 0);
	if (recvSize <= 0) {
		return 0;
	}
	else {
		if (ptRecv->Type == channelCode::LOGIN_OK) {

		}
		else if (ptRecv->Type == channelCode::LOGIN_FAIL) {

		}
	}
}

ptRoomList recv_channel_list() {
	ptRoomList result;
	result.cnt = 0;

	struct PacketHeader ptSend;
	ptSend.Code = 1;
	ptSend.Type = channelCode::SELECT_ROOM;
	ptSend.PayloadSize = 0;
	
	mSend_mtx.lock();
	send(mSocket, (char*)&ptSend, sizeof(struct PacketHeader), 0);
	mSend_mtx.unlock();

	int recvSize;
	struct PacketHeader* ptRecv = (struct PacketHeader*)malloc(sizeof(struct PacketHeader));
	recvSize = recv(mSocket, (char*)ptRecv, sizeof(struct PacketHeader), 0);
	if (recvSize <= 0) {
		exit;
	}
	else {
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

unsigned int send_create_room(char* name, int max_user) {
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
	ptHeader.Type = channelCode::CREATE_ROOM_RQ;
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
			struct sc_ptCreateRoom ptData;
			ptData.deserialize(st);
			free(data);
			free(ptRecv);
			return ptData.id;
		}
		if (ptRecv->Type == channelCode::CREATE_ROOM_ERROR) {
			free(ptRecv);
			return 0;
		}
	}
}
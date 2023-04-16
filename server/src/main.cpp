#include "mainServer.h"
#include "GameServer.h"
#include "ChatServer.h"


int main() {
	WORD wVersionRequired;//원속버전
	WSADATA wasData; //원속정보
	wVersionRequired = MAKEWORD(2, 2);
	if (WSAStartup(wVersionRequired, &wasData)!=0) {
		printf("WSAStartup Error\n");
		WSACleanup();
	}

	Lobby* lobby = new Lobby(10, 30);
	
	MainServer mServer(MAIN_PORTNO, IPADDRESS, 5, lobby);
	
	mServer.TestRoomList();
	mServer.run_addClient_thread();

	GameServer gServer(GAME_PORTNO, IPADDRESS, 5, lobby);
	gServer.run_addClient_thread();

	ChatServer cServer(CHAT_PORTNO, IPADDRESS, 5, lobby);
	cServer.run_addClient_thread();
	
	while (1);
}

/*
void main_server_init() {
	//주소체계, SOCK_STREAM 연결형, SOCK_DGRAM 비연결형
	mSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	SOCKADDR_IN serv_addr;
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.S_un.S_addr = inet_addr(IPADDRESS);
	serv_addr.sin_port = htons(PORTNO);


	if (mSocket == INVALID_SOCKET) {
		printf("소켓 에러번호 : %d\n", WSAGetLastError());
		WSACleanup();
	}

	if (bind(mSocket, (LPSOCKADDR)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR) {
		printf("bind 에러번호 : %d\n", WSAGetLastError());
		WSACleanup();
	}

	listen(mSocket, 5);
}

void send_roomList(SOCKADDR_IN client_addr, int client_addrSize) {
	ptRoomList roomList;
	roomList.cnt = cnt_channel;
	roomList.rooms = (ptRoom*)malloc(sizeof(rooms) * cnt_channel);
	for (int i = 0; i < cnt_channel; i++) {
		roomList.rooms[i] = rooms[i].send_ptRoom();
	}
	std::stringstream st;
	roomList.serialize(st);
	std::string str = st.str();
	std::vector<char> chars(str.begin(), str.end());
	chars.push_back('\0');

	struct PacketHeader ptSend;
	ptSend.Code = 1;
	ptSend.Type = channelCode::SELECT_ROOM;
	ptSend.PayloadSize = chars.size();

	sendto(mSocket, (char*)&ptSend, sizeof(struct PacketHeader), 0, (struct sockaddr*)&client_addr, client_addrSize);
	sendto(mSocket, (char*)&chars[0], ptSend.PayloadSize, 0, (struct sockaddr*)&client_addr, client_addrSize);
}

void send_roomList_json(struct ptSelectRoom* dt,SOCKADDR_IN client_addr, int client_addrSize) {
	json data;

	for (int i = 0; i < cnt_channel; i++) {
		json obj = rooms[i].send_json();
		data.push_back(obj);
	}
	std::cout << data.dump() << std::endl;
	if (data.is_null()) {
		int aws = -1;
		sendto(mSocket, (char*)&aws, sizeof(int), 0, (struct sockaddr*)&client_addr, client_addrSize);
	}
	else {
		int strLen = strlen(data.dump().c_str()) + 1;
		sendto(mSocket, (char*)&strLen, sizeof(int), 0, (struct sockaddr*)&client_addr, client_addrSize);
		sendto(mSocket, data.dump().c_str(), strLen, 0, (struct sockaddr*)&client_addr, client_addrSize);
	}
}

void main_server_recv() {

	SOCKADDR_IN client_addr;
	int client_addrSize = sizeof(client_addr);
	int RecvSize;

	printf("명령어 서버 실행완료\n");
	struct PacketHeader* ptHeader = (struct PacketHeader*)malloc(sizeof(struct PacketHeader));
	while (1) {
		RecvSize = recvfrom(mSocket, (char*)ptHeader, sizeof(struct PacketHeader), 0, (struct sockaddr*)&client_addr, &client_addrSize);
		if (RecvSize < 0) {
			printf("recvfrom() Error");
			continue;
		}
		printf("수신 클라이언트 ip = %s port = %d - ", inet_ntoa(client_addr.sin_addr),client_addr.sin_port);
		printf("요청 : %d\n", ptHeader->Code);
		switch (ptHeader->Type) {
		case SELECT_ROOM:
		{
			std::thread th(send_roomList, client_addr, client_addrSize);
			th.detach();
			break;
		}
		default:
			continue;
		}

	}
	free(ptHeader);
}
*/

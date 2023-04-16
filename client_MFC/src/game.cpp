#include "pch.h"
#include "game.h"

SOCKET gSocket;
std::mutex gSend_mtx;
SOCKADDR_IN gServ_addr;

void check_game_server_state(CStatic* t_state) {
	struct PacketHeader ptSend;
	ptSend.Code = 1;
	ptSend.Type = gameCode::GAME_STATE_OK;
	ptSend.PayloadSize = 0;
	int recvSize;
	int c;
	while (1) {
		gSend_mtx.lock();
		send(gSocket, (char*)&ptSend, sizeof(struct PacketHeader), 0);
		gSend_mtx.unlock();
		recvSize = recv(gSocket, (char*)&c, sizeof(int), 0);
		if (recvSize <= 0) {
			t_state->SetWindowText(_T("접속 끊김"));
			return;
		}
		t_state->SetWindowText(_T("접속"));
		Sleep(10000);
	}
}

int game_server_init() {
	//주소체계, SOCK_STREAM 연결형, SOCK_DGRAM 비연결형
	gSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	gServ_addr.sin_family = AF_INET;
	gServ_addr.sin_addr.S_un.S_addr = inet_addr(IPADDRESS);
	gServ_addr.sin_port = htons(GAME_PORTNO);

	if (gSocket == INVALID_SOCKET) {
		printf("소켓 에러번호 : %d", WSAGetLastError());
		WSACleanup();
		return 0;
	}
	return 1;
}

int game_server_connet() {
	if (connect(gSocket, (LPSOCKADDR)&gServ_addr, sizeof(gServ_addr)) == SOCKET_ERROR) {
		WSACleanup();
		return 0;
	}
	return 1;
}

int game_server_access(char* name) {
	struct PacketHeader ptSend;
	ptSend.Code = 1;
	ptSend.Type = gameCode::ACCESS_GAME_SERVER;

	struct ptACCESS_RQ ptData;
	ptData.name = name;

	//추후 auto(template) 함수로 변경
	std::stringstream dataStream;
	ptData.serialize(dataStream);
	std::string strData = dataStream.str();
	std::vector<char> dataChars(strData.begin(), strData.end());
	dataChars.push_back('\0');
	int dataSize = dataChars.size();

	ptSend.PayloadSize = dataSize;

	gSend_mtx.lock();
	send(gSocket, (char*)&ptSend, sizeof(struct PacketHeader), 0);
	send(gSocket, &dataChars[0], dataSize, 0);
	gSend_mtx.unlock();

	int recvSize;
	struct PacketHeader* ptRecv = (struct PacketHeader*)malloc(sizeof(struct PacketHeader));
	recvSize = recv(gSocket, (char*)ptRecv, sizeof(struct PacketHeader), 0);
	if (recvSize <= 0) {
		return 0;
	}
	else {
		if (ptRecv->Type == gameCode::ACCESS_GAME_SERVER) {
			return 1;
		}
		else if (ptRecv->Type == gameCode::EXHALE_GAME_SERVER) {
			return 0;
		}
	}
	return 0;
}

void entry_room(unsigned int id) {
	struct PacketHeader ptSend;
	ptSend.Code = 1;
	ptSend.Type = gameCode::ACCESS_GAME_SERVER;

	struct ptACCESS_RQ ptData;
	ptData.name = name;

	//추후 auto(template) 함수로 변경
	std::stringstream dataStream;
	ptData.serialize(dataStream);
	std::string strData = dataStream.str();
	std::vector<char> dataChars(strData.begin(), strData.end());
	dataChars.push_back('\0');
	int dataSize = dataChars.size();

	ptSend.PayloadSize = dataSize;

	gSend_mtx.lock();
	send(gSocket, (char*)&ptSend, sizeof(struct PacketHeader), 0);
	send(gSocket, &dataChars[0], dataSize, 0);
	gSend_mtx.unlock();

	int recvSize;
	struct PacketHeader* ptRecv = (struct PacketHeader*)malloc(sizeof(struct PacketHeader));
	recvSize = recv(gSocket, (char*)ptRecv, sizeof(struct PacketHeader), 0);
	if (recvSize <= 0) {
		return 0;
	}
	else {
		if (ptRecv->Type == gameCode::ACCESS_GAME_SERVER) {
			return 1;
		}
		else if (ptRecv->Type == gameCode::EXHALE_GAME_SERVER) {
			return 0;
		}
	}
	return 0;
}
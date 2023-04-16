#include "pch.h"
#include "chat.h"

SOCKET cSocket; 
std::mutex cSend_mtx;
SOCKADDR_IN cServ_addr;

void check_chat_server_state(CStatic* t_state) {
	struct PacketHeader ptSend;
	ptSend.Code = 1;
	ptSend.Type = chatCode::CHAT_STATE_OK;
	ptSend.PayloadSize = 0;
	int recvSize;
	int c;
	while (1) {
		cSend_mtx.lock();
		send(cSocket, (char*)&ptSend, sizeof(struct PacketHeader), 0);
		cSend_mtx.unlock();
		recvSize = recv(cSocket, (char*)&c, sizeof(int), 0);
		if (recvSize <= 0) {
			t_state->SetWindowText(_T("접속 끊김"));
			return;
		}
		t_state->SetWindowText(_T("접속"));
		Sleep(10000);
	}
}

int chat_server_init() {
	//주소체계, SOCK_STREAM 연결형, SOCK_DGRAM 비연결형
	cSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	cServ_addr.sin_family = AF_INET;
	cServ_addr.sin_addr.S_un.S_addr = inet_addr(IPADDRESS);
	cServ_addr.sin_port = htons(CHAT_PORTNO);

	if (cSocket == INVALID_SOCKET) {
		printf("소켓 에러번호 : %d", WSAGetLastError());
		WSACleanup();
		return 0;
	}
	return 1;
}

int chat_server_connet() {
	if (connect(cSocket, (LPSOCKADDR)&cServ_addr, sizeof(cServ_addr)) == SOCKET_ERROR) {
		WSACleanup();
		return 0;
	}
	return 1;
}

int chat_server_access(char* name) {
	struct PacketHeader ptSend;
	ptSend.Code = 1;
	ptSend.Type = chatCode::ACCESS_CHAT_SERVER;

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

	cSend_mtx.lock();
	send(cSocket, (char*)&ptSend, sizeof(struct PacketHeader), 0);
	send(cSocket, &dataChars[0], dataSize, 0);
	cSend_mtx.unlock();

	int recvSize;
	struct PacketHeader* ptRecv = (struct PacketHeader*)malloc(sizeof(struct PacketHeader));
	recvSize = recv(cSocket, (char*)ptRecv, sizeof(struct PacketHeader), 0);
	if (recvSize <= 0) {
		return 0;
	}
	else {
		if (ptRecv->Type == chatCode::ACCESS_CHAT_SERVER) {
			return 1;
		}
		else if (ptRecv->Type == chatCode::EXHALE_CHAT_SERVER) {
			return 0;
		}
	}
	return 0;
}

void recv_server() {
	while (1) {
		int RecvSize;
		char buffer[BUFFER_SIZE];
		RecvSize = recv(cSocket, buffer, BUFFER_SIZE, 0);
		if (RecvSize <= 0) {
			//server_close();
		}

		//printf("패킷 수신 클라이언트 정보 %d", inet_ntoa(client_addr.sin_addr));
		buffer[RecvSize] = '\0';
		printf("%s\n", buffer);
	}
}
char* getString() {
	char msg[BUFFER_SIZE];
	char* data=NULL;
	int strLen = 0;
	while (1) {
		fgets(msg, BUFFER_SIZE, stdin);
		strLen += strlen(msg);
		if (data == NULL) {
			data = (char*)malloc(strLen + 1);
			strcpy_s(data, strLen + 1, msg);
		}
		else {
			data = (char*)realloc(data, strLen + 1);
			strcat_s(data, strLen + 1, msg);
		}
		if (msg[strlen(msg)-1] == '\n') {
			break;
		}
	}
	return data;
}
void testChat_init() {
	//주소체계, SOCK_STREAM 연결형, SOCK_DGRAM 비연결형
	cSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	//mSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	SOCKADDR_IN serv_addr;
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.S_un.S_addr = inet_addr(IPADDRESS);
	serv_addr.sin_port = htons(CHAT_PORTNO);

	if (cSocket == INVALID_SOCKET) {
		printf("소켓 에러번호 : %d", WSAGetLastError());
		WSACleanup();
	}
	if (connect(cSocket, (LPSOCKADDR)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR) {
		printf("접속 실패");
		WSACleanup();
		return;
	}
	else {
		printf("접속 성공\n");
		std::thread th(recv_server);
		th.detach();
	}
}
void send_msg() {
	char msg[BUFFER_SIZE];
	char* data;
	int strLen = 0;
	while (1) {
		printf("메세지입력(q입력시 종료) : ");
		data = getString();
		if (strcmp(msg, "q\n") == 0) {
			closesocket(cSocket);
			break;
		}
		int datasize = strlen(data) + 1;
		send(cSocket, (char*)&datasize, sizeof(int), 0);
		int send_size = send(cSocket, data, strlen(data), 0);
		free(data);
		if (send_size == -1) {
			//server_close();
		};

	}
}
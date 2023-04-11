#include "TextChat.h"

SOCKET tSocket;

void recv_server() {
	while (1) {
		int RecvSize;
		int SendSize;
		char buffer[BUFFER_SIZE];

		RecvSize = recv(tSocket, buffer, BUFFER_SIZE, 0);
		if (RecvSize <= 0) {
			server_close();
		}

		//printf("��Ŷ ���� Ŭ���̾�Ʈ ���� %d", inet_ntoa(client_addr.sin_addr));
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
	//�ּ�ü��, SOCK_STREAM ������, SOCK_DGRAM �񿬰���
	tSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	//mSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	SOCKADDR_IN serv_addr;
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.S_un.S_addr = inet_addr(IPADDRESS);
	serv_addr.sin_port = htons(PORTNO);

	if (tSocket == INVALID_SOCKET) {
		printf("���� ������ȣ : %d", WSAGetLastError());
		WSACleanup();
	}
	if (connect(tSocket, (LPSOCKADDR)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR) {
		printf("���� ����");
		WSACleanup();
		return;
	}
	else {
		printf("���� ����\n");
		std::thread th(recv_server);
		th.detach();
	}
}
void send_msg() {
	char msg[BUFFER_SIZE];
	char* data;
	int strLen = 0;
	while (1) {
		printf("�޼����Է�(q�Է½� ����) : ");
		data = getString();
		if (strcmp(msg, "q\n") == 0) {
			closesocket(tSocket);
			break;
		}
		int datasize = strlen(data) + 1;
		send(tSocket, (char*)&datasize, sizeof(int), 0);
		int send_size = send(tSocket, data, strlen(data), 0);
		free(data);
		if (send_size == -1) {
			server_close();
		};

	}
}
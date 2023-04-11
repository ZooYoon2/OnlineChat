#include "TextChat.h"
#include "channel.h"

SOCKET mSocket;
channel channels[MAX_CHANNEL];
int cnt_channel = 0;

void main_server_init() {
	//�ּ�ü��, SOCK_STREAM ������, SOCK_DGRAM �񿬰���
	mSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	SOCKADDR_IN serv_addr;
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.S_un.S_addr = inet_addr(IPADDRESS);
	serv_addr.sin_port = htons(PORTNO);


	if (mSocket == INVALID_SOCKET) {
		printf("���� ������ȣ : %d\n", WSAGetLastError());
		WSACleanup();
	}

	if (bind(mSocket, (LPSOCKADDR)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR) {
		printf("bind ������ȣ : %d\n", WSAGetLastError());
		WSACleanup();
	}

	listen(mSocket, 5);
}

void main_server_recv() {
	int RecvSize;
	int SendSize;
	char buffer[20];
	SOCKADDR_IN client_addr;
	int client_addrSize = sizeof(client_addr);
	printf("��ɾ� ���� ����Ϸ�\n");
	while (1) {
		RecvSize = recvfrom(mSocket, buffer, 20, 0, (struct sockaddr*)&client_addr, &client_addrSize);
		if (RecvSize < 0) {
			printf("recvfrom() Error");
			return;
		}
		printf("���� Ŭ���̾�Ʈ ip = %s port = %d - ", inet_ntoa(client_addr.sin_addr),client_addr.sin_port);
		buffer[RecvSize] = '\0';
		printf("��û : %s\n", buffer);
		if (strcmp("channel info", buffer) == 0) {
			char* data = NULL;
			int strLen = 0;
			for (int i = 0; i < cnt_channel; i++) {
				const char* dt = channels[i].send();
				strLen += strlen(dt);
				if (data == NULL) {
					data = (char*)malloc(strLen + 1);
					strcpy_s(data, strLen + 1, dt);
				}
				else {
					data = (char*)realloc(data, strLen + 1);
					strcat_s(data, strLen + 1, dt);
				}
			}
			if (data == NULL) {
				sendto(mSocket, data, strLen, 0, (struct sockaddr*)&client_addr, client_addrSize);
			}
			else {
				sendto(mSocket, data, strLen, 0, (struct sockaddr*)&client_addr, client_addrSize);
			}
			
		}
	}
}

int main() {
	json obj = { {"id", 1},
			   {"name", "snowdeer"},
			   {"age", 45} };
	std::string str = "{ {\"id\", 1},{\"name\", \"snowdeer\"},{ \"age\", 45 }}";
	const char chars[] = "{ {\"id\", 1},{\"name\", \"snowdeer\"},{ \"age\", 45 }}";
	printf("json - %d bytes\nstring - %d bytes\nchar* - %d bytes",sizeof(obj),sizeof(str),sizeof(chars));

	/*
	WORD wVersionRequired;//���ӹ���
	WSADATA wasData; //��������
	wVersionRequired = MAKEWORD(2, 2);
	if (WSAStartup(wVersionRequired, &wasData)!=0) {
		printf("WSAStartup Error\n");
		WSACleanup();
	}
	//TC_server_init();
	//TC_client_add();
	main_server_init();

	std::thread th(main_server_recv);
	th.detach();
	while (1);
	*/
}

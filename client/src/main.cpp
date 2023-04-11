#include "TextChat.h"
#include "view.h"
#include "channel.h"

SOCKET mSocket;
SOCKADDR_IN mServ_addr;
int main_server_init() {
	//�ּ�ü��, SOCK_STREAM ������, SOCK_DGRAM �񿬰���
	mSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	mServ_addr.sin_family = AF_INET;
	mServ_addr.sin_addr.S_un.S_addr = inet_addr(IPADDRESS);
	mServ_addr.sin_port = htons(PORTNO);

	if (mSocket == INVALID_SOCKET) {
		printf("���� ������ȣ : %d", WSAGetLastError());
		WSACleanup();
		return 1;
	}
	return 0;
}
void main_server_connet() {
	if (connect(mSocket, (LPSOCKADDR)&mServ_addr, sizeof(mServ_addr)) == SOCKET_ERROR) {
		title_to_servInfo(false);
		WSACleanup();
	}
	else {
		title_to_servInfo(true);
	}
}
void recv_channel_list() {
	send(mSocket, "channel info", sizeof("channel info"), 0);
	int RecvSize;
	int SendSize;
	char buffer[20];
	RecvSize = recv(mSocket, buffer, 20, 0);
	if (RecvSize <= 0) {
		server_close();
	}
	//printf("��Ŷ ���� Ŭ���̾�Ʈ ���� %d", inet_ntoa(client_addr.sin_addr));
	buffer[RecvSize] = '\0';
	printf("%s\n", buffer);
}
void server_close() {
	printf("���� ���� ����\n");
	quick_exit(0);
}

int main() {
	WORD wVersionRequired;//���ӹ���
	WSADATA wasData; //��������
	wVersionRequired = MAKEWORD(2, 2);
	if (WSAStartup(wVersionRequired, &wasData) != 0) {
		printf("WSAStartup Error");
		WSACleanup();
	}
	while (main_server_init());
	setup();
	main_server_connet();
	logo();
	menu();
}
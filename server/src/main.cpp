#include "TextChat.h"

int main() {
	WORD wVersionRequired;//���ӹ���
	WSADATA wasData; //��������
	wVersionRequired = MAKEWORD(2, 2);
	if (WSAStartup(wVersionRequired, &wasData)!=0) {
		printf("WSAStartup Error\n");
		WSACleanup();
	}
	TC_server_init();
	TC_client_add();
	
	/* 
	//UDP send
	int client_addrSize;
	int RecvSize;
	int SendSize;
	char buffer[BUFFER_SIZE];
	while (1) {
		client_addrSize = sizeof(client_addr);
		RecvSize = recvfrom(mSocket, buffer, BUFFER_SIZE, 0, (struct sockaddr*)&client_addr, &client_addrSize);
		if (RecvSize < 0) {
			printf("recvfrom() Error");
			return 0;
		}
		printf("��Ŷ ���� Ŭ���̾�Ʈ ���� %d", inet_ntoa(client_addr.sin_addr));
		buffer[RecvSize] = '\0';
		printf("������ : %s", buffer);
	}
	*/
}

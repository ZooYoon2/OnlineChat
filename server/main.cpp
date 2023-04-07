#include "TextChat.h"

int main() {
	WORD wVersionRequired;//원속버전
	WSADATA wasData; //원속정보
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
		printf("패킷 수신 클라이언트 정보 %d", inet_ntoa(client_addr.sin_addr));
		buffer[RecvSize] = '\0';
		printf("데이터 : %s", buffer);
	}
	*/
}

#include "TextChat.h"
#include "view.h"
void server_close() {
	printf("���� ���� ����\n");
	quick_exit(0);
}

int main() {
	setup();
	logo();
	menu();
	
	/*
	WORD wVersionRequired;//���ӹ���
	WSADATA wasData; //��������
	wVersionRequired = MAKEWORD(2, 2);
	if (WSAStartup(wVersionRequired, &wasData) != 0) {
		printf("WSAStartup Error");
		WSACleanup();
	}
	testChat_init();
	while (1) {
		view();
	}
	*/
}
#include "TextChat.h"
#include "view.h"
void server_close() {
	printf("서버 연결 종료\n");
	quick_exit(0);
}

int main() {
	setup();
	logo();
	menu();
	
	/*
	WORD wVersionRequired;//원속버전
	WSADATA wasData; //원속정보
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
#pragma once
#include "SCH.h"

typedef struct user {
	SOCKET s;
	char name[20];
	char ipaddr[12];
}user;

void TC_server_init();
void TC_recv_client(int idx);
void TC_client_add();
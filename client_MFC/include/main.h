#pragma once
#include "SCH.h"
#include "LobbyProtocol.h"

class user {
private:
	int id;
	int name;
};

class Room {
private:
	int id;
	int name;
	user* host;
	int cnt_user;
	int max_user;
	user* users;
public:
};

void check_connect_state(CStatic* t_state);
int main_server_init();
int main_server_connet();
int main_server_login(char* name);

ptRoomList recv_channel_list();
unsigned int send_create_room(char* name, int max_user);
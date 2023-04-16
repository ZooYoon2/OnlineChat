#pragma once
#include "SCH.h"
#include "LobbyProtocol.h"

#define MAX_CHANNEL 10

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

ptRoomList recv_channel_list();
int send_create_room(char* name, int max_user);
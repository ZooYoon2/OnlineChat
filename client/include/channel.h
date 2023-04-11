#pragma once
#include "SCH.h"

#define MAX_CHANNEL 10

class user {
private:
	int id;
	int name;
};

class channel {
private:
	int id;
	int name;
	user host;
	int cnt_user;
	int max_user;
	user* users;
public:
};


void recv_channel_list();
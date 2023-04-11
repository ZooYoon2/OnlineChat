#pragma once
#include "SCH.h"
#include <format>

#define MAX_CHANNEL 10

class user {
private:
	int id;
	const char* name;
	SOCKADDR_IN addr;
public:
	SOCKET socket;
	int get_id() { return this->id; }
	void set_id(int id) { this->id = id; }
	const char* get_name() { return this->name; }
};

class channel {
private:
	int id;
	const char* name;
	user* host;
	int cnt_user;
	int max_user;
	user* users;

public:
	channel();
	channel(const char* str);
	channel(int id, const char* name, user* host, int cnt_user, int max_user, user* users);
	const char* send();
};
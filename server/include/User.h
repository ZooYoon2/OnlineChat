#pragma once
#include "SCH.h"

class User {
private:
	char* name;

public:
	SOCKADDR_IN addr;
	SOCKET mSocket;
	SOCKET gSocket;
	SOCKET cSocket;
	User() {};
	User(char* name) {
		this->name = name;
	}
	User(char* name, SOCKADDR_IN addr, SOCKET mSocket) {
		this->name = name;
		this->addr = addr;
		this->mSocket = mSocket;
	}
	void setMainServerSocket(SOCKET mSocket) { this->mSocket = mSocket; }
	void setGameServerSocket(SOCKET gSocket) { this->gSocket = gSocket; }
	void setChatServerSocket(SOCKET cSocket) { this->cSocket = cSocket; }
	char* getName() { return this->name; }
};
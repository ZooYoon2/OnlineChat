#pragma once
#include "SCH.h"
#include "User.h"
#include "GameProtocol.h"
#include "LobbyProtocol.h"

class GameRoom;
enum GameJob {

};
class GamePlayer {
private:
	int id;
	GameJob job;
	User* user;
	friend GameRoom;

public:
	GamePlayer() { 
		this->id = 0;
		this->user = nullptr; 
	}
};

class GameRoom {
	int id;
	char* name;
	User* host;
	int cnt_user;
	int max_user;
	GamePlayer* gamePlayers;
	//RoomType type = RoomType::PUBLIC;
public:
	GameRoom() {};
	GameRoom(const char* str);
	GameRoom(int id, char* name, User* host, int cnt_user, int max_user) {
		this->id = id;
		this->name = name;
		this->host = host;
		this->cnt_user = cnt_user;
		this->max_user = max_user;
		this->gamePlayers = new GamePlayer[this->max_user];
		EnterUser(host);
	};
	int getId() { return this->id; }
	char* getName() { return this->name; }
	User* getHost() { return this->host; }
	int getCnt_user() { return this->cnt_user; }
	int getMax_user() { return this->max_user; }

	ptRoom send_ptRoom(){
		ptRoom rm;
		rm.id = this->id;
		rm.name = this->name;
		rm.host_name = this->host->getName();
		rm.cnt_user = this->cnt_user;
		rm.max_user = this->max_user;
		//rm.type = this->type;
		return rm;
	}

	int is_full() {
		if (cnt_user >= max_user)
			return 1;
		else
			return 0;
	}
	void EnterUser(User* user) {
		for (int i = 0; i < this->max_user; i++) {
			if (gamePlayers[i].user == nullptr) {
				gamePlayers[i].user = user;
				gamePlayers[i].id = i;
			}
		}
	}
	void OutUser(int id) {
		gamePlayers[id].user = nullptr;
	}
};

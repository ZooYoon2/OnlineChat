#pragma once
#include "SCH.h"
#include "User.h"
#include "GameRoom.h"

class Lobby {
	int max_room;
	std::unordered_map<unsigned int, GameRoom>* rooms;
	std::mutex rooms_mtx;

	int max_user;
	std::unordered_map<unsigned int, User>* users;
	std::mutex users_mtx;
public:
	Lobby(int max_room, int max_user) {
		this->max_room = max_room;
		this->max_user = max_user;
		rooms = new std::unordered_map<unsigned int, GameRoom>;
		users = new std::unordered_map<unsigned int, User>;
	};
	bool is_full_rooms() {
		rooms_mtx.lock();
		if (rooms->size() >= max_room) {
			rooms_mtx.unlock();
			return true;
		}
		rooms_mtx.unlock();
		return false;
	}
	bool is_empty_rooms() {
		rooms_mtx.lock();
		if (rooms->size()==0) {
			rooms_mtx.unlock();
			return true;
		}
		rooms_mtx.unlock();
		return false;
	}
	int getMaxRoom() { return max_room; }
	std::unordered_map<unsigned int, GameRoom>* refer_to_rooms() { rooms_mtx.lock(); return rooms; }
	void refer_to_rooms_end() { rooms_mtx.unlock();}

	bool is_full_users() {
		users_mtx.lock();
		if (users->size() >= max_user) {
			users_mtx.unlock();
			return true;
		}
		users_mtx.unlock();
		return false;
	}
	bool is_empty_users() {
		users_mtx.lock();
		if (users->size() == 0) {
			users_mtx.unlock();
			return true;
		}
		users_mtx.unlock();
		return false;
	}
	int getMaxUser() { return max_user; }
	std::unordered_map<unsigned int, User>* refer_to_users() { users_mtx.lock(); return users; }
	void refer_to_users_end() { users_mtx.unlock(); }
	int is_find_user(int id) {
		users_mtx.lock();
		if (users->find(id) != users->end()) {
			users_mtx.unlock();
			return 1;
		}
		else {
			users_mtx.unlock();
			return 0;
		}
	}
};

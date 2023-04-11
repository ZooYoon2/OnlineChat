#include "channel.h"

const char* channel::send() {
	return std::format("\{{{};{};{};{};{}}}",this->id, this->name, this->host->get_id(),this->cnt_user,this->max_user).c_str();
}
//channel::channel(const char* str) {}
channel::channel() {};
channel::channel(int id, const char* name, user* host, int cnt_user, int max_user, user* users) {
	this->id = id;
	this->name = name;
	this->host = host;
	this->cnt_user = cnt_user;
	this->max_user = max_user;
	this->users = users;
}
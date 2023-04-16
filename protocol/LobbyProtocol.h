#pragma once
#include "Protocol.h"
#pragma pack(push,1)
#pragma pack(pop)

enum channelCode : unsigned short {
	LOGIN_RQ = 0,
	LOGIN_OK,
	LOGIN_FAIL,
	CONNECT_OK,
	CREATE_ROOM_RQ,
	CREATE_ROOM_OK,
	CREATE_ROOM_ERROR,
	SELECT_ROOM,
	CONNECT_ROOM,
	DISCONNECT_ROOM
};

enum RoomType {
	PUBLIC = 0,
	PRIVATE=1
};

#pragma pack(push,1)
struct cs_ptLogin {
	char* name = nullptr;
	std::ostream& serialize(std::ostream& os) const {
		char null = '\0';
		os.write(name, strlen(name));
		os.write(&null, 1);
		return os;
	}
	std::istream& deserialize(std::istream& is) {
		if (name != nullptr) {
			free(name);
		}
		std::string nameTmp = "";
		while (1) {
			char tmp = is.get();
			nameTmp.push_back(tmp);
			if (tmp == '\0') {
				break;
			}
		}
		std::vector<char> nameChars(nameTmp.begin(), nameTmp.end());
		nameChars.push_back('\0');
		name = (char*)malloc(nameChars.size());
		strcpy_s(name, nameChars.size(), &nameChars[0]);
		return is;
	}
};
#pragma pack(pop)

#pragma pack(push,1)
struct ptRoom {
	int id;
	char* name = nullptr;
	int cnt_user;
	int max_user;
	//RoomType type;
	char* host_name = nullptr;
	std::ostream& serialize(std::ostream& os) const{
		char null = '\0';
		os.write((char*)&id, sizeof(id));
		os.write(name, strlen(name));
		os.write(&null, 1);
		os.write((char*)&cnt_user, sizeof(cnt_user));
		os.write((char*)&max_user, sizeof(max_user));
		//os.write((char*)&type, sizeof(type));
		os.write(host_name, strlen(host_name));
		os.write(&null, 1);
		return os;
	}
	std::istream& deserialize(std::istream& is) {
		is.read((char*)&id, sizeof(id));
		if (name != nullptr) {
			free(name);
		}
		std::string nameTmp="";
		while (1) {
			char tmp = is.get();
			nameTmp.push_back(tmp);
			if (tmp == '\0') {
				break;
			}
		}
		std::vector<char> nameChars(nameTmp.begin(), nameTmp.end());
		nameChars.push_back('\0');
		name = (char*)malloc(nameChars.size());
		strcpy_s(name, nameChars.size(), &nameChars[0]);

		is.read((char*)&cnt_user, sizeof(cnt_user));
		is.read((char*)&max_user, sizeof(max_user));
		//is.read((char*)&type, sizeof(type));

		if (host_name != nullptr) {
			free(host_name);
		}
		std::string host_nameTmp = "";
		while (1) {
			char tmp = is.get();
			host_nameTmp.push_back(tmp);
			if (tmp == '\0') {
				break;
			}
		}
		std::vector<char> host_nameChars(host_nameTmp.begin(), host_nameTmp.end());
		host_nameChars.push_back('\0');
		host_name = (char*)malloc(host_nameChars.size());
		strcpy_s(host_name, host_nameChars.size(), &host_nameChars[0]);
		return is;
	}
};
#pragma pack(pop)

#pragma pack(push,1)
struct ptRoomList {
	int cnt;
	ptRoom* rooms=nullptr;
	std::ostream& serialize(std::ostream& os) const {
		os.write((char*)&cnt, sizeof(cnt));
		for (int i = 0; i < cnt; i++) {
			rooms[i].serialize(os);
		}
		return os;
	}
	std::istream& deserialize(std::istream& is) {
		is.read((char*)&cnt, sizeof(cnt));
		if (rooms != nullptr){
			free(rooms);
		}
		rooms = (ptRoom*)malloc(sizeof(ptRoom) * cnt);
		for (int i = 0; i < cnt; i++) {
			ptRoom tmp;
			tmp.deserialize(is);
			rooms[i] = tmp;
			//memcpy_s(&rooms[i], sizeof(struct ptRoom), &tmp, sizeof(struct ptRoom));
		}
		return is;
	}
};
#pragma pack(pop)

#pragma pack(push,1)
struct ptSearchRoom {
	char* name;
	int max_user;
	//RoomType type;
	std::ostream& serialize(std::ostream& os) const {
		char null = '\0';
		os.write(name, strlen(name));
		os.write(&null, 1);
		os.write((char*)&max_user, sizeof(max_user));
		//os.write((char*)&type, sizeof(type));
		return os;
	}
	std::istream& deserialize(std::istream& is) {
		if (name != NULL) free(name);
		std::string strTmp = "";
		while (1) {
			char tmp = is.get();
			strTmp.push_back(tmp);
			if (tmp == '\0') {
				break;
			}
		}
		std::vector<char> nameChars(strTmp.begin(), strTmp.end());
		nameChars.push_back('\0');
		name = (char*)malloc(nameChars.size());
		strcpy_s(name, nameChars.size(), &nameChars[0]);

		is.read((char*)&max_user, sizeof(max_user));
		//is.read((char*)&type, sizeof(type));
	}
};
#pragma pack(pop)

#pragma pack(push,1)
struct cs_ptCreateRoom {
	char* name=nullptr;
	int max_user;
	//RoomType type;
	//const char* password;
	std::ostream& serialize(std::ostream& os) const {
		char null = '\0';
		os.write(name, strlen(name));
		os.write(&null, 1);
		os.write((char*)&max_user, sizeof(max_user));
		//os.write((char*)&type, sizeof(type));
		return os;
	}
	std::istream& deserialize(std::istream& is) {
		if (name != nullptr) {
			free(name);
		}
		std::string strTmp = "";
		while (1) {
			char tmp = is.get();
			strTmp.push_back(tmp);
			if (tmp == '\0') {
				break;
			}
		}
		std::vector<char> nameChars(strTmp.begin(), strTmp.end());
		nameChars.push_back('\0');
		name = (char*)malloc(nameChars.size());
		strcpy_s(name, nameChars.size(), &nameChars[0]);
		is.read((char*)&max_user, sizeof(max_user));
		//is.read((char*)&type, sizeof(type));
		return is;
	}
};
#pragma pack(pop)

#pragma pack(push,1)
struct sc_ptCreateRoom {
	unsigned int id;
	std::ostream& serialize(std::ostream& os) const {
		os.write((char*)&id, sizeof(id));
		return os;
	}
	std::istream& deserialize(std::istream& is) {
		is.read((char*)&id, sizeof(id));
		return is;
	}
};
#pragma pack(pop)

#pragma pack(push,1)
struct ptConnectRoom {
	int id;
	//const char* password;
};
#pragma pack(pop)

#pragma pack(push,1)
struct ptUser {
	char* name;
	std::ostream& serialize(std::ostream& os) const {
		char null = '\0';
		os.write(name, strlen(name));
		os.write(&null, 1);
		return os;
	}
	std::istream& deserialize(std::istream& is) {
		if (name != nullptr) {
			free(name);
		}
		std::string strTmp = "";
		while (1) {
			char tmp = is.get();
			strTmp.push_back(tmp);
			if (tmp == '\0') {
				break;
			}
		}
		std::vector<char> nameChars(strTmp.begin(), strTmp.end());
		nameChars.push_back('\0');
		name = (char*)malloc(nameChars.size());
		strcpy_s(name, nameChars.size(), &nameChars[0]);
		return is;
	}
};
#pragma pack(pop)

#pragma pack(push,1)
struct ptUserList {
	ptUser* users;
};
#pragma pack(pop)

#pragma once
#include "Protocol.h"

#pragma pack(push,1)
#pragma pack(pop)

enum gameCode : unsigned short {
	ACCESS_GAME_SERVER=0,
	EXHALE_GAME_SERVER,
	GAME_WORRING,
	GAME_STATE_OK,
	START,
	END,
	READY
};

#pragma pack(push,1)
struct ptSendMsg {
	char* name = nullptr;
	char* msg = nullptr;
	std::ostream& serialize(std::ostream& os) const {
		char null = '\0';
		os.write(name, strlen(name));
		os.write(&null, 1);
		os.write(msg, strlen(msg));
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

		if (msg != nullptr) {
			free(msg);
		}
		std::string msgTmp = "";
		while (1) {
			char tmp = is.get();
			msgTmp.push_back(tmp);
			if (tmp == '\0') {
				break;
			}
		}
		std::vector<char> msgChars(msgTmp.begin(), msgTmp.end());
		msgChars.push_back('\0');
		msg = (char*)malloc(msgChars.size());
		strcpy_s(msg, msgChars.size(), &msgChars[0]);

		return is;
	}
};
#pragma pack(pop)

#pragma pack(push,1)
struct ptEnterUser {
	int name;
};
struct ptOutGoUser {
	int name;
};
#pragma pack(pop)
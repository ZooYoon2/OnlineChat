#pragma once
#include <iostream>
#include <vector>

struct PacketHeader {
	BYTE Code;
	WORD Type;
	WORD PayloadSize;
};//

struct UDP_Packet {
	BYTE Code;
	WORD Type;
	WORD PayloadSize;
	char* Payload;
};

#pragma pack(push,1)
struct ptACCESS_RQ {
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
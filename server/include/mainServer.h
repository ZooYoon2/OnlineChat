#pragma once
#include "SCH.h"
#include "server.h"
#include "Lobby.h"
#include "LobbyProtocol.h"
#include "Protocol.h"

class MainServer : TCP_Server {
	Lobby* lobby;
public:
	MainServer(int portno, const char* ipAddr, int cnt_listen, Lobby* lobby) : TCP_Server(portno, ipAddr, cnt_listen) {
		this->lobby = lobby;
	}
	~MainServer() {
	}

	void TestRoomList() {
		std::unordered_map<unsigned int, GameRoom>* mRooms = lobby->refer_to_rooms();
		mRooms->insert(std::pair<unsigned int, GameRoom>( 1, GameRoom(1, (char*)"test1", new User((char*)"홍길동"), 1, 8) ));
		mRooms->insert(std::pair<unsigned int, GameRoom>( 2, GameRoom(2, (char*)"test2", new User((char*)"testUser"), 1, 8) ));
		mRooms->insert(std::pair<unsigned int, GameRoom>( 3, GameRoom(3, (char*)"test3", new User((char*)"이순신"), 1, 8) ));
		lobby->refer_to_rooms_end();
	}

	virtual void recv_msg(int id) {
		std::unordered_map<unsigned int, User>* mUser = lobby->refer_to_users();
		SOCKET* Sock = &mUser->find(id)->second.mSocket;
		SOCKADDR_IN* Addr = &mUser->find(id)->second.addr;
		lobby->refer_to_users_end();

		int RecvSize;
		struct PacketHeader* ptHeader = (struct PacketHeader*)malloc(sizeof(struct PacketHeader));
		
		while (Sock!=nullptr) {
			RecvSize = recv(*Sock, (char*)ptHeader, sizeof(struct PacketHeader), 0);
			if (RecvSize < 0) {
				printf("recv() Error");
				break;
			}

			printf("MainServer ip = %s port = %d - 요청 : %d\n", inet_ntoa(Addr->sin_addr), Addr->sin_port, ptHeader->Type);
			switch (ptHeader->Type) {
			case channelCode::SELECT_ROOM:{
				send_roomList(Sock);
				break;
				}
			case channelCode::CREATE_ROOM_RQ: {
				create_room(Sock, id, ptHeader->PayloadSize);
				break;
			}
			case channelCode::CONNECT_OK: {
				int c = 1;
				send_mtx.lock();
				send(*Sock, (char*)&c, sizeof(int), 0);
				send_mtx.unlock();
				break;
			}
			default:
				break;
			}
		}

		free(ptHeader);
	}

	void create_room(SOCKET* cSocket, int host_id, int payloadSize) {
		struct PacketHeader ptHeader;
		ptHeader.Code = 1;

		char* data = (char*)malloc(payloadSize);
		int RecvSize = recv(*cSocket, data, payloadSize, 0);
		if (RecvSize < 0) {
			printf("recv() Error");
			return;
		}
		std::stringstream st;
		st.write(data, payloadSize);
		struct cs_ptCreateRoom ptCreateData;
		ptCreateData.deserialize(st);
		free(data);

		if (!lobby->is_full_rooms()) {
			std::unordered_map<unsigned int, User>* mUsers = lobby->refer_to_users();
			User* pHost = &mUsers->find(host_id)->second;
			lobby->refer_to_users_end();
			std::unordered_map<unsigned int, GameRoom>* mRooms = lobby->refer_to_rooms();
			mRooms->insert({ host_id , GameRoom(host_id, ptCreateData.name, pHost, 1, ptCreateData.max_user) });
			mRooms->find(host_id)->second.EnterUser(pHost);
			lobby->refer_to_rooms_end();

			struct sc_ptCreateRoom ptData;
			ptData.id = host_id;
			std::stringstream dataStream;
			ptData.serialize(dataStream);
			std::string strData = dataStream.str();
			std::vector<char> dataChars(strData.begin(), strData.end());
			dataChars.push_back('\0');
			int dataSize = dataChars.size();

			ptHeader.Type = channelCode::CREATE_ROOM_OK;
			ptHeader.PayloadSize = dataSize;

			send_mtx.lock();
			send(*cSocket, (char*)&ptHeader, sizeof(PacketHeader), 0);
			send(*cSocket, &dataChars[0], dataSize, 0);
			send_mtx.unlock();
		}
		else {
			ptHeader.PayloadSize = 0;
			ptHeader.Type = channelCode::CREATE_ROOM_ERROR;

			send_mtx.lock();
			send(*cSocket, (char*)&ptHeader, sizeof(PacketHeader), 0);
			send_mtx.unlock();
		}
		
	}

	void send_roomList(SOCKET* cSocket) {
		struct PacketHeader ptSend;
		ptSend.Code = 1;
		ptSend.Type = channelCode::SELECT_ROOM;

		if (lobby->is_empty_rooms()) {
			ptSend.PayloadSize = 0;
			send_mtx.lock();
			send(*cSocket, (char*)&ptSend, sizeof(PacketHeader), 0);
			send_mtx.unlock();
		}
		else {
			std::unordered_map<unsigned int, GameRoom>* mRooms = lobby->refer_to_rooms();
			ptRoomList roomList;
			roomList.cnt = mRooms->size();
			roomList.rooms = (ptRoom*)malloc(sizeof(ptRoom) * roomList.cnt);
			int i = 0;
			for (std::pair<unsigned int, GameRoom> R : *mRooms) {
				roomList.rooms[i++] = R.second.send_ptRoom();
			}
			lobby->refer_to_rooms_end();

			std::stringstream dataStream;
			roomList.serialize(dataStream);
			free(roomList.rooms);

			std::string strData = dataStream.str();
			std::vector<char> dataChars(strData.begin(), strData.end());
			dataChars.push_back('\0');
			int dataSize = dataChars.size();

			ptSend.PayloadSize = dataSize;

			send_mtx.lock();
			send(*cSocket, (char*)&ptSend, sizeof(PacketHeader), 0);
			send(*cSocket, &dataChars[0], dataSize, 0);
			send_mtx.unlock();
		}
	}
	/*UDP
	* void send_roomList(SOCKADDR_IN client_addr, int client_addrSize) {
		std::vector<char> packetChars;

		ptRoomList roomList;
		roomList.cnt = cnt_channel;
		roomList.rooms = (ptRoom*)malloc(sizeof(ptRoom) * roomList.cnt);
		for (int i = 0; i < cnt_channel; i++) {
			//memcpy_s(roomList.rooms[i],sizeof(rooms),)
			roomList.rooms[i] = rooms[i].send_ptRoom();
		}
		std::stringstream dataStream;
		roomList.serialize(dataStream);
		std::string strData = dataStream.str();
		std::vector<char> dataChars(strData.begin(), strData.end());
		dataChars.push_back('\0');
		int dataSize = dataChars.size();

		struct PacketHeader ptSend;
		ptSend.Code = 1;
		ptSend.Type = channelCode::SELECT_ROOM;
		ptSend.PayloadSize = dataSize;
		char* charToPacketHeader = (char*)&ptSend;
		std::stringstream headerStream;
		packetChars.insert(packetChars.end(), charToPacketHeader, charToPacketHeader + sizeof(struct PacketHeader));
		packetChars.insert(packetChars.end(), dataChars.begin(), dataChars.end());

		for (auto i : packetChars) {
			std::cout << i;
		}
		std::cout << packetChars.size();

		send_mtx.lock();
		sendto(mSocket, &dataChars[0], dataSize, 0, (struct sockaddr*)&client_addr, client_addrSize);
		sendto(mSocket, (char*)&packetChars[0], packetChars.size(), 0, (struct sockaddr*)&client_addr, client_addrSize);

		send_mtx.unlock();

		//sendto(mSocket, (char*)&ptSend, sizeof(struct PacketHeader)+ptSend.PayloadSize, 0, (struct sockaddr*)&client_addr, client_addrSize);



		free(roomList.rooms);
		return;
	}
	*/
	void add_client() {
		while (1) {
			SOCKADDR_IN client_addr;
			int client_addrSize = sizeof(client_addr);
			SOCKET cSocket = accept(mSocket, (LPSOCKADDR)&client_addr, &client_addrSize);
			if (cSocket == INVALID_SOCKET) {
				printf("접속 에러번호 : %d\n", WSAGetLastError());
				continue;
			}
			else {
				int RecvSize;
				struct PacketHeader* ptHeader = (struct PacketHeader*)malloc(sizeof(struct PacketHeader));
				RecvSize = recv(cSocket, (char*)ptHeader,sizeof(struct PacketHeader),0);
				if (RecvSize <= 0) {
					continue;
				}
				char* data = (char*)malloc(ptHeader->PayloadSize);
				RecvSize = recv(cSocket, data, ptHeader->PayloadSize, 0);
				if (RecvSize < 0) {
					continue;
				}

				std::stringstream st;
				st.write(data, ptHeader->PayloadSize);
				struct cs_ptLogin ptData;
				ptData.deserialize(st);
				free(data);
				free(ptHeader);

				struct PacketHeader ptRecv;
				ptRecv.Code = 1;
				ptRecv.PayloadSize = 0;

				if (!lobby->is_full_users()) {
					std::string t(ptData.name);
					t.append(inet_ntoa(client_addr.sin_addr));
					unsigned int  uidx = crc32((char *)t.c_str());
					std::unordered_map<unsigned int, User>* mUsers = lobby->refer_to_users();
					mUsers->insert({ uidx, User(ptData.name, client_addr, cSocket) });
					printf("현재 접속인원수 %d\n", mUsers->size());
					lobby->refer_to_users_end();

					printf("Connection established. ip = %s port = %d \n", inet_ntoa(client_addr.sin_addr), client_addr.sin_port);

					ptRecv.Type = channelCode::LOGIN_OK;
					send(cSocket, (char*)&ptRecv, sizeof(struct PacketHeader), 0);
					
					std::thread th(&MainServer::recv_msg, this, uidx);
					th.detach();
				}
				else {
					printf("클라이언트 초과\n");
					ptRecv.Type = channelCode::LOGIN_FAIL;
					send(cSocket, (char*)&ptRecv, sizeof(struct PacketHeader), 0);
					closesocket(cSocket);
				}
			}
		}
	}
	void run_addClient_thread() {
		std::thread th(&MainServer::add_client, this);
		th.detach();
	}
};
#pragma once
#include "SCH.h"
#include "server.h"
#include "Lobby.h"
#include "GameProtocol.h"

class GameServer : TCP_Server {
	Lobby* lobby;
public:
	GameServer(int portno, const char* ipAddr, int cnt_listen,Lobby *lobby) : TCP_Server(portno, ipAddr, cnt_listen) {
		this->lobby = lobby;
	}
	~GameServer() {
	}

	void recv_msg(int id) {
		std::unordered_map<unsigned int, User>* mUser = lobby->refer_to_users();
		SOCKET* Sock = &mUser->find(id)->second.gSocket;
		SOCKADDR_IN* Addr = &mUser->find(id)->second.addr;
		lobby->refer_to_users_end();

		int RecvSize;
		struct PacketHeader* ptHeader = (struct PacketHeader*)malloc(sizeof(struct PacketHeader));

		while (Sock != nullptr) {
			RecvSize = recv(*Sock, (char*)ptHeader, sizeof(struct PacketHeader), 0);
			if (RecvSize < 0) {
				printf("recv() Error");
				break;
			}

			printf("GameServer ip = %s port = %d - 요청 : %d\n", inet_ntoa(Addr->sin_addr), Addr->sin_port, ptHeader->Type);
			switch (ptHeader->Type) {
			case gameCode::GAME_STATE_OK: {
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
	void send_msg(int id) {
	}

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
				RecvSize = recv(cSocket, (char*)ptHeader, sizeof(struct PacketHeader), 0);
				if (RecvSize <= 0) {
					continue;
				}

				if (ptHeader->Type == gameCode::ACCESS_GAME_SERVER) {
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

					std::string t(ptData.name);
					t.append(inet_ntoa(client_addr.sin_addr));
					unsigned int  uidx = crc32((char*)t.c_str());

					if (lobby->is_find_user(uidx)) {
						ptRecv.Type = gameCode::ACCESS_GAME_SERVER;
						send(cSocket, (char*)&ptRecv, sizeof(struct PacketHeader), 0);

						std::unordered_map<unsigned int, User>* mUsers = lobby->refer_to_users();
						User* pHost = &mUsers->find(uidx)->second;
						pHost->setGameServerSocket(cSocket);
						lobby->refer_to_users_end();

						printf("Connection established. ip = %s port = %d \n", inet_ntoa(client_addr.sin_addr), client_addr.sin_port);
						std::thread th(&GameServer::recv_msg, this, uidx);
						//std::thread th(&GameServer::send_msg, this, uidx);
						th.detach();
					}
					else {
						ptRecv.Type = gameCode::EXHALE_GAME_SERVER;
						send(cSocket, (char*)&ptRecv, sizeof(struct PacketHeader), 0);
						closesocket(cSocket);
					}
				}
			}
		}
	}
	void run_addClient_thread() {
		std::thread th(&GameServer::add_client, this);
		th.detach();
	}
};
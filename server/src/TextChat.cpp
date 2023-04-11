#include "TextChat.h"
#include "channel.h"

user users[MAX_CLNT];
int user_cnt = 0;
std::mutex users_mtx;

std::queue<int> vacancy_idx_q;
int user_idx = 0;
std::mutex vacancy_q_mtx;

SOCKET tSocket;

void TC_server_init() {
	//주소체계, SOCK_STREAM 연결형, SOCK_DGRAM 비연결형
	tSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	//mSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	SOCKADDR_IN serv_addr;
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.S_un.S_addr = inet_addr(IPADDRESS);
	serv_addr.sin_port = htons(PORTNO);


	if (tSocket == INVALID_SOCKET) {
		printf("소켓 에러번호 : %d\n", WSAGetLastError());
		WSACleanup();
	}

	if (bind(tSocket, (LPSOCKADDR)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR) {
		printf("bind 에러번호 : %d\n", WSAGetLastError());
		WSACleanup();
	}

	listen(tSocket, 5);
}

void TC_client_add() {
	//TCP accept
	while (1) {
		SOCKADDR_IN client_addr;
		int client_addrSize = sizeof(client_addr);
		int client_idx = 0;
		SOCKET cSocket;
		cSocket = accept(tSocket, (LPSOCKADDR)&client_addr, &client_addrSize);
		if (cSocket == INVALID_SOCKET) {
			printf("접속 에러번호 : %d\n", WSAGetLastError());
		}
		else {
			printf("현재 접속인원수 %d\n", user_cnt);
			users_mtx.lock();
			if (user_cnt < MAX_CLNT) {
				if (vacancy_q_mtx.try_lock()) {
					if (vacancy_idx_q.empty()) {
						client_idx = user_idx++;

					}
					else {
						client_idx = vacancy_idx_q.front();
						vacancy_idx_q.pop();
					}
				}
				else {
					client_idx = user_idx++;
				}
				users[client_idx].socket = cSocket;
				printf("Connection established. New socket num is %d\n", cSocket);
				user_cnt++;
				vacancy_q_mtx.unlock();
				std::thread th(TC_recv_client, client_idx);
				th.detach();
			}
			else {
				printf("클라이언트 초과\n");
				send(cSocket, "client limit\n", strlen("client limit"), 0);
				closesocket(cSocket);
			}
			users_mtx.unlock();
		}

	}

}

void TC_recv_client(int idx) {
	int RecvSize;
	char* data;
	while (1) {
		if (recv(users[idx].socket, (char*)&RecvSize, sizeof(int), 0) <= 0) {
			printf("%d번째 클라이언트 Socket Num %d 종료\n", idx + 1, users[idx].socket);
			vacancy_q_mtx.lock();
			user_cnt -= 1;
			vacancy_idx_q.push(idx);
			vacancy_q_mtx.unlock();
			printf("현재 접속인원수 %d\n", user_cnt);
			return;
		};
		data = (char*)malloc(RecvSize + 1);
		printf("%d번째 유저 데이터 - ", idx + 1);
		if (recv(users[idx].socket, data, RecvSize, 0) <= 0) {
			printf("%d번째 클라이언트 Socket Num %d 종료\n", idx + 1, users[idx].socket);
			vacancy_q_mtx.lock();
			user_cnt -= 1;
			vacancy_idx_q.push(idx);
			vacancy_q_mtx.unlock();
			printf("현재 접속인원수 %d\n", user_cnt);
			return;
		}
		data[RecvSize] = '\0';

		printf("%s", data);
		free(data);
	}
}
#pragma once
#include "SCH.h"
#include "Protocol.h"

class UDP_Server {
protected:
	SOCKET mSocket;
	SOCKADDR_IN serv_addr;
	int portno;
	const char* ipAddr;
	std::mutex send_mtx;
public:
	UDP_Server(int portno, const char* ipAddr, int cnt_listen) {
		this->portno = portno;
		this->ipAddr = ipAddr;

		//주소체계, SOCK_STREAM 연결형, SOCK_DGRAM 비연결형;
		this->mSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);


		this->serv_addr.sin_family = AF_INET;
		this->serv_addr.sin_addr.S_un.S_addr = inet_addr(ipAddr);
		this->serv_addr.sin_port = htons(portno);


		if (this->mSocket == INVALID_SOCKET) {
			printf("소켓 에러번호 : %d\n", WSAGetLastError());
			WSACleanup();
		}

		if (bind(this->mSocket, (LPSOCKADDR)&this->serv_addr, sizeof(this->serv_addr)) == SOCKET_ERROR) {
			printf("bind 에러번호 : %d\n", WSAGetLastError());
			WSACleanup();
		}

		listen(this->mSocket, cnt_listen);
	}
	virtual void recv_msg() {};
	virtual void run() {};
	virtual void run_recv_thread() {};
};

class TCP_Server {
protected:
	SOCKET mSocket;
	SOCKADDR_IN serv_addr;
	int portno;
	const char* ipAddr;
	std::mutex send_mtx;
public:
	TCP_Server(int portno, const char* ipAddr, int cnt_listen) {
		this->portno = portno;
		this->ipAddr = ipAddr;

		//주소체계, SOCK_STREAM 연결형, SOCK_DGRAM 비연결형;
		this->mSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

		this->serv_addr.sin_family = AF_INET;
		this->serv_addr.sin_addr.S_un.S_addr = inet_addr(ipAddr);
		this->serv_addr.sin_port = htons(portno);


		if (this->mSocket == INVALID_SOCKET) {
			printf("소켓 에러번호 : %d\n", WSAGetLastError());
			WSACleanup();
		}

		if (bind(this->mSocket, (LPSOCKADDR)&this->serv_addr, sizeof(this->serv_addr)) == SOCKET_ERROR) {
			printf("bind 에러번호 : %d\n", WSAGetLastError());
			WSACleanup();
		}

		listen(this->mSocket, cnt_listen);
	}
	virtual void recv_msg() {};
	virtual void run() {};
	virtual void run_recv_thread() {};
};
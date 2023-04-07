#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <WinSock2.h>
#define _WINSOCKAPI_
#pragma comment(lib, "Ws2_32.lib")

#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <thread>
#include <mutex>
#include <queue>

#define PORTNO 3000
#define IPADDRESS "127.0.0.1"
#define BUFFER_SIZE 1024
#define MAX_CLNT 2
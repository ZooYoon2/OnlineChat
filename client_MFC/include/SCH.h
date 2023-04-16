#pragma once
#include <WinSock2.h>
#define _WINSOCKAPI_
#pragma comment(lib, "Ws2_32.lib")

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <thread>
#include <mutex>


#define IPADDRESS "127.0.0.1"

#define MAIN_PORTNO 3000
#define GAME_PORTNO 3001
#define CHAT_PORTNO 3002

#define BUFFER_SIZE 1024
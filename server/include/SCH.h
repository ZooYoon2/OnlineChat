#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <WinSock2.h>
#define _WINSOCKAPI_
#pragma comment(lib, "Ws2_32.lib")

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <thread>
#include <mutex>
#include <queue>

#include "json.hpp"
using json = nlohmann::json;

#define PORTNO 3000
#define IPADDRESS "127.0.0.1"
#define BUFFER_SIZE 1024
#define MAX_CLNT 2
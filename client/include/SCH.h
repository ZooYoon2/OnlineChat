#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <WinSock2.h>
#define _WINSOCKAPI_
#pragma comment(lib, "Ws2_32.lib")

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <thread>
#include "json.hpp"

using json = nlohmann::json;

#define PORTNO 3000
#define IPADDRESS "127.0.0.1"
#define BUFFER_SIZE 1024

void server_connet();
void server_close();

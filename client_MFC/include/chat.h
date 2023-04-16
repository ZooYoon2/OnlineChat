#pragma once
#include "pch.h"
#include "SCH.h"
#include "ChatProtocol.h"
#include <sstream>

void testChat_init();
char* getString();
void recv_server();
void send_msg();
void view();

void check_chat_server_state(CStatic* t_state);
int chat_server_init();
int chat_server_connet();
int chat_server_access(char* name);
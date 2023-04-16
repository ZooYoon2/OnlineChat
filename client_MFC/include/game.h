#pragma once
#include "pch.h"
#include "SCH.h"
#include "GameProtocol.h"
#include <sstream>

void check_game_server_state(CStatic* t_state);
int game_server_init();
int game_server_connet();
int game_server_access(char* name);

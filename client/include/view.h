#pragma once
#include "SCH.h"
#include <conio.h>

enum keyCode {
	UP = 0,
	DOWN=1,
	LEFT=2,
	RIGHT=3,
	ENTER=4,
	RESET=5
};

void setup();
void title_to_servInfo(int b);
void logo();
void menu();
void list_channel();
void join_channel(int chID, int chName);
void selectCursor(int bx, int by, int ax, int ay);
int kCntl();
void mCursor(int x,int y);
#pragma once
#include "SCH.h"
#include <conio.h>

enum keyCode {
	UP = 0,
	DOWN=1,
	LEFT=2,
	RIGHT=3,
	ENTER=4
};

void setup();
void logo();
void menu();
void join_channel();
void selectCursor(int bx, int by, int ax, int ay);
int kCntl();
void mCursor(int x,int y);
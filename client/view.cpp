#include "view.h"

void setup() {
	system("mode con cols=80 lines=50 | title 챗챗챗");
}
void logo() {
	printf("################################################################################\n");
	printf("#######                                                                  #######\n");
	printf("#######        ########   ###     ###        ###        ##############   #######\n");
	printf("#######      ##########   ###     ###      ### ###      ##############   #######\n");
	printf("#######    ###            ###     ###     ###   ###          ####        #######\n");
	printf("#######   ###             ###     ###    ###     ###         ####        #######\n");
	printf("#######   ###             ###########   #############        ####        #######\n");
	printf("#######   ###             ###########   #############        ####        #######\n");
	printf("#######   ###             ###     ###   ####     ####        ####        #######\n");
	printf("#######    ###            ###     ###   ####     ####        ####        #######\n");
	printf("#######      ##########   ###     ###   ####     ####        ####        #######\n");
	printf("#######        ########   ###     ###   ####     ####        ####        #######\n");
	printf("#######                                                                  #######\n");
	printf("################################################################################\n");
}
void menu() {
	mCursor(35, 15);
	printf("채널 접속\n");
	mCursor(35, 16);
	printf("채널 생성\n");
	mCursor(35, 17);
	printf("채널 참여\n");
	
	int BCurX = 33;
	int BCurY = 15;
	int ACurX = 33;
	int ACurY = 15;
	selectCursor(BCurX, BCurY, ACurX, ACurY);
	while (1) {
		mCursor(79, 17);
		int key = kCntl();
		if (key == UP) {
			if (ACurY > 15) {
				BCurY = ACurY;
				ACurY = ACurY - 1;
			}
		}
		else if (key == DOWN) {
			if (ACurY < 17) {
				BCurY = ACurY;
				ACurY = ACurY + 1;
			}
		}
		else if (key == RIGHT) {
			if (ACurY == 15) {
				join_channel();
			}
			
			mCursor(35, 15);
			printf("채널 접속\n");
			mCursor(35, 16);
			printf("채널 생성\n");
			mCursor(35, 17);
			printf("채널 참여\n");
		}
		selectCursor(BCurX, BCurY, ACurX, ACurY);
	}
}
void join_channel() {
	system("cls");
	logo();

	mCursor(35, 15);
	printf("1.채널명 : \n");
	int BCurX = 33;
	int BCurY = 15;
	int ACurX = 33;
	int ACurY = 15;
	selectCursor(BCurX, BCurY, ACurX, ACurY);
	while (1) {
		mCursor(79, 17);
		int key = kCntl();
		selectCursor(BCurX, BCurY, ACurX, ACurY);
	}
}
void selectCursor(int bx,int by,int ax,int ay) {
	mCursor(bx,by);
	printf(" ");
	mCursor(ax, ay);
	printf(">");
}
int kCntl() {
	if (_getch()) {
		int key = _getch();
		switch (key) {
		case 72: return UP;
		case 80: return DOWN;
		case 75: return LEFT;
		case 77: return RIGHT;
		default: return -1;
		}
	}
}
void mCursor(int x, int y){
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}
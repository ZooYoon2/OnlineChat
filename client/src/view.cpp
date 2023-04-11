#include "view.h"
#include "channel.h"

void setup() {
	system("mode con cols=80 lines=50 | title ÃªÃªÃª");
}
void title_to_servInfo(int b) {
	if (b == 1) {
		system("title ÃªÃªÃª - Á¢¼ÓÁß");
	}
	else{
			system("title ÃªÃªÃª - Á¢¼Ó²÷±è");
	}
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
	printf("Ã¤³Î Á¢¼Ó\n");
	mCursor(35, 16);
	printf("Ã¤³Î »ý¼º\n");
	mCursor(35, 17);
	printf("Ã¤³Î Âü¿©\n");
	
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
				list_channel();
			}
			mCursor(35, 15);
			printf("Ã¤³Î Á¢¼Ó\n");
			mCursor(35, 16);
			printf("Ã¤³Î »ý¼º\n");
			mCursor(35, 17);
			printf("Ã¤³Î Âü¿©\n");
		}
		selectCursor(BCurX, BCurY, ACurX, ACurY);
	}
}
void list_channel() {
	system("cls");
	logo();

	mCursor(35, 15);
	printf("1.Ã¤³Î¸í : \n");
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
				printf("U");
			}
		}
		else if (key == DOWN) {
			if (ACurY < 17) {
				BCurY = ACurY;
				ACurY = ACurY + 1;
				printf("D");
			}
		}
		else if (key == RIGHT) {
			if (ACurY == 15) {
				list_channel();
				printf("N");
			}
			mCursor(35, 15);
			printf("Ã¤³Î Á¢¼Ó\n");
			mCursor(35, 16);
			printf("Ã¤³Î »ý¼º\n");
			mCursor(35, 17);
			printf("Ã¤³Î Âü¿©\n");
		}
		else if (key == RESET) {
			mCursor(79, 17);
			recv_channel_list();
			printf("R");
		}

		selectCursor(BCurX, BCurY, ACurX, ACurY);
	}
}
void join_channel(int chID, int chName) {
	system("cls");
	logo();

	mCursor(35, 15);
	printf("1.Ã¤³Î¸í : \n");
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
	int key;
	if (key = _getch()) {
		if (key == 224) {
			key = _getch();
			switch (key) {
			case 72: return UP;
			case 80: return DOWN;
			case 75: return LEFT;
			case 77: return RIGHT;
			default: return -1;
			}
		}
		else {
			switch (key) {
			case 114:
			case 82:
				return RESET;
			}
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
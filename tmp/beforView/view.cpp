#include "view.h"
#include "channel.h"

using namespace std;
int BCurX = 0;
int BCurY = 0;
int ACurX = 0;
int ACurY = 0;

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
	while (1) {
		system("cls");
		logo();

		mCursor(35, 15);
		printf("Ã¤³Î Á¢¼Ó\n");
		mCursor(35, 16);
		printf("Ã¤³Î »ý¼º\n");
		mCursor(35, 17);
		printf("Ã¤³Î Âü¿©\n");

		BCurX = 33;
		BCurY = 15;
		ACurX = 33;
		ACurY = 15;
		selectCursor(BCurX, BCurY, ACurX, ACurY);

		while (1) {
			mCursor(79, 14);
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
					break;
				}
				if (ACurY == 16) {
					create_channel();
					break;
				}
			}
			selectCursor(BCurX, BCurY, ACurX, ACurY);
		}
	}
}

void list_channel() {
	while (1) {
		system("cls");
		logo();

		mCursor(19, 15);
		int noColWidth = 2;
		int nameColWidth = 20;
		int hostColWidth = 20;
		//table header 
		cout << setfill(' ') << fixed;
		cout << setw(noColWidth) << "No" << setw(nameColWidth) << "Name" << setw(hostColWidth) << "Host Name";

		mCursor(19, 16);
		cout << setfill('-') << setw(noColWidth + nameColWidth + nameColWidth) << '-';
		cout << setfill(' ') << fixed;

		int cnt_channel = 0;

		BCurX = ACurX;
		BCurY = ACurY;
		ACurX = 18;
		ACurY = 17;
		selectCursor(BCurX, BCurY, ACurX, ACurY);
		BCurX = ACurX;
		BCurY = ACurY;

		mCursor(79, 17);
		ptRoomList data = recv_channel_list();
		if (data.cnt==0) {
			mCursor(34, 17);
			printf("¹æÀÌ ¾ø½À´Ï´Ù.\n");
		}
		else {
			// create table of data 
			for (int i = 0; i < data.cnt;i++) {
				mCursor(19, 17 + i);
				cout << setprecision(0) << setw(noColWidth) << data.rooms[i].id + 1 << setprecision(4)
					<< setw(nameColWidth) << data.rooms[i].name
					<< setw(hostColWidth) << data.rooms[i].host_name;
			}
			cnt_channel = data.cnt;
		}

		while (1) {
			mCursor(79, 14);
			int key = kCntl();
			if (key == UP) {
				if (ACurY > 17) {
					BCurY = ACurY;
					ACurY = ACurY - 1;
				}
			}
			else if (key == DOWN) {
				if (ACurY < 17 + (cnt_channel - 1)) {
					BCurY = ACurY;
					ACurY = ACurY + 1;
				}
			}
			else if (key == LEFT) {
				return;
			}
			else if (key == 114 || key==82) {
				break;
			}
			selectCursor(BCurX, BCurY, ACurX, ACurY);
		}
	}
}

void create_channel() {
	fflush(stdin);
	system("cls");
	logo();

	int cnt;
	char title[41];

	mCursor(36, 15);
	cout << "-Ã¤³Î»ý¼º-";
	mCursor(25, 16);
	cout << setfill('-') << setw(30) << '-';
	while (1) {
		mCursor(25, 17);
		printf("Ã¤³Î Á¦¸ñ : ");
		scanf_s("%[^\n]s", title, sizeof(title));
		if (strcmp(title, "!q") == 0) {
			break;
		}
		fflush(stdin);
		mCursor(25, 18);
		printf("ÃÖ´ë ÀÎ¿ø ¼ö(ÃÖ´ë8¸í) : ");
		std::cin >> cnt;
		if ((cnt > 1) && (cnt <= 8)) {
			fflush(stdin);
			break;
		}
		fflush(stdin);
	}
	send_create_room(title,cnt);
	return;
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
			printf("%d", key);
			switch (key) {
			case 72: return UP;
			case 80: return DOWN;
			case 75: return LEFT;
			case 77: return RIGHT;
			default: return -1;
			}
		}
		else {
			if (key == 8) return BACKSPACE;
			return key;
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
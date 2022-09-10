#include "myTetris.h"
#include "stdafx.h"
#include "Windows.h"
#include <conio.h>
#define _CRT_SECURE_NO_WARNINGS

unsigned char playground[MY_HIGH][MY_WIDTH] = { 0 };
unsigned char oldplayground[MY_HIGH][MY_WIDTH] = { 0 };
unsigned char baseground[MY_HIGH][MY_WIDTH] = { 0 };
unsigned char nextblock[4][4] = { 0 };

int block_type, block_dir;
int block_row, block_column;

int next_block_type, next_block_dir;
int score,level=1;
int best_score = 0;

extern Point blockPattern[MY_PATTERN_NUM][4][4];
extern int t;
#define _TEST


int main() {

	int i,key, row, column, dir;

	FILE *file;

	CONSOLE_CURSOR_INFO CurInfo;
	CurInfo.dwSize = 1;
	CurInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);

	system("mode con: cols=80 lines=30");

	init();

	fopen_s(&file, "scoreFile.txt", "r");

	if (file == NULL)
		best_score = 0;
	else {
		fscanf_s(file, "%d", &best_score);
		fclose(file);
	}

	display(1);

	while (1) {

		key = NULL;
		if (delayFunction(t)) {
			key = MY_KEY_DOWN; // ����߷��� �̰���
		}
		else key = getKey();

		if (key == 'q') break;
		if (key == 'p') {
			_getch();
			_getch();
		}


		if (key != NULL) {
			getMove(key, &row, &column, &dir);

			if (checkMove(row, column, dir)) {
				moveBlock(row, column, dir, key);
				display(1); // ������ ���� �ٽ� ���������ϱ� �ٽ� �ؾ��ϴ°�
				display(1);
			}

			else if (key == MY_KEY_DOWN) {
				copyBlock();// base�� ī��!
				removeLines(); //removeLines ���� ȣ��.
				if (block_type == MY_BLOCK_BOMB)
					BombRemove(&column);
				newBlock();
				if (Finishcheck() == 0) {
					gotoxy(33, 7);
					printf(" �ٽ��ҷ���? �Ҳ��� r�� ������ ");
					key = _getch();
					if (key == 'r') {
						regame();
					}
					else{

						if (score > best_score) {
							fopen_s(&file, "scoreFile.txt", "w");

							if (file == NULL)
								printf("������ �����ϴ�.");
							else {
								fprintf_s(file, "%d", score);
								fclose(file);
							}
						}
						break;
					}
				}

			}
		}
		display(1);

	




		//2�ð� 30�и��� ����...

	}



	//Ŀ�� ���߱�, �ܼ� â

	return 0;
}

#include "myTetris.h"
#include "stdafx.h"
#include <stdlib.h>
#include <Windows.h>

extern unsigned char playground[MY_HIGH][MY_WIDTH];
extern unsigned char oldplayground[MY_HIGH][MY_WIDTH];
extern unsigned char baseground[MY_HIGH][MY_WIDTH];
extern unsigned char nextblock[4][4];

extern int block_type;
extern int block_dir;

extern int block_row;
extern int block_column;

extern int next_block_type, next_block_dir;
extern int score, level;
extern Point blockPattern[MY_PATTERN_NUM][4][4];

// flag=1, block 추가
// flag=0, remove line => 블럭 추가 없음 (라인 지우는거)

void display(int flag) {
	int i, k, y, x,a,b;

	// baseground를 playground에 전체 복사! [for 문 이용]
	for (i = 0; i < MY_HIGH; i++) {
		for (k = 0; k < MY_WIDTH; k++) {
			playground[i][k] = baseground[i][k]; // 여기만 play 에서 old로 바꾸면 뜨긴 뜸
		}											// 근데 벽이 안뜸
	}


	// 블럭 위치를 계산하여 playground에 추가함
	if (flag == 1) {
		Shadow();
		for (i = 0; i < 4; i++) {
			
			y = block_row + blockPattern[block_type][block_dir][i].row;
			x = block_column + blockPattern[block_type][block_dir][i].column;
		
			playground[y][x] = block_type;
			
		}
	}




	//playground를 게임창에 출력
	for (i = 0; i < MY_HIGH; i++) {
		for (k = 0; k < MY_WIDTH; k++) {
			
			// playground와 oldplayground를 비교해서 값이 다른 부분만 출력.
			if (playground[i][k] != oldplayground[i][k]) {
				gotoxy(k * 2, i);
				switch (playground[i][k]) {
				case MY_SPACE:
					printf("  ");
					break;
				case MY_WALL:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					printf("▦");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // 물들어있으니까 
					break;														  //다시 바꿔주는거
				case MY_SHADOW_BLOCK:
					printf("□");
					break;
				case MY_BLOCK_BOMB:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 24);
					printf("■");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					break;
				case MY_BLOCK_1:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
					printf("■");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					break;
				case MY_BLOCK_2:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
					printf("■");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					break;
				case MY_BLOCK_3:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					printf("■");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					break;
				case MY_BLOCK_4:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					printf("■");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					break;
				case MY_BLOCK_5:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
					printf("■");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					break;
				default:
					break;
				}
			}
		}
	}
	// 여기부터 NEXT BLOCK 만들기 시작!

	a = 32, b = 2;
	gotoxy(32, 1), printf("┏   NEXT  BLOCK  ┓");
	for (b = 2; b < 7; b++) {
		gotoxy(a, b), printf("┃                ┃");
	}
	gotoxy(32, b), printf("┗━━━━━━━━━━━━━━━━┛");

	gotoxy(37, 3);
	int A = 3;
	if (flag == 1) {
		for (i = 0; i < 4; i++) {
			y = blockPattern[next_block_type][next_block_dir][i].row;
			x = blockPattern[next_block_type][next_block_dir][i].column;
			nextblock[y][x] = next_block_type;
		}
	}

	for (i = 0; i < 4; i++) {
		for (k = 0; k < 4; k++) {
			switch (nextblock[i][k]) {
			case MY_SPACE:
				printf("  ");
				break;
			case MY_BLOCK_BOMB:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 24);
				printf("■");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				break;
			case MY_BLOCK_1:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				printf("■");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				break;
			case MY_BLOCK_2:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
				printf("■");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				break;
			case MY_BLOCK_3:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				printf("■");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				break;
			case MY_BLOCK_4:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				printf("■");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				break;
			case MY_BLOCK_5:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
				printf("■");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				break;
			default:
				break;
			}
		}
		printf("\n");
		A++;
		gotoxy(37 , A);
	}

	for (i = 0; i < 4; i++) {
		for (k = 0; k < 4; k++) {
			nextblock[i][k] = MY_SPACE;
		}
	}

	// playground를 oldplayground 에 다시 복사
	for (i = 0; i < MY_HIGH; i++) {
		for (k = 0; k < MY_WIDTH; k++) {
			oldplayground[i][k] = playground[i][k];
		}
	}
}




#ifndef _MY_TETRIS_H
#define _MY_TETRIS_H


#define MY_PATTERN_NUM	6	
#define MY_HIGH			28
#define MY_WIDTH		15

#define MY_SPACE		0x0F
#define MY_WALL			0xF0
#define MY_BLOCK_1		0
#define MY_BLOCK_2		1
#define MY_BLOCK_3		2		// 나중에 색깔 바꿀 때 쓰려고
#define MY_BLOCK_4		3
#define MY_BLOCK_5		4
#define MY_BLOCK_BOMB   5
#define MY_SHADOW_BLOCK 7
#define MY_BASE_BLOCK	9

#define MY_KEY_UP		72
#define MY_KEY_DOWN		80
#define MY_KEY_RIGHT	77
#define MY_KEY_LEFT		75
#define MY_KEY_SPACE	32


#define CANNOT_MOVE		0
#define CAN_MOVE		1
#define MY_GAME_GO		1
#define MY_GAME_STOP	0



typedef struct _Point {
	int row;			// 행
	int column;			// 열
}Point;

void init();
void gotoxy(int, int);
unsigned char getKey();
void display(int);
int checkMove(int, int, int);
void getMove(int, int *, int *, int *);
void moveBlock(int, int, int,int);
void newBlock();
int delayFunction(unsigned int ); 
void copyBlock();
void removeLines();
int removeLine(int );
int Finishcheck();
void Shadow();
void regame();
void BombRemove(int *);
#endif
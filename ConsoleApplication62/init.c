#include "myTetris.h"
#include "stdafx.h"
#include <stdlib.h>


extern unsigned char playground[MY_HIGH][MY_WIDTH];
extern unsigned char oldplayground[MY_HIGH][MY_WIDTH];
extern unsigned char baseground[MY_HIGH][MY_WIDTH];

extern int block_type;
extern int block_dir;

extern int block_row;
extern int block_column;

extern int next_block_type, next_block_dir;
extern int score, level;
extern Point blockPattern[MY_PATTERN_NUM][4][4];

void init() {
	int i, j;
	int x, y;

	// 1. baseground를 초기화한다.
	// 2. baseground에 테두리를 설정한다.
	// 3. block 을 생성한다 (block_type, block_dir 설정)
	// 4. block의 기본 위치를 설정한다.
	// 5. oldplayground를 0xFF 로 초기화한다.

	for (i = 0; i < MY_HIGH; i++) {
		for (j = 0; j < MY_WIDTH; j++) {
			baseground[i][j] = MY_SPACE;
		}
	}
	// [2. 테두리 설정]
	for (i = 0; i < MY_WIDTH-1; i++)
		baseground[0][i] = MY_WALL;
	for (i = 0; i < MY_WIDTH; i++)
		baseground[MY_HIGH - 1][i] = MY_WALL;
	for (i = 0; i < MY_HIGH; i++)
		baseground[i][0] = MY_WALL;
	for (i = 0; i < MY_HIGH; i++)
		baseground[i][MY_WIDTH -1] = MY_WALL;
	

	// 블럭을 인쇄할 위치값 초기화 [3. block 생성]
	next_block_type = rand() % MY_PATTERN_NUM;
	next_block_dir = rand() % 4; 

	
	// [4. block 기본 위치 설정] 
	block_row = 1; // 이거는 2부터 내려오겠다는 말임~!!
	block_column = (rand() % (MY_WIDTH - 5)) + 1; // 이건 사실 아무데나 설정해도 괜춘

	// [5. oldplayground 초기화]
	for (i = 0; i < MY_HIGH; i++) {
		for (j = 0; j < MY_WIDTH; j++) {
			oldplayground[i][j] = MY_SPACE;
		}
	}
}


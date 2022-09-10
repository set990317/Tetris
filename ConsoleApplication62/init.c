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

	// 1. baseground�� �ʱ�ȭ�Ѵ�.
	// 2. baseground�� �׵θ��� �����Ѵ�.
	// 3. block �� �����Ѵ� (block_type, block_dir ����)
	// 4. block�� �⺻ ��ġ�� �����Ѵ�.
	// 5. oldplayground�� 0xFF �� �ʱ�ȭ�Ѵ�.

	for (i = 0; i < MY_HIGH; i++) {
		for (j = 0; j < MY_WIDTH; j++) {
			baseground[i][j] = MY_SPACE;
		}
	}
	// [2. �׵θ� ����]
	for (i = 0; i < MY_WIDTH-1; i++)
		baseground[0][i] = MY_WALL;
	for (i = 0; i < MY_WIDTH; i++)
		baseground[MY_HIGH - 1][i] = MY_WALL;
	for (i = 0; i < MY_HIGH; i++)
		baseground[i][0] = MY_WALL;
	for (i = 0; i < MY_HIGH; i++)
		baseground[i][MY_WIDTH -1] = MY_WALL;
	

	// ���� �μ��� ��ġ�� �ʱ�ȭ [3. block ����]
	next_block_type = rand() % MY_PATTERN_NUM;
	next_block_dir = rand() % 4; 

	
	// [4. block �⺻ ��ġ ����] 
	block_row = 1; // �̰Ŵ� 2���� �������ڴٴ� ����~!!
	block_column = (rand() % (MY_WIDTH - 5)) + 1; // �̰� ��� �ƹ����� �����ص� ����

	// [5. oldplayground �ʱ�ȭ]
	for (i = 0; i < MY_HIGH; i++) {
		for (j = 0; j < MY_WIDTH; j++) {
			oldplayground[i][j] = MY_SPACE;
		}
	}
}


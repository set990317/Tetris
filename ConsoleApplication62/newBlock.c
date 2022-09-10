#include "myTetris.h"
#include "stdafx.h"
#include <stdlib.h>
#include <time.h>

extern int block_type;
extern int block_dir;

extern int block_row;
extern int block_column;

extern int next_block_type, next_block_dir;
extern Point blockPattern[MY_PATTERN_NUM][4][4];

void newBlock() {

	srand(time(NULL));

	block_type = next_block_type;
	block_dir = next_block_dir;
	block_row = 2;
	block_column = (rand()%(MY_WIDTH-5)+1);

	next_block_type = rand() % MY_PATTERN_NUM;
	next_block_dir = rand() % 4;

}
/* ������ ���� => ����ִ� column �� ������ �ѱ��
�� ���� �����= ���� �ִ� �� ������ ����߸��� = ����� = ����ī�� ���פѤ��R
removeline / removelines �� �и��ع����� �� �����غ���.*/
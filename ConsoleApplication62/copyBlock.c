#include "myTetris.h"

extern unsigned char baseground[MY_HIGH][MY_WIDTH];
extern Point blockPattern[MY_PATTERN_NUM][4][4];

extern int block_type;
extern int block_dir;

extern int block_row;
extern int block_column;

void copyBlock() {
	int i, x, y;
	for (i = 0; i < 4; i++) {

		y = block_row + blockPattern[block_type][block_dir][i].row;
		x = block_column + blockPattern[block_type][block_dir][i].column;

		baseground[y][x] = MY_BASE_BLOCK;

	}
}
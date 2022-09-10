#include "myTetris.h"

extern int block_type;
extern unsigned char baseground[MY_HIGH][MY_WIDTH];
extern Point blockPattern[MY_PATTERN_NUM][4][4];


int checkMove(int row, int column, int direction) {
	int i, x, y;

	for (i = 0; i < 4; i++) {

		y = row + blockPattern[block_type][direction][i].row;
		x = column + blockPattern[block_type][direction][i].column;

		if (baseground[y][x] != MY_SPACE ) return CANNOT_MOVE;

	}
	return CAN_MOVE;
}
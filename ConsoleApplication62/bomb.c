#include "myTetris.h"

extern int block_row;
extern int block_column;
extern int block_type;
extern int block_dir;

extern unsigned char baseground[MY_HIGH][MY_WIDTH];

extern int next_block_type, next_block_dir;

void BombRemove(int *column) {
	int i;
	for (i = MY_HIGH - 2; i > 1; i--) {
		baseground[i][*column] = MY_SPACE;
	}
}
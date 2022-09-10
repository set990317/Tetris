#include "myTetris.h"

extern int block_dir;
extern int block_row;
extern int block_column;

void moveBlock(int row, int column, int dir, int key) {

	block_row = row;
	block_column = column;
	block_dir = dir;

	if (key == MY_KEY_SPACE) {
		while (1)
		{
			if (!checkMove(block_row, block_column, block_dir))
			{
				block_row--;
				break;
			}
			block_row++;
		}
	}



}
#include "stdafx.h"
#include "myTetris.h"


extern unsigned char playground[MY_HIGH][MY_WIDTH];
extern Point blockPattern2[MY_PATTERN_NUM][4][4];

extern int block_type;
extern int block_dir;
extern int block_row;
extern int block_column;




void Shadow() {
	int i,x,y;
	int row, block_row2;
	block_row2 = block_row;
		
	while (checkMove(block_row, block_column, block_dir))
		{
			block_row++;
			row = block_row;
		}
		row = block_row--;
		block_row = block_row2;
		

		for (i = 0; i < 4; i++) {

			y = row + blockPattern2[block_type][block_dir][i].row;
			x = block_column + blockPattern2[block_type][block_dir][i].column;

			playground[y-1][x] = MY_SHADOW_BLOCK;
		}	

}


#include "myTetris.h"

extern unsigned char baseground[MY_HIGH][MY_WIDTH];

extern int block_type;
extern int block_dir;

extern int block_row;
extern int block_column;

int removeLine(int line) {

	// 맨 밑에 line 검사 == for 문 돌리기
	// line 건들때는 base로 할거임 걔는 움직이지 않는 아이니까!!

	int i,k;
	
	for (k = 1; k < MY_WIDTH - 1; k++) {
		if (baseground[line][k] == MY_SPACE) return 0;
	}
	for (i = line;i>1; i--) {
		for (k = 1; k < MY_WIDTH - 1; k++) {
			baseground[i][k] = baseground[i-1][k];
		}
	}

	return 1;
}
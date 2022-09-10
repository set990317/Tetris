#include "stdafx.h"
#include "myTetris.h"

extern int block_type;
extern int block_dir;

extern int block_row;
extern int block_column;
// 체크무브를 돌려보면서 알 수 있는거. 체크무브 경우 4개.아래/ 좌 / 우/ 방향 한칸 움직일 수 있으면. (if-else if)
// 다 되면 return MY_GAME_GO; 하고 맨 나중에는 return MY_GAME_STOP; 으로 끝

int Finishcheck() {

	// 새로운 블럭이 생성될 수 없으면 종료!

	if (!checkMove(block_row, block_column, block_dir)) {
		return MY_GAME_STOP;
	}
	// 새로운 블럭이 움직일 수 없으면 종료!
	if (checkMove(block_row + 1, block_column, block_dir)) {
		return MY_GAME_GO;
	}
	else if (checkMove(block_row, block_column + 1, block_dir)) {
		return MY_GAME_GO;
	}
	else if (checkMove(block_row, block_column - 1, block_dir)) {
		return MY_GAME_GO;
	}
	else if (checkMove(block_row, block_column, (block_dir + 1) % 4)) {
		return MY_GAME_GO;
	}
	return MY_GAME_STOP;
}
		

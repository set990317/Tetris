#include "stdafx.h"
#include "myTetris.h"

extern int block_type;
extern int block_dir;

extern int block_row;
extern int block_column;
// üũ���긦 �������鼭 �� �� �ִ°�. üũ���� ��� 4��.�Ʒ�/ �� / ��/ ���� ��ĭ ������ �� ������. (if-else if)
// �� �Ǹ� return MY_GAME_GO; �ϰ� �� ���߿��� return MY_GAME_STOP; ���� ��

int Finishcheck() {

	// ���ο� ���� ������ �� ������ ����!

	if (!checkMove(block_row, block_column, block_dir)) {
		return MY_GAME_STOP;
	}
	// ���ο� ���� ������ �� ������ ����!
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
		

//���ӽð��� ������ ���� �Űܵ� �������� �� �Ű��� (������ �̿�)
// switch �� �Ἥ key ���Ԥ��µǾ��� ���� ����
// dir+1�ϸ� 90�� ó�� ����.
// �̵��� ��ǥ ����Ͽ� �� ��� ���� ��ȯ
// �� key�� ���� ��쿡�� ���� ��ǥ������ ��ȯ
#include "myTetris.h"
extern int block_type, block_dir;
extern int block_row, block_column;

void getMove(int key, int *row, int *column, int *dir) {

	*row = block_row;
	*column = block_column;
	*dir = block_dir;

	switch (key) {
	case MY_KEY_UP:
		*dir = (block_dir + 1) % 4;
		break;
	case MY_KEY_LEFT :
		*column = block_column - 1;
		break;
	case MY_KEY_DOWN :
		*row = block_row + 1;
		break;
	case MY_KEY_RIGHT :
		*column = block_column + 1;
		break;
	default :
		break;
	}
}

// ���蹮��
// ���� ����� ���� �ϳ�
// ��~û ���� ���� �ϳ�
// ��� ���� �ϳ� �̷��� �ؼ� �� 3����!!!!!!!!!!!!!
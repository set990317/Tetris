#include "myTetris.h"

extern unsigned char baseground[MY_HIGH][MY_WIDTH];

extern int block_type;
extern int block_dir;

extern int block_row;
extern int block_column;

int removeLine(int line) {

	// �� �ؿ� line �˻� == for �� ������
	// line �ǵ鶧�� base�� �Ұ��� �´� �������� �ʴ� ���̴ϱ�!!

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
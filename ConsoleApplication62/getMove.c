//ㅣ임시값을 결정한 다음 옮겨도 괜찮으면 블럭 옮겨줌 (포인터 이용)
// switch 문 써서 key 뭐입ㅂ력되었을 때를 써줌
// dir+1하면 90도 처럼 보임.
// 이동할 좌표 계산하여 그 결과 값을 반환
// 단 key가 널인 경우에는 현재 좌표값으로 반환
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

// 시험문제
// 파일 입출력 문제 하나
// 엄~청 쉬운 문제 하나
// 기능 문제 하나 이렇게 해서 총 3문제!!!!!!!!!!!!!
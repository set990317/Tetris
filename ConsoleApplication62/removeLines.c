//main ���� ȣ���ϴ� �� ����.
//removeLine�� i �����鼭 ȣ��.
#include "myTetris.h"
#include "stdafx.h"

extern int score, level, best_score;
int t = 500;

void removeLines() {
	int i,a,b;

	
	for (i = MY_HIGH - 2; i > 0; i--) {
		if (removeLine(i)) {
			display(0);		// 0 ������ �ֳĸ� 1 ������ ���� �� ����.. �� 1������ newblock �����ϰ� �صױ� ����
	//		delayFunction(t);
			i++; 
			score = score + 50;
		}
	}

	a = 30;
	b = 26;

	if (score >= 150) {
		level = 2;
		t = 300;
		if (score >= 400) {
			level = 3;
			t = 200;
			if (score >= 700) {
				level = 4;
				t = 100;
			}
		}
	}

	gotoxy(a, b);
	printf(" level : %d ", level);
	gotoxy(a, b + 1);
	printf(" score : %d ", score);
	gotoxy(a, b + 2);
	printf(" best score : %d ", best_score);
}
// ������ ������ �ٽ� ���� �ϴ� ����!!
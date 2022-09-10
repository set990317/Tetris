//main 에서 호출하는 건 얘임.
//removeLine에 i 넣으면서 호출.
#include "myTetris.h"
#include "stdafx.h"

extern int score, level, best_score;
int t = 500;

void removeLines() {
	int i,a,b;

	
	for (i = MY_HIGH - 2; i > 0; i--) {
		if (removeLine(i)) {
			display(0);		// 0 넣은건 왜냐면 1 넣으면 쟤가 그 뭐야.. 그 1넣으면 newblock 생성하게 해뒀기 때문
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
// 지워진 라인을 다시 보게 하는 거임!!
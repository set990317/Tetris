#include "stdafx.h"
#include <Windows.h>
#include "myTetris.h"

extern int best_score;
extern int score, level;

void regame() {
	FILE *file;
	if (score > best_score) {
		fopen_s(&file, "scoreFile.txt", "w"); // file=fopen("scoreFile.txt","w") 이랑 또같ㅇㅁ!!!!!!똑같음!

		if (file == NULL)
			printf("파일이 없습니다.");
		else {
			fprintf_s(file, "%d", score);
			fclose(file);
		}
	}
	system("cls");
	init();
	display(1);
	level = 1, score = 0;
	fopen_s(&file, "scoreFile.txt", "r");

	if (file == NULL)
		best_score = 0;
	else {
		fscanf_s(file, "%d", &best_score);
		fclose(file);
	}
}
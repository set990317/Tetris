// t는 기준 시간. t값이 작을수록 빨리 떨어짐.
#include <Windows.h>
#include "myTetris.h"

int delayFunction(unsigned int t) {

	double newTime;
	static double oldTime = 0;

	//newTime = GetTickCount();

	newTime = GetTickCount64();
	
	if ((newTime - oldTime) > t) {
		oldTime = newTime;
		return CAN_MOVE;
	}
	else {
		return CANNOT_MOVE;
	}
}
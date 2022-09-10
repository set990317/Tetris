#include "stdafx.h"
#include <conio.h>


unsigned char getKey() {

	unsigned char key = NULL;

	if (_kbhit()) {
		key = _getch();
		if (key == 224){
			key = _getch();
		}
	}

	return key;
}
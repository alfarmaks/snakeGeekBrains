// Snake.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "HorizontalLine.h"
#include "VerticalLine.h"
#include "Snake.h"
#include <conio.h>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT rect = { 0, 0, 25, 15 };
	SetConsoleWindowInfo(hConsole, TRUE, &rect);

	HorizontalLine topX(0, 25, 0, '#');
	HorizontalLine downX(0, 25, 15, '#');
	VerticalLine topY(0, 1, 14, '#');
	VerticalLine downY(25, 1, 14, '#');
	topX.Draw();
	downX.Draw();
	topY.Draw();
	downY.Draw();

	Point p(12, 7, 'o');
	Snake snake(p, 2, Direction::RIGHT);
	snake.Draw();
	char key;
	while (true){
		if (kbhit()){
			key = _getch();
			snake.handleKey(key);
		}
		Sleep(150);
		snake.Move();
	}
	
	system("pause>>void"); //Stop program while user don't press any key. 
	return 0;
}
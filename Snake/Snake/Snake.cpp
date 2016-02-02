// Snake.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "HorizontalLine.h"
#include "VerticalLine.h"
#include "Snake.h"
#include "FoodCreator.h"
#include <conio.h>
#include <time.h>
using namespace std;

void Draw(Figure figure){
	figure.Draw();
}

int _tmain(int argc, _TCHAR* argv[])
{
	srand((unsigned)time(NULL));//randomize random
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT rect = { 0, 0, 25, 15 };
	SetConsoleWindowInfo(hConsole, TRUE, &rect);

	HorizontalLine topX(0, 25, 0, '#');
	HorizontalLine downX(0, 25, 15, '#');
	VerticalLine topY(0, 1, 14, '#');
	VerticalLine downY(25, 1, 14, '#');
	Draw(topX);
	Draw(topY);
	Draw(downX);
	Draw(downY);
	/*topX.Draw();
	downX.Draw();
	topY.Draw();
	downY.Draw();*/

	Point p(12, 7, 'o');
	Snake snake(p, 2, Direction::RIGHT);
	snake.Draw();

	FoodCreator foodCreator(25, 15, '$');
	Point food = foodCreator.CreateFood();
	food.Draw();

	char key;
	while (true){
		if (snake.Eat(food)){
			food = foodCreator.CreateFood();
			food.Draw();
		}
		Sleep(50);
		if (kbhit()){
			key = _getch();
			snake.handleKey(key);
		}
		Sleep(100);
		snake.Move();
	}
	
	system("pause>>void"); //Stop program while user don't press any key. 
	return 0;
}
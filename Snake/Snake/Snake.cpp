// Snake.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Walls.h"
#include "Snake.h"
#include "FoodCreator.h"
#include <conio.h>
#include <string>
#include <time.h>
using namespace std;

void WriteText(string text, int xOffset, int yOffset)
{
	COORD pos = { xOffset, yOffset };//struct for coordinate our point(symbol)
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//descriptor
	SetConsoleCursorPosition(hConsole, pos);
	cout << text;
}

void GameOver(){
	int xOffset = 11;
	int yOffset = 13;
	COORD pos = { xOffset, yOffset };//struct for coordinate our point(symbol)
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//descriptor
	SetConsoleTextAttribute(hConsole, 0x3C);
	SetConsoleCursorPosition(hConsole, pos);
	WriteText("============================", xOffset, yOffset++);
	WriteText("И Г Р А    О К О Н Ч Е Н А", xOffset+1, yOffset++);
	yOffset++;
	WriteText("Автор: Бондарь Максим", xOffset + 2, yOffset++);
	WriteText("Специально для себя любимого", xOffset, yOffset++);
	WriteText("============================", xOffset, yOffset++);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int score = 0;
	SetConsoleOutputCP(1251);
	srand((unsigned)time(NULL));//randomize random
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT rect = { 0, 0, 49, 35 };
	SetConsoleWindowInfo(hConsole, TRUE, &rect);

	Walls walls(49, 35);
	walls.Draw();

	Point p(12, 7, 'o');
	Snake snake(p, 2, Direction::RIGHT);
	snake.Draw();

	FoodCreator foodCreator(25, 15, '$');
	Point food = foodCreator.CreateFood();
	food.Draw();

	char key;
	while (true){
		if (walls.IsHit(snake) || snake.isHitTail()){
			break;
		}
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
	GameOver();

	system("pause>>void"); //Stop program while user don't press any key. 
	return 0;
}
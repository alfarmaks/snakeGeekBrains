// Snake.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
using namespace std;

void Draw(int x, int y, char sym){
	COORD pos = { x, y };//struct for coordinate our point(symbol)
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//descriptor
	SetConsoleCursorPosition(hConsole, pos);
	cout << sym;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int x = 5;
	int y = x;
	Draw(x, y, '#');
	system("pause>>void"); //Stop program while user don't press any key. 
	return 0;
}


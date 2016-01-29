// Snake.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include "Point.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//Point number one
	Point p1;
	p1.x = 1;
	p1.y = 1;
	p1.symb = 'X';
	p1.Draw();
	//Point number two
	Point* p2 = new Point();
	p2->x = 0;
	p2->y = 0;
	p2->symb = '#';
	p2->Draw();
	system("pause>>void"); //Stop program while user don't press any key. 
	return 0;
}


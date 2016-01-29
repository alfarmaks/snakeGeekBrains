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
	Point p1(1, 1, 'X');
	p1.Draw();
	//Point number two
	Point* p2 = new Point(0, 0, '#');
	p2->Draw();
	system("pause>>void"); //Stop program while user don't press any key. 
	return 0;
}


// Snake.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Point.h"
#include "HorizontalLine.h"
#include "VerticalLine.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	HorizontalLine topX(0, 9, 0, '#');
	VerticalLine topY(0, 1, 9, '#');
	topX.Draw();
	topY.Draw();
	system("pause>>void"); //Stop program while user don't press any key. 
	return 0;
}
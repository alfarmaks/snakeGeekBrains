// Snake.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <algorithm>
#include <list>
#include "Point.h"
using namespace std;

void show_element(const int &i){
	cout << i << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//Point number one
	Point p1(1, 1, 'X');
	p1.Draw();
	//Point number two
	Point* p2 = new Point(0, 0, '#');
	p2->Draw();

	//list with integer values
	list<int>* newList = new list<int>();
	newList->push_back(1);
	newList->push_back(2);
	newList->push_back(3);
	newList->erase(newList->begin());// newList->begin() return iterator for first element. About function erase http://www.cplusplus.com/reference/list/list/erase/
	for_each(newList->begin(), newList->end(), show_element);

	//list with Points
	list<Point> * pList = new list<Point>();
	pList->push_back(p1);
	pList->push_back(*p2);
	pList->push_back(Point(5, 5, '/'));
	pList->push_back(Point(3, 10, '0'));

	system("pause>>void"); //Stop program while user don't press any key. 
	return 0;
}


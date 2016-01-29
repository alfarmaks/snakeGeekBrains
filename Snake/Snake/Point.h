#include <Windows.h>
#include <iostream>
#ifndef POINT_INCLUDED
#define POINT_INCLUDED
class Point{
private:
	int x = 0, y = 0;
	char symb = '*';
public:
	int getX() const{
		return this->x;
	}
	int getY() const{
		return this->y;
	}
	char getSymb() const{
		return this->symb;
	}
	Point(Point const & Some){
		this->x = Some.getX();
		this->y = Some.getY();
		this->symb = Some.getSymb();
	}
	bool &operator==(Point &Some){
		bool flag = true;
		if (this->x != Some.getX()) flag = false;
		if (this->y != Some.getY()) flag = false;
		if (this->symb != Some.getSymb()) flag = false;
		return flag;
	}
	Point(int x, int y, char sym){
		this->x = x;
		this->y = y;
		this->symb = sym;
	}
	void Draw(){
		COORD pos = { x, y };//struct for coordinate our point(symbol)
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//descriptor
		SetConsoleCursorPosition(hConsole, pos);
		std::cout << symb;
	}
};
#endif
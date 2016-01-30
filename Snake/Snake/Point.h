#include <Windows.h>
#include <iostream>
#include "Direction.h"
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
	void Move(int offset, Direction dir){
		if (dir == Direction::DOWN){
			this->y -= offset;
		}
		else if (dir == Direction::UP){
			this->y += offset;
		}
		else if (dir == Direction::LEFT){
			this->x -= offset;
		}
		else if (dir == Direction::RIGHT){
			this->x += offset;
		}
	}
	void Draw(){
		COORD pos = { x, y };//struct for coordinate our point(symbol)
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//descriptor
		SetConsoleCursorPosition(hConsole, pos);
		std::cout << symb;
	}
};
#endif
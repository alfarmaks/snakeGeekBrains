#include "Figure.h"
#ifndef VERTICAL_INCLUDED
#define VERTICAL_INCLUDED
class VerticalLine : public Figure{
private:
	Figure::line;
public:
	VerticalLine(int x, int startPos, int endPos, char symbol){
		line = new std::list<Point>();
		for (int y = startPos; y <= endPos; y++){
			line->push_back(Point(x, y, symbol));
		}
	}
};
#endif
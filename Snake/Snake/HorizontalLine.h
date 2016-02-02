#include "Figure.h"
#ifndef HORIZONTAL_INCLUDED
#define HORIZONTAL_INCLUDED
class HorizontalLine : public Figure{
private:
	Figure::line;
public:
	HorizontalLine(int startPos, int endPos, int y, char symbol){
		line = new std::list<Point>();
		for (int x = startPos; x <= endPos; x++){
			line->push_back(Point(x, y, symbol));
		}
	}
};
#endif
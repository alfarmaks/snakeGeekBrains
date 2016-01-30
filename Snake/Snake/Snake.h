#include "Figure.h"
#include "Direction.h"
class Snake : public Figure{
public:
	Snake(Point tail, int lenght, Direction dir){
		line = new std::list<Point>();
		for (int i = 0; i < lenght; i++){
			Point *p = new Point(tail);
			p->Move(i, dir);
			line->push_back(*p);
		}
	}
};
#include "Figure.h"
#include "Direction.h"
class Snake : public Figure{
private:
	Direction direction;
public:
	Snake(Point tail, int lenght, Direction dir){
		direction = dir;
		line = new std::list<Point>();
		for (int i = 0; i < lenght; i++){
			Point *p = new Point(tail);
			p->Move(i, dir);
			line->push_back(*p);
		}
	}

	void Move(){
		Point tail = *(line->begin());
		line->remove(tail);
		Point head = getNewPoint();
		line->push_back(head);
		tail.Clear();
		head.Draw();
	}

	Point getNewPoint(){
		Point head = *(--(line->end()));
		head.Move(1, direction);
		return head;
	}
};
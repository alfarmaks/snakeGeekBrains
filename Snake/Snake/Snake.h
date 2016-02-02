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

	Point getCurrPoint(){
		Point head = *(--(line->end()));
		return head;
	}
	
	void handleKey(char key){
		if (key == 68 || key == 100){
			direction = Direction::RIGHT;
		}
		else if (key == 65 || key == 97){
			direction = Direction::LEFT;
		}
		else if (key == 87 || key == 119){
			direction = Direction::UP;
		}
		else if (key == 83 || key == 115){
			direction = Direction::DOWN;
		}
	}

	bool Eat(Point food){
		Point head = getCurrPoint();
		if (head.isHit(food)){
			food.setSymb('o');
			food.Move(1, direction);
			line->push_back(food);
			food.Draw();
			return true;
		}
		return false;
	}
};
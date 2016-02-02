#include <list>
#include "Point.h"
#ifndef FIGURE_INCLUDED
#define FIGURE_INCLUDED
class Figure{
public:
	std::list<Point>* line;
public:
	void Draw(){
		for (auto it = line->begin(); it != line->end(); it++){
			it->Draw();
		}
	}
	bool isHit(Figure figure){
		for (auto point = line->begin(); point != line->end(); point++){
			if (figure.isHit(*point)){
				return true;
			}
		}
		return false;
	}

	bool isHit(Point point){
		for (auto p = line->begin(); p != line->end(); p++){
			if (p->isHit(point)){
				return true;
			}
		}
		return false;
	}
};
#endif
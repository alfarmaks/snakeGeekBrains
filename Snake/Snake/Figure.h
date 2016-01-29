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
};
#endif
#include <list>
class VerticalLine{
private:
	std::list<Point>* line;
public:
	VerticalLine(int x, int startPos, int endPos, char symbol){
		line = new std::list<Point>();
		for (int y = startPos; y <= endPos; y++){
			line->push_back(Point(x, y, symbol));
		}
	}

	void Draw(){
		for (auto it = line->begin(); it != line->end(); it++){
			it->Draw();
		}
	}
};
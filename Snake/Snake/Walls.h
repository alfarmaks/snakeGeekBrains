#include "VerticalLine.h"
#include "HorizontalLine.h"
class Walls{
private:
	std::list<Figure> wallList;
	int mapWidth, mapHeight;

public:
	Walls(int mapWidth, int mapHeight)
	{
		this->mapHeight = mapHeight;
		this->mapWidth = mapWidth;

		HorizontalLine topX(0, mapWidth, 0, '#');
		HorizontalLine downX(0, mapWidth, mapHeight, '#');
		VerticalLine topY(0, 1, mapHeight - 1, '#');
		VerticalLine downY(mapWidth, 1, mapHeight - 1, '#');

		wallList.push_back(topX);
		wallList.push_back(downX);
		wallList.push_back(topY);
		wallList.push_back(downY);
	}

	bool IsHit(Figure figure)
	{
		for (auto wall = wallList.begin(); wall != wallList.end(); wall++)
		{
			if (wall->isHit(figure))
			{
				return true;
			}
		}
		return false;
	}

	void Draw()
	{
		for (auto wall = wallList.begin(); wall != wallList.end(); wall++)
		{
			wall->Draw();
		}
	}
};
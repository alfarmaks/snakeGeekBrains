
class FoodCreator{
private:
	int mHeight = 0, mWidth = 0;
	char symb = '$';
public:
	FoodCreator(int x, int y, char sym){
		this->mWidth = x;
		this->mHeight = y;
		this->symb = sym;
	}
	Point CreateFood(){
		int x = 1 + rand() % (mWidth - 1);
		int y = 1 + rand() % (mHeight - 1);
		Point Food(x, y, symb);
		return Food;
	}
};
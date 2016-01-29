

class Point{
private:
	int x = 0, y = 0;
	char symb = '*';
public:
	Point(int x, int y, char sym){
		this->x = x;
		this->y = y;
		this->symb = sym;
	}
	void Draw(){
		COORD pos = { x, y };//struct for coordinate our point(symbol)
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//descriptor
		SetConsoleCursorPosition(hConsole, pos);
		std::cout << symb;
	}
};
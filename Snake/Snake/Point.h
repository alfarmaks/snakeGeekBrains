

class Point{
public:
	int x = 0, y = 0;
	char symb = '*';
	void Draw(){
		COORD pos = { x, y };//struct for coordinate our point(symbol)
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//descriptor
		SetConsoleCursorPosition(hConsole, pos);
		std::cout << symb;
	}
};
#include	<iostream>

class Point{
private:
	int xpos, ypos;

public:
	Point(int x=0, int y=0) : xpos(x), ypos(y) {}

	void ShowPosition(){
		std::cout << xpos << ", " << ypos << std::endl;
	}

	friend std::ostream& operator<<(std::ostream& os, const Point&);
};

std::ostream& operator<<(std::ostream& os, const Point& pos){
	os << "[" << pos.xpos << ", " << pos.ypos << "]";
	return os;
}

int main(){
	Point pos1(1, 3);
	std::cout << pos1 << std::endl;
	Point pos2(101, 303);
	std::cout << pos2;

	return 0;
}

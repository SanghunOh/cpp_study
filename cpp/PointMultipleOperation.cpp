#include	<iostream>

class Point{
private:
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}

	void ShowPosition(){
		std::cout << "[" << xpos << ", " << ypos << "]" << std::endl;
	}

	Point operator*(int times){
		Point pos(xpos*times, ypos*times);
		return pos;
	}

	friend Point operator*(int, const Point&);
};

Point operator*(int times, const Point& po){
	Point pos(po.xpos*times, po.ypos*times);
	return pos;
}

int main(){
	Point pos(1, 2);

	Point cpy;
	cpy = pos*3;
	cpy.ShowPosition();

	cpy = pos*3*2;
	cpy.ShowPosition();

	cpy = 5*2*pos;
	cpy.ShowPosition();

	return 0;
}

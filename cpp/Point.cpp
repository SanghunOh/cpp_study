#include	<iostream>
#include	"Point.h"

std::ostream& operator<<(std::ostream& os, const Point& pos){
	os << "[" << pos.xpos << ", " << pos.ypos << "]" << std::endl;
	return os;
}

Point::Point(int x=0, int y=0) : xpos(x), ypos(y) {}

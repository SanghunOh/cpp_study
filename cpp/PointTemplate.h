#ifndef __POINT_TEMPLATE_H
#define __POINT_TEMPLATE_H

template <typename T>
class Point{
private:
	T xpos;
	T ypos;

public:
	Point(T x=0, T y=0);
	void ShowPosition() const;
};

template <typename T>
Point<T>::Point(T x=0, T y=0) : xpos(x), ypos(y){}

template <typename T>
void Point<T>::ShowPosition() const {
	std::cout << "[" << xpos << ", " << ypos << "]" <<std::endl;
}
#endif

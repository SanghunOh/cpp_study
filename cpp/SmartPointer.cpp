#include	<iostream>

class Point{
private:
	int xpos;
	int ypos;

public:
	Point(int x=0, int y=0) : xpos(x), ypos(y) {
		std::cout << "객체 생성" << std::endl;
	}

	~Point(){
		std::cout << "destruct object" << std::endl;
	}

	void SetPos(int x, int y){
		xpos = x;
		ypos = y;
	}
	
	friend std::ostream& operator<<(std::ostream& os, const Point& pos);
};

std::ostream& operator<<(std::ostream& os, const Point& pos){
	os << "[" << pos.xpos << ", " << pos.ypos << "]" << std::endl;
	return os;
}

class SmartPtr{
private:
	Point* posptr;

public:
	SmartPtr(Point* ptr) : posptr(ptr){}

	Point& operator*() const{
		return *posptr;
	}

	Point* operator->() const{
		return posptr;
	}

	~SmartPtr(){
		delete posptr;
	}
};

int main(){
	SmartPtr sptr1(new Point(1, 2));
	SmartPtr sptr2(new Point(3, 4));
	SmartPtr sptr3(new Point(5, 6));

	std::cout << *sptr1;
	std::cout << *sptr2;
	std::cout << *sptr3;

	sptr1->SetPos(10, 20);
	sptr2->SetPos(30, 40);
	sptr3->SetPos(50, 60);

	std::cout << *sptr1;
	std::cout << *sptr2;
	std::cout << *sptr3;

	return 0;
}

#include	<iostream>
#include	<string>

class Rectangle{
private:
	int x;
	int y;

public:
	Rectangle() 
		:x(0), y(0) {}
	Rectangle(int x, int y)
		:x(x), y(y) {}

	void ShowAreaInfo();
};

void Rectangle::ShowAreaInfo(){
	std::cout << "Area: " << x * y << std::endl;
	return;
}

class Square : public Rectangle{
public:
	Square()
		: Rectangle(0, 0) {}
	Square(int r)
		: Rectangle(r, r) {}
};

int main(){
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();

	return 0;
}

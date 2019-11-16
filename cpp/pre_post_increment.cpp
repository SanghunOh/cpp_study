#include	<iostream>

class Test{
private:
	int x;

public:
	Test(int x) : x(x) {}
	Test(const Test& t) : x(t.x) {}

	Test& operator++(){
		x++;
		std::cout << "pre increment" << std::endl;
		return *this;
	}

	Test operator++(int){
		Test temp(*this);
		x++;
		std::cout << "post increment" << std::endl;
		return temp;
	}

	int get_x() const {
		return x;
	}
};

void func(const Test& t){
	std::cout << "x: " << t.get_x() << std::endl;
}

int main(){
	Test t(3);

	func(++t);
	func(t++);
	std::cout << "x: " << t.get_x() << std::endl;

	return 0;
}

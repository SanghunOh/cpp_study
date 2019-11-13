#include	<iostream>

class A{
	mutable int data_;

public:
	A(int data) : data_(data){}
	void Dosomething(int x) const{
		data_ = x;
	}

	void printdata() const{
		std::cout << "data: " << data_ << std::endl;
	}
};

int main(){
	A a(10);
	a.Dosomething(3);
	a.printdata();
}

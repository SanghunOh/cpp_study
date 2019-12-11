#include	<iostream>

class A{
	int data_;

public:
	A(int data) : data_(data) {
		std::cout << "calling normal constructor" << std::endl;
	}

	A(const A& a) : data_(a.data_){
		std::cout << "calling copy constructor" << std::endl;
	}
};

int main(){
	A a(1);
	A b(a);

	A c(A(2));

	return 0;
}

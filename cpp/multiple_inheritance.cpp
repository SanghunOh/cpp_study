#include	<iostream>

class A{
public:
	int a;
	A(){
		std::cout << "call A constructor" << std::endl;
	}
};

class B {
public:
	int b;
	B(){
		std::cout << "call B constructor" << std::endl;
	}
};

class C : public A, public B{
public:
	int c;
	C(): B(), A(){
		std::cout << "call C constructor" << std::endl;
	}
};

int main(){
	C c;
	
	return 0;
}

#include	<iostream>

class Parent{
public:
	Parent(){
		std::cout << "call Parent constructor" << std::endl;
	}
	
	virtual ~Parent(){
		std::cout << "call Parent destructor" << std::endl;
	}
};

class Child : public Parent{
public:
	Child() : Parent(){
		std::cout << "call Child constructor" << std::endl;
	}

	~Child() override{
		std::cout << "call Child destructor" << std::endl;
	}
};

int main(){
	std::cout << "----normal Child----" << std::endl;
	{Child c;}
	std::cout << "----Parent 포인터로 Child를 가리켰을 때----" << std::endl;
	{
		Parent* p = new Child();
		delete p;
	}
}

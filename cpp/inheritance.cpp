#include	<iostream>
#include	<string>

class Base{
protected:
	std::string s;

public:
	Base() : s("Base") {std::cout << "Base class" << std::endl;}

	void what(){
		std::cout << s << std::endl;
	}
};

class Derived : public Base{
	std::string s;

public:
	Derived() : Base(), s("Derived"){
		std::cout << "Derived class" << std::endl;
		what();
		Base::s = "asdf";
	}
	void what(){
		std::cout << s << std::endl;
	}
};

int main(){
	std::cout << "=== make base class ===" << std::endl;
	Base p;

	std::cout << "=== make derived class ===" << std::endl;
	Derived c;

	return 0;
}

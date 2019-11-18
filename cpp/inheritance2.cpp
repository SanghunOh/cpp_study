#include	<iostream>

class Base{
	std::string s;

public:
	Base() : s("Base"){
		std::cout << "base class" << std::endl;
	}

	void what(){
		std::cout << s << std::endl;
	}
};

class Derived : public Base{
	std::string s;

public:
	Derived() : s("derived"), Base() {
		std::cout << "derived class" << std::endl;
	}

	void what(){
		std::cout << s << std::endl;
	}
};

int main(){
	Base p;		//-> base class
	Derived c;	//-> base class
			//-> derived class
	std::cout << "=== pointer version ===" << std::endl;
	Base* p_c = &c;
	p_c->what();
//파생클래스에서 기반 클래스로 캐스팅 하는 것 == 업캐스팅

//	Derived p_p = &p -> 불가능

//	Derived p_p = p_c -> 불가능

//	Derived p_p = static_cast<Derived*>(p_p);
	p_c->what();
	return 0;
}

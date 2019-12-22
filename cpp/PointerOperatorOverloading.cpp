#include	<iostream>
#include	<typeinfo>

class Number{
private:
	int num;

public:
	Number(int n) : num(n) {}

	void ShowData(){
		std::cout << num << std::endl;
	}

	Number* operator->(){
		return this;
	}

	Number& operator*(){
		return *this;
	}
};

int main(){
	Number num(20);
	Number* num2 = new Number(30);
	num.ShowData();

	std::cout << typeid(num).name() << std::endl;
	std::cout << typeid(num2).name() << std::endl;

	(*num) = 30;
	num->ShowData();
	(*num).ShowData();

	return 0;
}

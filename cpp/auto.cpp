#include	<iostream>
#include	<typeinfo>

int sum(int a, int b){
	return a + b;
}

class SomeClass{
	int data;

public:
	SomeClass(int d) : data(d){}
	SomeClass(const SomeClass& s) : data(s.data){}
};

int main(){
	auto c = sum(1, 2);
	auto num = 1.0 + 2.0;

	SomeClass some(10);
	auto some2 = some;

	auto some3(10);

	std::cout << "type c : " << typeid(c).name() << std::endl;
	std::cout << "type num : " << typeid(num).name() << std::endl;
	std::cout << "type some2 : " << typeid(some2).name() << std::endl;
	std::cout << "type some3 : " << typeid(some3).name() << std::endl;

	return 0;
}

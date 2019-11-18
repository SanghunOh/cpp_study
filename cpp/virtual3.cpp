#include	<iostream>

class Animal{
public:
	Animal(){}
	virtual ~Animal(){}
	virtual void speak() = 0;	// 반드시 오버라이딩 되어야만함
					// = pure virtual funcion
					// 이 함수를 호출하는 것은 불가능
					// --> Animal객체를 생성하는 것도 불가능
					// 이러한 클래스를 추상클래스(abstract class)라고 함
};

class Dog : public Animal{
public:
	Dog(): Animal(){}
	void speak() override {
		std::cout << "왈왈" << std::endl;
	}
};

class Cat : public Animal{
public:
	Cat(): Animal(){}
	void speak() override{
		std::cout << "야옹" << std::endl;
	}
};

int main(){
	Dog* dog = new Dog();
	Animal* cat = new Cat();

	dog->speak();
	cat->speak();

	return 0;
}

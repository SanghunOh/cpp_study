#include	<iostream>

class AAA{
private:
	int num1;
public:
	virtual void func1(){
		std::cout << "func1" << std::endl;
	}

	virtual void func2(){
		std::cout << "func2" << std::endl;
	}
};

class BBB : public AAA{
private:
	int num2;
public:
	virtual void func1(){
		std::cout << "BBB::func1" << std::endl;
	}
	void func3(){
		std::cout << "func3" << std::endl;
	}
};

int main(){
	AAA* aptr = new AAA();
	aptr->func1();

	BBB* bptr = new BBB();
	bptr->func1();

	return 0;
}

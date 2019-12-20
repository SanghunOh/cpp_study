#include	<iostream>

class First{
public:
	virtual void MyFunc(){
		std::cout << "First Func" << std::endl;
	}
};

class Second : public First{
public:
	virtual void MyFunc(){
		std::cout << "Second Func" << std::endl;
	}
};

class Third : public Second{
public:
	virtual void MyFunc(){
		std::cout << "Third Func" << std::endl;
	}
};

int main(){
	Third* tptr = new Third();
	Second* sptr = tptr;
	First* fptr = sptr;

	fptr->MyFunc();
	sptr->MyFunc();
	tptr->MyFunc();

	delete tptr;
	
	return 0;
}

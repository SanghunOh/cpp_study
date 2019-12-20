#include	<iostream>
#include	<cstring>

class First{
public:
	void FirstFunc(){
		std::cout << "FirstFunc()" << std::endl;
	}

	virtual void SimpleFunc(){
		std::cout << "First is SimpleFunc()" << std::endl;
	}
};

class Second : public First{
public:
	void SecondFunc(){
		std::cout << "SecondFunc()" << std::endl;
	}

	virtual void SimpleFunc(){
		std::cout << "Second is SimpleFunc()" << std::endl;
	}
};

class Third : public Second{
public:
	void ThirdFunc(){
		std::cout << "ThirdFunc()" << std::endl;
	}

	virtual void SimpleFunc(){
		std::cout << "Third is SimpleFunc()" << std::endl;
	}
};

int main(){
	Third obj;
	obj.FirstFunc();
	obj.SecondFunc();
	obj.ThirdFunc();
	obj.SimpleFunc();

	Second& sref = obj;
	sref.FirstFunc();
	sref.SecondFunc();
	sref.SimpleFunc();

	First& fref = obj;
	fref.FirstFunc();
	fref.SimpleFunc();

	return 0;
}

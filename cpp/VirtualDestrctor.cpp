#include	<iostream>
#include	<cstring>

class First{
private:
	char* strOne;

public:
	First(char* str){
		strOne = new char[strlen(str) + 1];
	}

	virtual ~First(){
		std::cout << "~First()" << std::endl;
		delete strOne;
	}
};

class Second : public First{
private:
	char* strTwo;

public:
	Second(char* str1, char* str2) : First(str1){
		strTwo = new char[strlen(str2) + 1];
	}

	~Second(){
		std::cout << "~Second" << std::endl;
		delete strTwo;
	}
};

int main(){
	First* ptr = new Second("simple", "complex");

	delete ptr;

	return 0;
}

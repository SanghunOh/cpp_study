#include	<iostream>

class MyString{
	char* string;
	int len;

	int memory_capacity;

public:
	explicit MyString(int);
	MyString(const char*);
	MyString(const MyString&);
	~MyString();

	int length() const;
};

MyString::MyString(int capacity){
	string = new char[capacity];
	len = 0;
	memory_capacity = capacity;
}

MyString::MyString(const char* str){
	len = 0;
	while(str[len++]){}

	string = new char[len];
	memory_capacity = len;

	for(int i=0 ; i<len ; i++)
		string[i] = str[i];
}

MyString::MyString(const MyString& str){
	len = str.len;
	string = new char[str.len];

	for(int i=0 ; i<len ; i++)
		string[i] = str.string[i];
}

MyString::~MyString(){
	delete [] string;
}

int MyString::length() const{
	return len;
}

int main(){
	MyString s(3);

	return 0;
}

#include	<iostream>
#include	<cstring>

class String{
private:
	int len;
	char* str;

public:
	String();
	String(const char*);
	String(const String&);
	~String();

	String& operator=(const String&);
	String operator+(const String&);
	String& operator+=(const String&);
	bool operator==(const String&);
	
	friend std::ostream& operator<<(std::ostream&, const String&);
	friend std::istream& operator>>(std::istream&, String&);
};

std::ostream& operator<<(std::ostream& os, const String& s){
	os << s.str << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, String& s){
	char str[100];
	is >> str;
	s = String(str);
	return is;
}

String::String(){
	len = 0;
	str = nullptr;
}

String::String(const char*s){
	len = strlen(s) + 1;
	str = new char[len];
	strcpy(str, s);
}

String::String(const String& s){
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
}

String::~String(){
	if(str)
		delete [] str;
}

String& String::operator=(const String& s){
	len = s.len;
	if(str)
		delete [] str;
	str = new char[len];
	strcpy(str, s.str);
	return *this;
}

String String::operator+(const String& s){
	String tmp;
	tmp.len = len + s.len - 1;
	tmp.str = new char[tmp.len];

	strcpy(tmp.str, str);
	strcat(tmp.str, s.str);
	return tmp;
}


bool String::operator==(const String& s){
	return !strcmp(str, s.str);
}

String& String::operator+=(const String& s){
	char* tmp;
	tmp = str;

	len += (s.len-1);
	str = new char[len];

	strcpy(str, tmp);
	strcat(str, s.str);

	delete [] tmp;

	return *this;
}

int main(){
	
}

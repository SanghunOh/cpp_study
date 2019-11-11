#include	<iostream>

class String{
private:
	char* str;
	int len;

public:
	String(char, int);
	String(const char*);
	String(const String& s);
	~String();

	void add_string(const String&);
	void copy_string(const String&);
	int strlen();
};

String::String(char c, int n){
	int i;
	str = new char[n];
	len = n;
	for(i=0 ; i<n ; i++)
		str[i] = c;
	str[i] = '\0';
}

String::String(const char* s){
	len = 0;
	while(s[len++] != '\0');
	str = new char[len];
	for(int i=0 ; i<len ; i++)
		str[i] = s[i];
}

String::String(const String& s){
	str = new char[s.len + 1];
	for(int i=0 ; i<=s.len ; i++)  		//왜 s.strlen()을 쓰면 오류가 발생하고
		str[i] = s.str[i];		// s.len을 쓰면 잘 되는지 모르겠다.
	len = s.len;
}

String::~String(){
	delete[] str;
}

int String::strlen(){
	return len;
}

void String::copy_string(const String& s){
	delete[] str;
	len = s.len;
	str = new char[len];
	for(int i=0 ; i<=len ; i++)
		str[i] = s.str[i];
}

void String::add_string(const String& s){
	char* tmp;
	tmp = new char[len + s.len + 1];
	for(int i=0 ; i<len ; i++)
		tmp[i] = str[i];
	for(int i=0 ; i<s.len ; i++)
		tmp[i+len] = s.str[i];
	len += s.len;
	delete str;
	str = tmp;
}

int main(){
	String s("ABCDEFG");
	

	return 0;
}

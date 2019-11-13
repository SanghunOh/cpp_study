#include	<iostream>

class string{
private:
	char* s;
	int len;

public:
	string();
	string(char c);
	string(char c, int n);
	string(const char* str);
	string(const string& str);
	~string();
	

	char* add_string(string&);
	int strlen() const;
	bool is_same(string&) const;
	int string_compare(string&) const;
	string& assign(const string&);
	string& assign(const char*);
	char at(int) const;

	string& insert(int, const string&);
	string& insert(int, const char*);
	string& insert(int, char);

	string& erase(int, int);

	void printstr() const;
};

string::string(){
	s = NULL;
	len = 0;
}

string::string(char c){
	s = new char [1];
	s[0] = c;
	len = 1;
}

string::string(char c, int n){
	len = n;
	s = new char[n];

	for(int i=0 ; i<n ; i++){
		s[i] = c;
	}
}

string::string(const char* str){
	len = 0;
	while(str[len++] != '\0')
		;

	len -= 1;
	std::cout << len << std::endl;

	s = new char [len];


	for(int i=0 ; i<len ; i++)
		s[i] = str[i];
}

string::string(const string& str)
	: len(str.len){
	s = new char [str.len];
	
	for(int i=0 ; i<len ; i++)
		s[i] = str.s[i];	
}

string::~string(){
	if(s)
		delete s;
}

char* string::add_string(string& str){
	char* tmp;
	
	tmp = new char[str.len + len];
	for(int i=0 ; i<len ; i++)
		tmp[i] = s[i];
	for(int i=0 ; i<str.len ; i++)
		tmp[i+len] = str.s[i];
	return tmp;
}

int string::strlen() const{
	return len;
}

bool string::is_same(string& str) const{
	if(len != str.strlen())
		return false;
	for(int i=0 ; i<len ; i++){
		if(s[i] != str.s[i])
			return false;
	}
	return true;
}

int string::string_compare(string& str) const{
	if(len < str.len){
		for(int i=0 ; i<len ; i++){
			if(s[i] < str.s[i])
				return -1;
			else if(s[i] > str.s[i])
				return 1;
		}
		return -1;
	}
	else if(len > str.len){
		for(int i=0 ; i>len ; i++){
			if(s[i] > str.s[i])
				return 1;
			else if(s[i] < str.s[i])
				return -1;
		}
		return 1;
	}
	else{
		for(int i=0 ; i<len ; i++){
			if(s[i] < str.s[i])
				return -1;
			else if(s[i] > str.s[i])
				return 1;
		}
		return 0;
	}
}

string& string::assign(const char* str){
	if(s)
		delete s;
	len = -1;

	while(str[len++] != '\0')
		;

	s = new char [len];

	for(int i=0 ; i<len ; i++)
		s[i] = str[i];
	return *this;
}

string& string::assign(const string& str){
	if(s)
		delete s;

	s = new char[str.len];
	len = str.len;

	for(int i=0 ; i<len ; i++)
		s[i] = str.s[i];
	
	return *this;
}

char string::at(int i) const{
	if(i >= 0 && i<len)
		return s[i];
	else
		return 0;
}

string& string::insert(int loc, const string& str){
	if(loc < 0 || loc > len)
		return *this;

	char* new_s;
	new_s = s;
	s = new char[len+str.len];
	

	for(int i=0 ; i<loc ; i++)
		s[i] = new_s[i];

	for(int i=len ; i>loc ; i--)
		s[i + str.len - 1] = new_s[i-1];

	for(int i=0 ; i<str.len ; i++)
		s[i + loc] = str.s[i];

	len += str.len;


	delete new_s;

	return *this;
}

string& string::insert(int loc, const char* str){
	string temp(str);
	
	return insert(loc, temp);
}

string& string::insert(int loc, char c){
	string temp(c);

	return insert(loc, temp);
}

string& string::erase(int loc, int num){
	if(num < 0 || loc < 0 || loc > len)
		return *this;

	for(int i=loc+num ; i<len ; i++)
		s[i-num] = s[i];

	len -= num;
	s[len] = '\0';
	
	return *this;
}

void string::printstr() const{
	std::cout << s << std::endl;
}

int main(){
	string s1("hi");
	string s2("hio");

	if(s1.is_same(s2))
		std::cout << "same!" << std::endl;
	else
		std::cout << "not same!" << std::endl;

	std::cout << s1.string_compare(s2) << std::endl;
	std::cout << s1.add_string(s2) << std::endl;

	s1.insert(0, "asdf");
	s1.printstr();
	s1.erase(0, 4);
	s1.printstr();

	return 0;
}

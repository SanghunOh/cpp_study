#include	<fstream>
#include	<iostream>
#include	<string>

int main(){
	std::ifstream out("test.txt");
	std::string s;

	if(out.is_open()){
		out >> s;
		std::cout << "input : " << s << std::endl;
	}
	else{
		std::cout << "no file!" << std::endl;
	}

	out.close();
	out.open("test1.txt");

	if(out.is_open()){
		out >> s;
		std::cout << "input : " << s << std::endl;
	}
	else{
		std::cout << "no file!" << std::endl;
	}

	return 0;
}

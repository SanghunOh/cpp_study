#include	<iostream>
#include	<string>

int main(){
	std::string s;
	std::cin >> s;

	char peek = std::cin.rdbuf()->snextc();
//	char t = std::cin.rdbuf()->snextc();
	
	if(std::cin.fail())
		std::cout << "failed";

	std::cout << "first char of second word : " << peek << std::endl;
	std::cin >> s;
	std::cout << "다시 읽으면 : " << s << std::endl;

//	std::cout << t << std::endl;

	return 0;
}

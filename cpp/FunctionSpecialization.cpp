#include	<iostream>
#include	<string>

template <typename T>
T Max(T a, T b){
	return a > b ? a : b;
}
/*
template <>
std::string& Max(std::string a, std::string b){
	std::cout << "std::string Max" << std::endl;
	if(a.length() > b.length())
		return a;
}
*/
int main(){
	std::cout << Max<int>(11, 15);
	std::cout << Max<char>('T', 'Q');
	std::cout << Max(3.5, 8.3);

	std::cout << Max(std::string("Simple"), std::string("Best"));
}

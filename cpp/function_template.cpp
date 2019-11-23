#include	<iostream>
#include	<string>

template <typename T>
T max(T& a, T& b){
	return a > b ? a : b;
}

int main(){
	int a, b;
	a = 1;
	b = 2;
	std::cout << max(a, b) << std::endl;

	std::string s, t;
	s = "hello";
	t = "world";
	std::cout << max(s, t) << std::endl;
	
	return 0;
}

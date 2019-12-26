#include	<iostream>

int main(){
	int num1, num2;

	std::cin >> num1 >> num2;

	try{
		if(!num2)
			throw num2;
		std::cout << "Q : " << num1 / num2 << std::endl;
		std::cout << "R : " << num1 % num2 << std::endl;
	}
	catch(int expn){
		std::cout << expn << std::endl;
		std::cout << "restrt" << std::endl;
	}

	std::cout << "end main" << std::endl;

	return 0;
}

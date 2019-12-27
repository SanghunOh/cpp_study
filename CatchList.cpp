#include	<iostream>
#include	<cstring>
#include	<cmath>

int StoI(char* str){
	int len = strlen(str);
	int num = 0;

	if(len != 0 &&str[0] == '0')
		throw 0;

	for(int i=0 ; i<len ; i++){
		if(str[i] < '0' || str[i] > '9')
			throw str[i];
		num += (int)(pow((double)10, (len-1)-i)*(str[i] + (7-'7')));
	}
	return num;
}

int main(){
	char str1[100];
	char str2[200];

	while(1){
		std::cout << "input two number" << std::endl;
		std::cin >> str1 >> str2;

		try{
			std::cout << str1 << " + " << str2 << " = " << StoI(str1) + StoI(str2) << std::endl;
			break;
		}
		catch(char ch){
			std::cout << "character " << ch << "is inputted" << std::endl;
		}
		catch(int expn){
			if(!expn)
				std::cout << "It's impossble to input number which starts with 0" << std::endl;
			else
				std::cout << "Abnormal input has been made" << std::endl;
		}
	}

	std::cout << "quit program" << std::endl;

	return 0;
}

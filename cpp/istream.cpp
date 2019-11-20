#include	<iostream>
#include	<string>

int main(){
	int t;

	while(true){
		std::cin >> t;
		std::cout << "input: " << t << std::endl;

		if(std::cin.fail()){	//fail bit or bad biton --> failbit를 초기화하지 않으면 다시 cin을 사용할 수 없음
			std::cout << "retry" << std::endl;
			std::cin.clear();	//fail bit & bad bit초기화
			std::cin.ignore(100, '\n');	//개행문자가 나올때 까지 무시-> 버퍼를 비운다.
		}
		if(t)
			break;
	}

///////////////////////////////////////////////////////

	int a;
	while(true){
		std::cin.setf(std::ios_base::hex, std::ios_base::basefield);
		std::cin >> std::hex >> a;

		std::cin >> a;
		std::cout << "input: " << a << std::endl;

		if(std::cin.fail()){
			std::cout << "retry" << std::endl;
			std::cin.clear();
		}

		if(a)
			break;
	}
}

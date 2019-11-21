#include	<iostream>
#include	<string>
#include	<fstream>

int main(){
	std::ifstream in("test.txt");
	char buf[100];

	if(!in.is_open()){
		std::cout << "no file!" << std::endl;

		return 0;
	}

	std::string s;
	while(in){
//		in.getline(buf, 100);
//		in.getline(buf, 100, '.')' -> .이 나올때까지
//		하지만 버퍼의 크리 - 1까지 밖에 받지 못함
//		그 이상 받으면 failbit가 켜짐
//		그래서 string클래스에 정의되어 는 getline함수를 이용
		getline(in, s);		
		std::cout << s << std::endl;
	}

	return 0;
}

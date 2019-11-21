#include	<iostream>
#include	<string>
#include	<fstream>

int main(){
	std::ofstream out("test.txt", std::ios::app);	//덧붙이기
//	std::ofstream out("test.txt", std::ios::ate);	//파일 끝에서부터 읽기, 쓰기
//	std::ofstream out("test.txt", std::ios::trunc);	//기존 내용 모두 삭제


	std::string s;

	if(out.is_open()){
		out << "add";
	}

	return 0;
}

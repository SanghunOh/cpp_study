#include	<iostream>
using namespace std;

int main(){
//	int &ref = 4;
//	disable because, it could be changed to another literal

	const int& ref = 4;
//	const를 사용하면 상수참조자 가능
	return 0;
}

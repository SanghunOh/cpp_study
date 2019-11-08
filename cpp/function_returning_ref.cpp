#include	<iostream>
using namespace std;

int fn1(int& a){
	return a;
}

int& fn2(int& a){
	return a;
}

int main(){
	int x = 1;

	cout << fn2(x)++ << endl;
	cout << "x :: " << x << endl;

	return 0;
}

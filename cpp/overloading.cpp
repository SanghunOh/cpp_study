#include	<iostream>
using namespace std;

void print(int x){
	cout << "int : " << x << endl;
}

void print(char x){
	cout << "char : " << (int)x << endl;
}

void print(double x){
	cout << "double : " << x << endl;
}

int main(){
	int a = 1;
	char b = 'c';
	double c = 3.2;

	print(a);
	print(b);
	print(c);

	return 0;
}

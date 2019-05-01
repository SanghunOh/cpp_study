#include	<iostream>
#include	<iomanip>
using namespace std;

int main(){
	float a = 123.123456;
	double b = 123.123456;

	cout << setiosflags(ios::fixed);
	cout << a << endl;
	cout << b << endl;
}

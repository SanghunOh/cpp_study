#include	<iostream>
using namespace std;

int main(){
	int i=3;
	int* p = &i;

	cout << "i is " << i << endl;
	cout << "*p is " << *p << endl;
	cout << "p is " << p << endl;

	return 0;
}

#include	<iostream>
using namespace std;

void change_val(int &p){
	p = 3;
}

int main(){
	int number = 4;

	cout << number << endl;
	change_val(number);
	cout << number << endl;

	return 0;
}

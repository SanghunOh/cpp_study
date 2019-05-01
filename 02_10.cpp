#include	<iostream>
#include	<cstring>
using namespace std;

int main(){
	char flowers[] = "rose";
	char flowers2[] = {'l', 'i', 'l', 'a', 'c'};
	char flowers3[] = "tulip";

	cout << flowers << endl;
	cout << flowers2 << endl;
	cout << flowers3 << endl;

	cout << strlen(flowers) << endl;
	cout << sizeof(flowers2) << endl;
}

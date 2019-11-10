#include	<iostream>
using namespace std;

int main(){
	int* var1;
	var1 = new int;
	delete var1;

	int* var2;
	var2 = new int[3];
	
	for(int i=0 ; i<3 ; i++)
		cout << var2[i] << endl;

	delete [] var2;


//이차원 배열 동적할당
	int** var3;
	var3 = new int*[3];
	for(int i=0 ; i<3 ; i++)
		var3[i] = new int[4];

	for(int i=0 ; i<3 ; i++)
		delete var3[i];
	delete [] var3;
}

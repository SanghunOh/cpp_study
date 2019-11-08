#include	<iostream>
using namespace std;

namespace{
	void OnlyInThisFile(){
		cout << "Hello world!" << endl;

//		return 1;
	}

	int only_in_this_file = 0;
}

int main(){
	OnlyInThisFile();
//	cout << only_in_this_file << endl;
	only_in_this_file = 3;
	cout << only_in_this_file << endl;
	return 0;
}

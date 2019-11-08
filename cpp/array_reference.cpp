#include	<iostream>
using namespace std;

int main(){
//	int &arr[2] = {a, b};
//	레퍼런스 배열은 불가능
//	레퍼런스의 레퍼런서, 레퍼런스의 배열, 레퍼런서의 포인터는
//	존재할 수 없음
//	배열의 레퍼런스만 가능
//	하지만 포인터를 쓰는게 더 효율적임

	int arr[3] = {1, 2, 3};
	int (&ref)[3] = arr;

	ref[0] = 2;
	ref[1] = 3;
	ref[2] = 1;

	cout << arr[0] << endl << arr[1] << endl << arr[2] << endl;

	return 0;
}

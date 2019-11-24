#include	<iostream>
#include	<array>

template <typename T, int num>
T add_num(T t){
	return t+num;
}

void print_array(const std::array<int, 5>&arr){
	for(int i=0 ; i<arr.size() ; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}
//이 함수는 std::array<int, 5> 크리가 5인 배열밖에 받지 못함 -> template 사용!

//

template <typename T>
void print_array(const T& arr){
	for(int i=0 ; i<arr.size() ; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main(){
	int x= 3;
	std::cout << "x : " << add_num<int, 5>(x) << std::endl;

	std::array<int, 5> arr = {1, 2, 3, 4, 5};
	std::array<int, 7> arr2 = {1,2,3,4,5,6,7};
	std::array<int, 3> arr3 = {1,2,3};

	print_array(arr);
	print_array(arr2);
	print_array(arr3);

	return 0;
}

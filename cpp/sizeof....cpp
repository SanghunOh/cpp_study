#include	<iostream>

int sum_all(){
	return 0;
}

template <typename... Ints>
int sum_all(int num, Ints... nums){
	return num + sum_all(nums...);
}

template <typename... Ints>
double average(Ints... nums){
	return static_cast<double>(sum_all(nums...)) / sizeof...(nums);
}

int main(){
	std::cout << sum_all(1,2,3,4,5,6,7,8,9) << std::endl;
	std::cout << average(1,2,3,4,5,6,7,8,9) << std::endl;

	return 0;
}

#include	<iostream>

template <typename... Ints>
int sum_all(Ints... nums){
	return (... + nums);
}

int main(){
	std::cout << sum_all(1,2,3,4,5,6,7,8,9) << std::endl;
}

#include	<iostream>
#include	<vector>
#include	<typeinfo>

template <typename T>
void print_vector(std::vector<T>& vec){
	for(typename std::vector<T>::iterator i=vec.begin() ; i<vec.end() ; i++)
		std::cout << *i << std::endl;
}

template <typename T>
void print_vector_range_based(std::vector<T>& vec){
	for(const auto& elem : vec){
		std::cout << elem << std::endl;
	}
}

int main(){
	std::vector<int> vec;
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(6);

	std::cout << vec.front() << std::endl;
	std::cout << vec.back() << std::endl;


	print_vector(vec);
	print_vector_range_based(vec);
	return 0;
}

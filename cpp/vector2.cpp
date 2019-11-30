#include	<iostream>
#include	<vector>

template <typename T>
void print_vector(std::vector<T>& vec){
	for(typename std::vector<T>::iterator itr = vec.begin() ; itr<vec.end() ; itr++)
		std::cout << *itr << std::endl;
}


int main(){
	std::vector<int> vec;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);

	std::cout << "first" << std::endl;

	print_vector(vec);

	
	std::vector<int>::iterator itr = vec.begin();

	for( ; itr < vec.end() ; itr++){
		if(*itr == 20){
			vec.erase(itr);
			itr = vec.begin();
		}
	}

	std::cout << "erase 20" << std::endl;
	print_vector(vec);

	return 0;
}

#include	<iostream>
#include	<vector>

int main(){
	std::vector<int> vec;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);

	for(std::vector<int>::size_type i=0 ; i<vec.size() ; i++)
		std::cout << i+1 << " : " << vec[i] << std::endl;


	std::cout << "///////////////////////////////////" << std::endl << std::endl;

	for(std::vector<int>::iterator itr = vec.begin() ; itr < vec.end() ; itr++)
		std::cout << *itr << std::endl;


	std::vector<int>::iterator itr = vec.begin() + 2;
	std::cout << "third : " << *itr << std::endl;
	return 0;
}

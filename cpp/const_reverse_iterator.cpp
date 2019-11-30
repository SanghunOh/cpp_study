#include	<iostream>
#include	<vector>

int main(){
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	for(std::vector<int>::size_type t = vec.size()-1 ; t>=0 ; t--)
		std::cout << vec[t] << std::endl;

	return 0;
}

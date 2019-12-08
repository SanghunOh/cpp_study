#include	<iostream>
#include	<vector>
#include	<algorithm>
#include	<functional>

template <typename Iter>
void print(Iter begin, Iter end){
	while(begin != end){
		std::cout << *begin << " ";
		begin++;
	}
	std::cout << std::endl;
}

int main(){
	std::vector<int> vec;

	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	std::vector<int>::iterator result = std::find(vec.begin(), vec.end(), 3);

	std::cout << std::distance(vec.begin(), result) +1 << std::endl;

	return 0;
}

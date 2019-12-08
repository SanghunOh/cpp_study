#include	<iostream>
#include	<vector>
#include	<string>
#include	<algorithm>
#include	<functional>

template <typename Iter>
void print(Iter begin, Iter end){
	while(begin != end){
		std::cout << *begin << std::endl;
		begin++;
	}
	std::cout << std::endl;
}

struct is_odd{
	bool operator()(const int& i){
		return (i % 2 == 1);
	}
};

int main(){
	std::vector<int> vec;

	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	std::cout << "first" << std::endl;
	print(vec.begin(), vec.end());

	std::cout << "remove odd" << std::endl;
	vec.erase(std::remove_if(vec.begin(), vec.end(), is_odd()), vec.end());

	print(vec.begin(), vec.end());

	return 0;
}

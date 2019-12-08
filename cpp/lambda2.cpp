#include	<iostream>
#include	<string>
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
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(4);

	std::cout << "first" << std::endl;

	print(vec.begin(), vec.end());

	std::cout << "remove 2 odd int" << std::endl;
	int num_odd = 0;
	vec.erase(std::remove_if(vec.begin(), vec.end(),
				[&num_odd](int i){
					if(num_odd >= 2)
						return false;
					else if(i%2 == 1){
						num_odd++;
						return true;
					}
					return false;
				}), vec.end());
	print(vec.begin(), vec.end());

	return 0;
}

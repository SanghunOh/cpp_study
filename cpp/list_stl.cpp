#include	<iostream>
#include	<list>

template <typename T>
void print_list(std::list<T>& lst){
	std::cout << "[" ;
	for(const auto& elem : lst){
		std::cout << elem << " ";
	}

	std::cout << "]" << std::endl;
}

int main(){
	std::list<int> lst;

	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);

	std::cout << "first" << std::endl;
	print_list(lst);

	for(std::list<int>::iterator itr = lst.begin() ; itr != lst.end() ; itr++){
		if(*itr == 20){
			lst.insert(itr, 50);
		}
	}

	print_list(lst);

	for(std::list<int>::iterator itr = lst.begin() ; itr!=lst.end() ; itr++){
		if(*itr == 300){
			lst.erase(itr);
		}
		break;
	}
	return 0;
}

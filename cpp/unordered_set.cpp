#include	<iostream>
#include	<string>
#include	<unordered_set>

template <typename K>
void print_unordered_set(std::unordered_set<K> & s){
	for(const auto& elem : s)
		std::cout << elem << " ";
	std::cout << std::endl;
}

int main(){
	std::unordered_set<std::string> s;

	s.insert("hi");
	s.insert("my");
	s.insert("name");
	s.insert("is");
	s.insert("poki");
	s.insert("welcome");
	s.insert("studying");
	s.insert("C++");

	print_unordered_set(s);

	return 0;
}

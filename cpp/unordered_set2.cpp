#include	<iostream>
#include	<string>
#include	<unordered_set>

template <typename K>
void print_unordered_set(std::unordered_set<K>& m){
	for(const auto elem : m)
		std::cout << elem << "  ";
	std::cout << std::endl;
}

template <typename K>
void is_exist(std::unordered_set<K>& s, K key){
	auto itr = s.find(key);

	if(itr != s.end())
		std::cout << key << " exists" << std::endl;
	else
		std::cout << key << " doesn't exist " << std::endl;
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

	std::cout << "-------------" << std::endl;
	is_exist(s, std::string("C++"));
	is_exist(s, std::string("C"));

	std::cout << "-------------" << std::endl;
	std::cout << "erase 'hi'" << std::endl;
	s.erase(s.find("hi"));
	is_exist(s, std::string("hi"));

	return 0;
}

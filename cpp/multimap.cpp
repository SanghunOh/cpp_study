#include	<iostream>
#include	<map>
#include	<string>

template <typename K, typename V>
void print_map(const std::multimap<K, V>& m){
	for(const auto& elem : m)
		std::cout << elem.first << " " << elem.second << std::endl;
}

int main(){
	std::multimap<int, std::string> m;

	m.insert(std::make_pair(1, "hello"));
	m.insert(std::make_pair(1, "hi"));
	m.insert(std::make_pair(1, "ahih"));
	m.insert(std::make_pair(2, "bye"));
	m.insert(std::make_pair(2, "baba"));

	print_map(m);


	auto range = m.equal_range(1);
	for(auto itr = range.first ; itr != range.second ; itr++)
		std::cout << itr->first << " : " << itr->second << " " << std::endl;
	
	
	return 0;
}

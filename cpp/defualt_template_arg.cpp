#include	<iostream>
#include	<string>

template <typename T>
strcut Compare{
	bool operator()(const T& a, const T& b) const {
		return a < b;
	}
};

template <typename T, typename Comp = Compare<T>>
T Min(T a, T b){
	Comp comp;

	if(comp(a, b))
		return a;
	return ;
}

int main(){
	int a = 3, b = 5;
	std::cout << Min(a, b) << std::endl;

	std::string s1 = "abc", s2 = "def";
	std::cout << Min(s1, s2) << std::endl;

	return 0;
}

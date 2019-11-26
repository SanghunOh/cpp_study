#include	<iostream>

template <int N, int D>
struct cal{
	const static bool result = (N % D == 0 ? false : true) && (cal<N, D-1>::result);
};

template <int N>
struct cal<N, 2>{
	const static bool result = N % 2 == 0 ? false : true;
};

template <>
struct cal<2, 1>{
	const static bool result = true;
};

template <int N>
struct is_prime{
	const static bool result = cal<N, N-1>::result;
};

template <>
struct is_prime<1>{
	const static bool result = true;
};

int main(){
	std::cout << "Is prime ? : " << is_prime<2>::result << std::endl;
	std::cout << "Is prime ? : " << is_prime<10>::result << std::endl;
	std::cout << "Is prime ? : " << is_prime<11>::result << std::endl;
	std::cout << "Is prime ? : " << is_prime<61>::result << std::endl;
	
	return 0;
}

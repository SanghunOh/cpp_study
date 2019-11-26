#include	<iostream>

template <int A, int B>
struct gcd{
	static const int result = gcd<B, A%B>::result;	
};

template <int A>
struct gcd<A, 0>{
	static const int result = A;
};

int main(){
	std::cout << gcd<36, 24>::result << std::endl;
}

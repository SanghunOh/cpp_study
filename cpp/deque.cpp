#include	<iostream>
#include	<deque>

template <typename T>
void print_deque(std::deque<T>& dq){
	for(const auto& elem : dq)
		std::cout << elem << std::endl;
}

int main(){
	std::deque<int> dq;

	dq.push_back(10);
	dq.push_back(20);
	dq.push_back(30);
	dq.push_back(40);

	print_deque(dq);

	dq.pop_front();
	print_deque(dq);

	return 0;
}

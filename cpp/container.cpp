#include	<iostream>
#include	<string>

template <typename T>
class Vector{
	T* data;
	int capacity;
	int length;

public:
	Vector(int n = 1) : data(new T[n]), capacity(n), length(0){}

	void push_back(int s){
		if(length >= capacity){
			T* temp = new T[capacity*2];
			for(int i=0 ; i<length ; i++)
				temp[i] = data[i];

			delete [] data;
			data = temp;
			capacity *= 2;
		}
		data[length++] = s;
	}

	T operator[](int i){
		return data[i];
	}

	void remove(int x){
		for(int i=x+1 ; i<length ; i++)
			data[i-1] = data[i];
		length--;
	}

	int size(){
		return length;
	}

	void swap(int i, int j){
		T temp = data[i];
		data[i] = data[j];
		data[j] = temp;
	}

	~Vector(){
		if(data)
			delete [] data;
	}
};

template <typename Cont>
void bubble_sort(Cont& cont){
	for(int i=0 ; i<cont.size() ; i++){
		for(int j=i+1 ; j<cont.size() ; j++){
			if(cont[i] > cont[j])
				cont.swap(i, j);
		}
	}
}

int main(){
	Vector<int> int_vec;
	int_vec.push_back(3);
	int_vec.push_back(9);
	int_vec.push_back(13);
	int_vec.push_back(35);
	int_vec.push_back(49);
	int_vec.push_back(26);
	int_vec.push_back(5);
	int_vec.push_back(5);
	int_vec.push_back(6);
	int_vec.push_back(4);
	int_vec.push_back(1);


	for(int i=0 ; i<int_vec.size() ; i++){
		std::cout << int_vec[i] << std::endl;
	}

	std::cout << std::endl;

	bubble_sort(int_vec);


	for(int i=0 ; i<int_vec.size() ; i++){
		std::cout << int_vec[i] << std::endl;
	}

	std::cout << std::endl;

	return 0;

}

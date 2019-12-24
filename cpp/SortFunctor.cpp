#include	<iostream>

class SortRule{
public:
	virtual bool operator()(int, int) const = 0;
};

class AscendingSort : public SortRule{
public:
	bool operator()(int num1, int num2) const {
		if(num1 < num2)
			return true;
		else
			return false;
	}
};

class DescendingSort : public SortRule{
public:
	bool operator()(int num1, int num2) const{
		if(num1 > num2)
			return true;
		else
			return false;
	}
};

class DataStorage{
private:
	int* arr;
	int idx;
	const int MAX_LEN;

public:
	DataStorage(int arrlen) : idx(0), MAX_LEN(arrlen){
		arr = new int[MAX_LEN];
	}

	void AddData(int num){
		if(MAX_LEN <= idx){
			std::cout << "impossible" << std::endl;
			return;
		}
		arr[idx++] = num;
	}

	void ShowAllData(){
		for(int i=0 ; i<idx ; i++){
			std::cout << arr[i] << " ";	
		}
		std::cout<< std::endl;
	}

	void SortData(const SortRule& functor){
		for(int i=0 ; i<MAX_LEN ; i++){
			for(int j=0 ; j<idx-1-i ; j++){
				if(functor(arr[i], arr[j])){
					int temp = arr[j];
					arr[j] = arr[i];
					arr[i] = temp;
				}
			}
		}
	}
};

int main(){
	DataStorage storage(5);
	storage.AddData(40);
	storage.AddData(30);
	storage.AddData(50);
	storage.AddData(10);
	storage.AddData(20);

	storage.SortData(AscendingSort());
	storage.ShowAllData();

	storage.SortData(DescendingSort());
	storage.ShowAllData();

	return 0;
}

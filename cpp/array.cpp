#include	<iostream>

class Array{
private:
	int* dim;
	int* arr;
	int dimension;
	int total_idx;

public:
	Array();
	Array(int* array_dim, int dim_num);
	Array(const Array& t);
	~Array();
};

Array::Array(){
	dim = NULL;
	arr = NULL;
}

Array::Array(int* array_dim, const int dim_num){
	total_idx = 1;
	dimension = dim_num;

	dim = new int [dimension];

	for(int i=0 ; i<dim_num ; i++){
		total_idx *= array_dim[i];
		dim[i] = array_dim[i];
	}

	arr = new int [total_idx];
}

Array::Array(const Array& t){
	dimension = t.dimension;
	total_idx = t.total_idx;

	if(dim)
		delete [] dim;
	if(arr)
		delete[] arr;

	dim = new int [dimension];
	arr = new int [total_idx];

	for(int i=0 ; i<dimension ; i++){
		dim[i] = t.dim[i];
	}

	for(int i=0 ; i<total_idx ; i++)
		arr[i] = t.arr[i];
}



int main(){
	
}

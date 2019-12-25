#ifndef __ARRAY_TEMPLATE_H_
#define __ARRAY_TEMPLATE_H_

#include	<iostream>
#include	<cstdlib>

template <typename T>
class BoundCheckArray{
private:
	T* arr;
	int len;

	BoundCheckArray(const BoundCheckArray& arr){}
	BoundCheckArray& operator=(const BoundCheckArray& arr){}

public:
	BoundCheckArray(int);
	~BoundCheckArray();

	T& operator[](int idx);
	T operator[](int idx) const;
	int GetArrLen() const;
};

template <typename T>
BoundCheckArray<T>::BoundCheckArray(int len) : len(len){
	arr = new T[len];	
}

template <typename T>
BoundCheckArray<T>::~BoundCheckArray(){
	delete [] arr;
}

template <typename T>
T& BoundCheckArray<T>::operator[](int idx){
	return arr[idx];
}

template <typename T>
T BoundCheckArray<T>::operator[](int idx) const{
	return arr[idx];
}

template <typename T>
int BoundCheckArray<T>::GetArrLen() const{
	return len;
}

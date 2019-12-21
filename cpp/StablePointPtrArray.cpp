#include	<iostream>
#include	<cstdlib>

class Point{
private:
	int xpos;
	int ypos;

public:
	Point(int x=0, int y=0) : xpos(x), ypos(y) {}
	friend std::ostream& operator<<(std::ostream& os, const Point& pos);
};

std::ostream& operator<<(std::ostream& os, const Point& pos){
	os << "[" << pos.xpos << ", " << pos.ypos << "]" << std::endl;

	return os;
}

class BoundCheckPointArray{
private:
	Point** arr;
	int arrlen;

	BoundCheckPointArray(const BoundCheckPointArray& arr){}
	BoundCheckPointArray& operator<<(const BoundCheckPointArray& arr){}

public:
	BoundCheckPointArray(int len) : arrlen(len){
		arr = new Point* [len];
	}

	Point*& operator[](int idx){
		if(idx <0 || idx>=arrlen){
			std::cout << "index error!" << std::endl;
			exit(1);
		}

		return arr[idx];
	}

	Point*& operator[](int idx) const{
		if(idx <0 || idx>=arrlen){
			std::cout << "index error!" << std::endl;
			exit(1);
		}

		return arr[idx];
	}

	int GetArrLen(){
		return arrlen;
	}

	~BoundCheckPointArray(){
		delete [] *arr;
	}	
};

int main(){
	BoundCheckPointArray parr(3);

	parr[0] = new Point(3, 4);
	parr[1] = new Point(5, 6);
	parr[2] = new Point(7, 8);

	for(int i=0 ; i<parr.GetArrLen() ; i++){
		std::cout << *(parr[i]);
	}

	for(int i=0 ; i<3 ; i++)
		delete parr[i];

	return 0;

}

#include	<iostream>

class Point{
private:
	int xpos;
	int ypos;

public:
	Point(int x=0, int y=0) : xpos(x), ypos(y) {
		std::cout << "constructor" << std::endl;
	}
	~Point(){
		std::cout << "destructor" << std::endl;
	}

	friend std::ostream& operator<<(std::ostream& os, const Point& pos);

	void* operator new(size_t size){
		std::cout << "operator new : " << size << std::endl;
		void* adr = new char[size];
		return adr;
	}

	void operator delete(void* adr){
		std::cout << "operator delete() " << std::endl;
		delete [] ((char*)adr);
	}
};

std::ostream& operator<<(std::ostream& os, const Point& pos){
	os << "[" << pos.xpos << ", " << pos.ypos << "]" << std::endl;
	return os;
}

int main(){
	Point* ptr = new Point(4, 3);
	std::cout << *ptr;
	delete ptr;
	return 0;
}

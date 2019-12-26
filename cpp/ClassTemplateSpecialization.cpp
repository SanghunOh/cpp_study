#include	<iostream>
#include	<cstring>

template <typename T>
class Point{
private:
	T xpos;
	T ypos;

public:
	Point(T xpos, T ypos) : xpos(xpos), ypos(ypos){}
	void ShowPosition() const{
		std::cout << "[" << xpos << ", " << ypos << "]" << std::endl;
	}
};

template <typename T>
class SimpleDataWrapper{
private:
	T mdata;

public:
	SimpleDataWrapper(T data) : mdata(data){}

	void ShowDataInfo(){
		std::cout << "Data : " << mdata << std::endl;
	}
};

template <>
class SimpleDataWrapper <char*>{
private:
	char* mdata;

public:
	SimpleDataWrapper(char* data){
		mdata = new char[strlen(data) + 1];
		strcpy(mdata, data);
	}

	void ShowDataInfo(){
		std::cout << "String : " << mdata << std::endl;
		std::cout << "Length : " << strlen(mdata) << std::endl;
	}

	~SimpleDataWrapper(){
		delete [] mdata;
	}
};

template <>
class SimpleDataWrapper <Point<int>>{
private:
	Point<int> mdata;

public:
	SimpleDataWrapper(int x, int y) : mdata(x, y) {}

	void ShowDataInfo(){
		mdata.ShowPosition();
	}
};

int main(){
	SimpleDataWrapper<int> iwrap(140);
	iwrap.ShowDataInfo();
	SimpleDataWrapper<char*> swrap("Class Template Specialization");
	swrap.ShowDataInfo();
	SimpleDataWrapper<Point<int>> poswrap(3, 5);
	poswrap.ShowDataInfo();

	return 0;
}

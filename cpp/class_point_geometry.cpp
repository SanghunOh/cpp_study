#include	<iostream>
using namespace std;

class Point{
private:
	int x;
	int y;

public:
	Point(int pos_x, int pos_y);
};

class Geometry{
private:
	Point** point_array;

public:
	Geometry();
	Geometry(Point** point_list);

	void Add_Point(const Point& point);
	void Print_Distance();
	void Print_Num_Meets();
};

Point::Point(int pos_x, int pos_y){
	x = pos_x;
	y = pos_y;
}

Geometry::Geometry(){
	
}

Geometry::Geometry(Point** point_list){
	
}

Geometry::Add_Point(const Point& point){
	
}

Geometry::Print_Distance(){

}

Geometry::Print_Num_Meets(){

}

int main(){
	
	return 0;	
}

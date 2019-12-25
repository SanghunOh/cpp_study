#include	<iostream>
#include	"Point.h"
#include	"ArrayTemplate.h"

int main(){
	BoundCheckArray<int> iarr(5);

	for(int i=0 ; i<5 ; i++)
		iarr[i] = (i+1)*11;

	for(int i=0 ; i<5 ; i++)
		std::cout << iarr[i];

	BoundCheckArray<Point> oarr(3);
	oarr[0] = Point(3, 4);
	oarr[1] = Point(1, 2);
	oarr[2] = Point(5, 6);

	for(int i=0 ; i<3 ; i++)
		std::cout << oarr[i];

	BoundCheckArray<Point*> parr(3);
	parr[0] = new Point(3, 4);
	parr[1] = new Point(1, 2);
	parr[2] = new Point(5, 6);

	for(int i=0 ; i<3 ; i++)
		std::cout << parr[i];

	for(int i=0 ; i<3 ; i++)
		delete [] parr[i];


	return 0;
}

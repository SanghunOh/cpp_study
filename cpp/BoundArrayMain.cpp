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

	BoundCheckArray<Point<int>> oarr1(3);
	oarr1[0] = Point<int>(3, 4);
	oarr1[1] = Point<int>(1, 2);
	oarr1[2] = Point<int>(5, 6);

	for(int i=0 ; i<oarr1.GetArrLen() ; i++)
		oarr[i].ShowPosition();

	BoundCheckArray<Point<double>> oarr2(3);
	oarr2[0] = Point<double>(3.1, 4.1);
	oarr2[1] = Point<double>(1.1, 2.1);
	oarr2[2] = Point<double>(5.1, 6.1);

	for(int i=0 ; i<oarr2.GetArrLen() ; i++)
		oarr[i].ShowPosition();

	typedef Point<int>* POINT_PTR;
	BoundChecKArray<POINT_PTR> oparr(3);

	oparr[0] = new Point<int>(11, 12);
	oparr[1] = new Point<int>(13, 14);
	oparr[2] = new Point<int>(15, 16);

	for(int i=0 ; i<oparr.GetArrLen() ; i++)
		oparr[i]->ShowPosition();

	delete oparr[0];
	delete oparr[1];
	delete oparr[2];

	return 0;
}

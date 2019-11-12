#include	<iostream>
using namespace std;

class A{
	int x;

public:
	A(int c): x(c){}
	A(const A& a){
		x = a.x;
		cout << "복사 생성" << endl;
	}
};

class B{
	A a;

public:
	B(int c) : a(c) {}
	B(const B& b) : a(b.a) {}
	A get_A(){
		A temp(a);
		return temp;
	}
};

int main(){
	B b(10);

	cout << "---------" << endl;
	A al = b.get_A();

	return 0;
}

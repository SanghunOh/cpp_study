#include	<iostream>
#include	<string>
using namespace std;

struct student{
	int id;
	char name[10];
};

int main(){
	student* s = new student;
	int* t = new int[10];

	s->id = 1;
	strcpy(s->name, "asdf");

	cout << "id: "<< s->id << ", name: " << s->name << endl;

	for(int i=0 ; i<10 ; i++)
		t[i] = i;

	for(int j=0 ; j<10 ; j++)
		cout << t[j] << endl;

	delete s;
	delete [] t;
	return 0;
}

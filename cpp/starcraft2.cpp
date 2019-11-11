#include	<iostream>
#include	<string.h>
using namespace std;

class Marine{
	int hp;
	int coord_x;
	int coord_y;
	int damage;
	bool is_dead;
	char* name;

public:
	Marine();
	Marine(int, int, const char*);
	Marine(int x, int y);
	~Marine();
	
	int attack();
	void be_attacked(int);
	void move(int, int);
	void show_status();	
};

Marine::Marine()
	: hp(50), coord_x(0), coord_y(0), damage(5), is_dead(false), name(NULL) {}
	//initializer list!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

Marine::Marine(int x, int y)
	: hp(50), coord_x(x), coord_y(y), damage(5), is_dead(false), name(NULL) {}

Marine::Marine(int x, int y, const char* _name){
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);

	hp = 50;
	coord_x = x;
	coord_y = y;
	damage = 5;
	is_dead = false;
}

Marine::~Marine(){
	cout << "call destructor of " << name << endl;
	if(name)
		delete [] name;
}

void Marine::move(int x, int y){
	coord_x = x;
	coord_y = y;
}

int Marine::attack(){
	return damage;
}

void Marine::be_attacked(int damage_earn){
	if(hp <= damage_earn){
		hp = 0;
		is_dead = true;
	}
	else
		hp -= damage_earn;
}

void Marine::show_status(){
	cout << " *** Marine : " << name << " ***" << endl;
	cout << "Hp: " << hp << endl;
	cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << endl;
}

int main(){
	Marine* marines[100];

	marines[0] = new Marine(2, 3, "marine1");
	marines[1] = new Marine(3, 5, "marine2");

	marines[0]->show_status();
	marines[1]->show_status();

	cout << endl << "marine1 attacked marine2! " << endl;

	marines[1]->be_attacked(marines[0]->attack());

	marines[0]->show_status();
	marines[1]->show_status();

	delete marines[0];
	delete marines[1];
}

#include	<iostream>
#include	<string.h>
using namespace std;

class Photon_Cannon{
private:
	int hp, shield;
	int coord_x, coord_y;
	int damage;

	char* name;

public:
	Photon_Cannon();
	Photon_Cannon(int, int);
	Photon_Cannon(int, int, const char*);
	Photon_Cannon(const Photon_Cannon& pc);
	~Photon_Cannon();
	
	void show_status();
};

Photon_Cannon::Photon_Cannon(int x, int y){
	cout << "생성자 호출 ! " << endl;
	hp = 100;
	shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;

	name = NULL;
}

Photon_Cannon::Photon_Cannon(int x, int y, const char* _name){
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;

	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
}

Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc){
	cout << "복사 생성자 호출 ! " << endl;
	hp = pc.hp;
	shield = pc.shield;
	coord_x = pc.coord_x;
	coord_y = pc.coord_y;
	damage = pc.damage;

	if(pc.name){
		name = new char[strlen(pc.name) + 1];
		strcpy(name, pc.name);
	}
	else 
		name = NULL;
}

Photon_Cannon::~Photon_Cannon(){
	if(name)
		delete [] name;
}

void Photon_Cannon::show_status(){
	cout << "Photon Cannon" << endl;
	cout << "Location : ( " << coord_x << " , " << coord_y << " )" << endl;
	cout << "HP : " << hp << endl;
}

int main(){
	Photon_Cannon pc1(3, 3);
	Photon_Cannon pc2(pc1);
	Photon_Cannon pc3 = pc2;

	pc1.show_status();
	pc2.show_status();

	return 0;
}

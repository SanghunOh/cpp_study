#include	<iostream>

class Marine{
	static int total_marine_num;
	const static int i=0;

	int hp;
	int coord_x, coord_y;
	bool is_dead;

	const int default_damage;

public:
	Marine();
	Marine(int, int);
	Marine(int, int, int);

	int attack();
	void be_attacked(int);
	void move(int, int);
	void show_status();
	
	static void show_total_marine(); 	//static함수 선언 방법

	~Marine(){total_marine_num--;};
};

int Marine::total_marine_num = 0; // class 내의 static변수 초기화 방법

void Marine::show_total_marine(){	// 선언할 때에는 static 안 씀
//	std:: cout << default_damage << endl;  어느 객체의 default_damage인지 모르므로 컴파일 오류!
	std::cout << "totla Marine: " << total_marine_num << std::endl;
}

Marine::Marine()
	:hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false){
	total_marine_num++;
}

Marine::Marine(int x, int y, int default_damage)
	:coord_x(x), coord_y(y), hp(50), default_damage(default_damage), is_dead(false){
	total_marine_num++;	
}

void Marine::move(int x, int y){
	coord_x = x;
	coord_y = y;
}

int Marine::attack(){return default_damage; }

void Marine::be_attacked(int damage_earn){
	hp -= damage_earn;
	if(hp <= 0)
		is_dead = true;
}

void Marine::show_status(){
	std::cout << "Marine" << std::endl;
	std::cout << "(" << coord_x << ", " << coord_y << ")" << std::endl;
	std::cout << "HP: " << hp << std::endl;
	std::cout << "total: " << total_marine_num << std::endl;
}

void create_marine(){
	Marine marine3(10, 10, 4);
	marine3.show_total_marine();
}

int main(){
	Marine marine1(2, 3, 5);
	marine1.show_total_marine();

	Marine marine2(3, 5, 10);
	marine2.show_total_marine();

	create_marine();

	std::cout << std::endl << "marine1 -> marine2" << std::endl;
	marine2.be_attacked(marine1.attack());

	marine1.show_status();
	marine2.show_status();

	return 0;
}

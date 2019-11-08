#include	<iostream>
using namespace std;

typedef struct {
	char name[30];
	int age;
	int health;
	int food;
	int clean;
}Animal;

void create_animal(Animal* animal){
	cout << "name? : ";
	cin >> animal->name;

	animal->health = 100;
	animal->food = 100;
	animal->clean = 100;	
}

void play(Animal* animal){
	animal->health += 10;
	animal->food -= 30;
	animal->clean -= 20;
}

void one_day_pass(Animal* animal){
	animal->health -= 10;
	animal->food -= 30;
	animal->clean -= 20;
}

void show_stat(Animal* animal){
	cout << animal->name << "의 상태" << endl;
	cout << "체력	: " << animal->health << endl;
	cout << "배부름 : " << animal->food << endl;
	cout << "청결	: " << animal->clean << endl;
}


int main(){
	Animal* list[30];
	int animal_num = 0;

	for( ; ; ){
		cout << "1. add" << endl;
		cout << "2. play" << endl;
		cout << "3. print" << endl;

		int input;
		cin >> input;

		switch(input){
			int play_with;
			case 1:
				list[animal_num] = new Animal;
				create_animal(list[animal_num]);
				animal_num++;
				break;

			case 2:
				cout << "play with whom? : ";
				cin >> play_with;
				if(play_with < animal_num)
					play(list[play_with]);
				break;

			case 3:
				cout << "which one do you want to see? ; ";
				cin >> play_with;
				if(play_with < animal_num)
					show_stat(list[play_with]);
				break;

		}

		for(int i=0 ; i != animal_num ; i++)
			one_day_pass(list[i]);

	}

	for(int i=0 ; i != animal_num ; i++){
		delete list[i];
	}

	return 0;
}

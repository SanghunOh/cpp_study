#include	<iostream>
#include	<cstring>
using namespace std;

class Computer{
private:
	char owner[50];

public:
	Computer(char* name){
		strcpy(owner, name);
	}

	void Calculate(){
		cout << "요청 내용을 계산합니다." << endl;
	}
};

class NoteBookComp : public Computer{
private:
	int Battery;

public:
	NoteBookComp(char* name, int initChag)
		:Computer(name), Battery(initChag) {}

	void Charing(){ Battery += 5;}
	void UseBattery(){ Battery -= 5; }
	void MovingCal(){
		if(GetBatteryInfo() < 1){
			cout << "충전이 필요합니다." << endl;
			return;
		}

		cout << "이동하면서 ";
		Calculate();
		UseBattery();
	}

	int GetBatteryInfo(){
		return Battery;
	}
};

class TableNotebook : public NoteBookComp{
private:
	char regstPenModel[50];

public:
	TableNotebook(char* name, int initChag, char* pen)
		: NoteBookComp(name, initChag){
		strcpy(regstPenModel, pen);
	}

	void Write(char* penInfo){
		if(GetBatteryInfo() < 1){
			cout << "충전이 필요합니다." << endl;
			return;
		}

		if(strcmp(regstPenModel, penInfo) != 0){
			cout << "등록된 펜이 아닙니다.";
			return;
		}

		cout << "필기 내용을 처리합니다." << endl;
		UseBattery();
	}
};

int main(){
	NoteBookComp nc("poki" , 5);
	TableNotebook tn("kipo", 5, "ISE-241-242");

	nc.MovingCal();
	tn.Write("ISE-241-242");

	return 0;
}

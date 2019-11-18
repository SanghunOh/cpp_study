#include	<iostream>
#include	<string>

class Human{
public:
	string name;
};

//class HandsomeHuman : public Human{	//
class HandsomeHuman : public virtual Human{
public;
};

//class SmartHuman : public Human{	//이렇게 하면 Me에서 name이 어떤 class의 name인지 모름
class SmartHuman : public virtual Human{
public:
};

class Me : public HandsomeHuman, public SmartHuman{

}

int main(){
	

	return 0;
}

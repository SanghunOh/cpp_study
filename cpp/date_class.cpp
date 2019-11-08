#include	<iostream>
using namespace std;

class Date{
private:
	int year;
	int month;
	int day;

public:
	void set_date(int _year, int _month, int _day){
		year = _year;
		month = _month;
		day = _day;
	}

	void add_day(int inc){
		int is_yoon;
		is_yoon = (year % 4) && (year % 400) && !(year % 100);

		if(month == 2){
			if(!is_yoon){
				if(day + inc > 29){
					day = day + inc -29;
					add_month(1);
				}
				else
					day += inc;
			}
			else{
				if(day + inc > 28){
					day = day + inc - 28;
					add_month(1);
				}
				else
					day += inc;
			}
		}
		else if(month % 2){
			if(day + inc > 31){
				day = day + inc - 31;
				add_month(1);
			}
			else{
				day += inc;
			}
		}
		else {
			if(day + inc > 30){
				day = day + inc - 30;
				add_month(1);
			}
			else
				day += inc;
		}
	}

	void add_month(int inc){
		if(month + inc > 12){
			month = month + inc - 12;
			add_year(1);
		}
		else
			month += inc;
	}

	void add_year(int inc){
		year += year;
	}

	void get_date(){
		cout << "Date : " << year << " / " << month << " / " << day << endl;
	}
};


int main(){
	Date date;
	return 0;
}

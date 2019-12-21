#include	<iostream>

namespace mystd{
	class Ostream{
	public:
		void operator<<(char* str){
			printf("%s\n", str);
		}

		void operator<<(char c){
			printf("%c\n", c);
		}

		void operator<<(int num){
			pritnf("%d\n", num);
		}

		void operator<<(double e){
			printf("%f\n", e);
		}

		void operator<<(Ostream&(*fp)(Ostream& ostm)){
			fp(*this);
		}
	};
}

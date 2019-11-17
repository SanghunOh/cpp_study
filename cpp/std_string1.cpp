#include	<iostream>
#include	<string>
using namespace std;

int main(){
	string s = "abc";
	string t = "def";
	string s2 = s;

	cout << s << "의 길이 : " << s.length() << endl;
	cout << s << "뒤에 " << t << "를 붙이면 : " << s + t << endl;

	if(s == s2)
		cout << s << " = " << s2 << endl;
	if(s != t)
		cout << s << " != " << t << endl;


	return 0;
}

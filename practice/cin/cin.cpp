#include <iostream>
#include <string>
using namespace std;

int main(){
	int a = 0;
	cout << "please assign a value to a" << endl;
	cin >> a;
	cout << "a(int) = " << a << endl;
	float f = 3.14f;
	cout << "please assign a value to f" << endl;
	cin >> f;
	cout << "f(float) = " << f << endl;
	char ch = 'a';
	cout << "please assign a value to ch" << endl;
	cin >> ch;
	cout << "ch(char) = " << ch << endl;
	string str = "hello";
	cout << "please assign a value to str" << endl;
	cin >> str;
	cout << "str(string) = " << str << endl;
	bool flag = false;
	cout << "please assign a value to flag" << endl;
	cin >> flag;
	cout << "flag(bool) = " << flag << endl;
	return 0;
}

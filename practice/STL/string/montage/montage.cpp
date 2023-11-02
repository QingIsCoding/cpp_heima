#include <iostream>
#include <string>
using namespace std;

void test01()
{
	string str1 = "I";
	str1 += " like playing computer games";
	cout << "str1:" << str1 << endl;
	str1 += ":";
	cout << "str1:" << str1 << endl;

	string str2 = "LOL and DNF";
	str1 += str2;
	cout << "str1:" << str1 << endl;

	string str3 = "I";
	str3.append(" love ");
	cout << "str3:" << str3 << endl;

	str3.append("game:abcde", 5);
	cout << "str3:" << str3 << endl;
	string str4 = str3;
	string str5 = str3;

	str3.append(str2);
	cout << "str3:" << str3 << endl;

	str4.append(str2, 0, 3);
	cout << "str4:" << str4 << endl;

	str5.append(str2, 8, 3);
	cout << "str5:" << str5 << endl;
}

int main()
{
	test01();
	return 0;
}

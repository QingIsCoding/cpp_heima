#include <iostream>
#include <string>
using namespace std;

void test01()
{
	string str1 = "abd";
	string str2 = "abc";
	if(str1.compare(str2) == 0)
	{
		cout << "str1 = str2" << endl;
	}
	else if(str1.compare(str2) > 0)
	{
		cout << "str1 > str2" << endl;
	}
	else
	{
		cout << "str1 < str2" << endl;
	}

	if(str2.compare(str1) == 0)
	{
		cout << "str2 = str1" << endl;
	}
	else if(str2.compare(str1) > 0)
	{
		cout << "str2 > str1" << endl;
	}
	else
	{
		cout << "str2 < str1" << endl;
	}

	string str3 = "abc";
	string str4 = "abc";
	if(str3.compare(str4) == 0)
	{
		cout << "str3 = str4" << endl;
	}
	else if(str3.compare(str4) > 0)
	{
		cout << "str3 > str4" << endl;
	}
	else
	{
		cout << "str3 < str4" << endl;
	}
}

int main()
{
	test01();
	return 0;
}

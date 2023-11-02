#include <iostream>
#include <string>
using namespace std;

void test01()
{
	string str = "abcdef";
	cout << "str: " << str << endl;

	string sub_str = str.substr(1, 3);
	cout << "sub_str: " << sub_str << endl;
}

void test02()
{
	string email = "zhangsan@sina.com";
	int pos = email.find("@");
	cout << "pos: " << pos << endl;
	string user_name = email.substr(0, pos);
	cout << "user_name: " << user_name << endl;
}

int main()
{
	test01();
	cout << endl;
	test02();
	return 0;
}

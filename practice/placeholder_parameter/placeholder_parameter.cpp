#include <iostream>
using namespace std;

void func1(int a)
{
	cout << "this is func1" << endl;
}

void func2(int a, int)
{
	cout << "this is func2" << endl;
}

void func3(int a, int = 10)
{
	cout << "this is func3" << endl;
}

int main()
{
	func1(10);
	func2(10, 10);
	func3(10);
	return 0;
}

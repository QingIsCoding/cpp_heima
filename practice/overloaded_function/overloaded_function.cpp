#include <iostream>
using namespace std;

void func()
{
	cout << "this is func()" << endl;
}

void func(int a)
{
	cout << "this is func(int a)" << endl;
}

void func(double a)
{
	cout << "this is func(double a)" << endl;
}

void func(int a, double b)
{
	cout << "this is func(int a, double b)" << endl;
}

void func(double a, int b)
{
	cout << "this is func(double a, int b)" << endl;
}

void fun1(int&a)
{
	cout << "this is fun1(int&a)" << endl;
}

void fun1(const int&a)
{
	cout << "this is fun1(const int&a)" << endl;
}

void fun2(int a, int b = 10)
{
	cout << "this is fun2(int a, int b = 10)" << endl;
}

/*void fun2(int a)
{
	cout << "this is fun2(int a)" << endl;
}*/

int main()
{
	func();
	func(10);
	func(3.14);
	func(10, 3.14);
	func(3.14, 10);	
	int a = 10;
	fun1(a);
	fun1(10);
	fun2(10);
	return 0;
}

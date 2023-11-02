#include <iostream>
using namespace std;

void SwapInt(int&a, int&b)
{
	int temp = a;
	a = b;
	b = temp;
}

void SwapDouble(double&a, double&b)
{
	double temp = a;
	a = b;
	b = temp;
}

template<typename T>
void Swap(T&a, T&b)
{
	T temp = a;
	a = b;
	b = temp;
}

void test01()
{
	int a = 10;
	int b = 20;
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	//SwapInt(a, b);
	Swap(a, b);
	cout << "after swap" << endl;
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	cout << endl;

	double c = 1.1;
	double d = 2.2;
	cout << "c: " << c << endl;
	cout << "d: " << d << endl;
	//SwapDouble(c, d);
	Swap<double>(c, d);
	cout << "after swap" << endl;
	cout << "c: " << c << endl;
	cout << "d: " << d << endl;
}

int main()
{
	test01();
	return 0;
}

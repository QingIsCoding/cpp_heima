#include <iostream>
using namespace std;

int Add01(int a, int b)
{
	return a+b;
}

template<typename T>
T Add02(T a, T b)
{
	return a+b;
}

void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	cout << "Add01(a, b): " << Add01(a, b) << endl;
	cout << "Add01(a, c): " << Add01(a, c) << endl;
}

void test02()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	cout << "Add02(a, b): " << Add02(a, b) << endl;
	//cout << "Add02(a, c): " << Add02(a, c) << endl; error
	cout << "Add02<int>(a, c): " << Add02<int>(a, c) << endl;
}

int main()
{
	test01();
	test02();
	return 0;
}

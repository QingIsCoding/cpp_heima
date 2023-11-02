#include <iostream>
using namespace std;

void Print(int a, int b)
{
	cout << "Print(int a, int b)" << endl;
}

template<typename T>
void Print(T a, T b)
{
	cout << "Print(T a, T b)" << endl;
}

template<typename T>
void Print(T a, T b, T c)
{
	cout << "Print(T a, T b, T c)" << endl;
}

void test01()
{
	int a = 10;
	int b = 10;

	Print(a, b);
	Print<>(a, b);
	Print(a, b, 100);

	char c1 = 'a';
	char c2 = 'b';
	Print(c1, c2);
}

int main()
{
	test01();
	return 0;
}

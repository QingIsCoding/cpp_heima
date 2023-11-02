#include <iostream>
#include <string>
using namespace std;

class MyAdd
{
	public:
		int operator()(int v1, int v2)
		{
			return v1+v2;
		}
};

void test01()
{
	MyAdd my_add;
	cout << "my_add(10, 10): " << my_add(10, 10) << endl;
}

class MyPrint
{
	public:
		int count;

		MyPrint()
		{
			this->count = 0;
		}

		void operator()(string test)
		{
			cout << "test: " << test << endl;
			this->count++;
		}
};

void test02()
{
	MyPrint my_print;//count = 0
	my_print("hello world");//count = 1
	my_print("hello world");//count = 2
	my_print("hello world");//count = 3
	my_print("hello world");//count = 4
	cout << "my_print.count: " << my_print.count << endl;
}

void DoPrint(MyPrint&mp, string test)
{
	mp(test);
}

void test03()
{
	MyPrint my_print;
	DoPrint(my_print, "hello c++");
}

int main()
{
	test01();
	cout << endl;
	test02();
	cout << endl;
	test03();
	return 0;
}

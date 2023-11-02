#include <iostream>
#include <string>
using namespace std;

class MyPrint1
{
	public:
		void operator()(string test)
		{
			cout << test << endl;
		}
};

class MyAdd
{
	public:
		int operator()(int num1, int num2)
		{
			return num1+num2;
		}
};

void MyPrint2(string test)
{
	cout << test << endl;
}

void test01()
{
	MyPrint1 myprint1;
	myprint1("hello world");
	MyPrint2("hello world");
}

void test02()
{
	MyAdd myadd;
	int ret = myadd(100, 100);
	cout << "ret = " << ret << endl;

	cout << MyAdd()(100, 100) << endl;
}

int main()
{
	test01();
	cout << endl;
	test02();
	return 0;
}

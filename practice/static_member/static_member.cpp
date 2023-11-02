#include <iostream>
using namespace std;

class Person
{
	public:
		static int m_a;
		static void func()
		{
			cout << "static void func" << endl;
		}
	private:
		static int m_b;
		static void func2()
		{
			cout << "static void func2" << endl;
		}
};

int Person::m_a = 100;
int Person::m_b = 1000;

//variable
void test01()
{
	Person p;
	cout << p.m_a << endl;
	Person p2;
	p2.m_a = 200;
	cout << p.m_a << endl;
	//cout << p.m_b << endl;
}

void test02()
{
	Person p;
	cout << p.m_a << endl;
}

void test03()
{
	cout << Person::m_a << endl;
}

//function
void test04()
{
	Person p;
	p.func();
}

void test05()
{
	Person::func();
}

/*void test06()
{
	Person::func2();
}*/

int main()
{
	test01();
	cout << endl;
	test02();
	cout << endl;
	test03();
	cout << endl;
	test04();
	cout << endl;
	test05();
	cout << endl;
	//test06();
	return 0;
}

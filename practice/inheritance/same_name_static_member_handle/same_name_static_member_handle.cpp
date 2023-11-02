#include <iostream>
using namespace std;

class Base
{
	public:
		static int m_a;

		static void func()
		{
			cout << "Base::static void func()" << endl;
		}

		static void func(int a)
		{
			cout << "Base::static void func(int a)" << endl;
		}
};

int Base::m_a = 100;

class Son : public Base
{
	public:
		static int m_a;

		static void func()
		{
			cout << "Son::static void func()" << endl;
		}
};

int Son::m_a = 200;

void test01()
{
	Son s;
	cout << "Son::m_a: " << s.m_a << endl;
	cout << "Base::m_a: " << s.Base::m_a << endl;
	cout << "Son::m_a: " << Son::m_a << endl;
	cout << "Son::Base::m_a: " << Son::Base::m_a << endl;//class name: Son, function field: Base
}

void test02()
{
	Son s;
	s.func();
	s.Base::func();
	Son::func();
	Son::Base::func();//class name: Son, function field: Base
	Son::Base::func(100);//class name: Son, function field: Base

}

int main()
{
	test01();
	cout << endl;
	test02();
	return 0;
}

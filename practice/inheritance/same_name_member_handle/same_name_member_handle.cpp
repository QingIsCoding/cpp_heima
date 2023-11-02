#include <iostream>
using namespace std;

class Base
{
	public:
		int m_a;

		Base()
		{
			m_a = 100;
		}

		void func()
		{
			cout << "Base::func()" << endl;
		}

		void func(int a)
		{
			cout << "Base::func(int a)" << endl;
		}
};

class Son : public Base
{
	public:
		int m_a;

		Son()
		{
			m_a = 200;
		}

		void func()
		{
			cout << "Son::func()" << endl;
		}
};

void test01()
{
	Son s;
	cout << "Son::m_a: " << s.m_a << endl;
	cout << "Base::m_a: " << s.Base::m_a << endl;
}

void test02()
{
	Son s;
	s.func();
	s.Base::func();
	s.Base::func(100);
}

int main()
{
	test01();
	cout << endl;
	test02();
	return 0;
}

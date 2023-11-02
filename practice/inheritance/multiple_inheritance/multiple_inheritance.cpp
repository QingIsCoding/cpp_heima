#include <iostream>
using namespace std;

class Base1
{
	public:
		int m_a;

		Base1()
		{
			m_a = 100;
		}
};

class Base2
{
	public:
		int m_a;

		Base2()
		{
			m_a = 200;
		}
};

class Son : public Base1, public Base2
{
	public:
		int m_c;
		int m_d;
		
		Son()
		{
			m_c = 300;
			m_d = 400;
		}
};

void test01()
{
	Son s;
	cout << "sizeof(s): " << sizeof(s) << endl;
	cout << "Base1::m_a: " << s.Base1::m_a << endl;
	cout << "Base2::m_a: " << s.Base2::m_a << endl;
}

int main()
{
	test01();
	return 0;
}

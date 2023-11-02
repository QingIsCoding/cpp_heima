#include <iostream>
using namespace std;

class Person
{
	public:
		Person()
		{

		}

		void ShowPerson() const
		{
			//m_a = 100; error, const Person*const this
			//this = NULL; error
			this->m_b = 100;
		}

		void func()
		{
			m_a = 100;
		}

		int m_a;
		mutable int m_b;
};

void test01()
{
	Person p;
	p.ShowPerson();
}

void test02()
{
	const Person p;
	//p.m_a = 100; error
	p.m_b = 100;
	p.ShowPerson();
	//p.func(); error
}

int main()
{
	test01();
	test02();
	return 0;
}

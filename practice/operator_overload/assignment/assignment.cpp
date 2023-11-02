#include <iostream>
using namespace std;

class Person
{
	public:
		int*m_age;
		
		Person(int age)
		{
			m_age = new int(age);
		}

		~Person()
		{
			if(m_age != NULL)
			{
				delete m_age;
				m_age = NULL;
			}
		}

		Person&operator=(Person&p)
		{
			if(m_age != NULL)
			{
				delete m_age;
				m_age = NULL;
			}

			m_age = new int(*p.m_age);
			return *this;
		}
};

void test01()
{
	Person p1(18);
	cout << "the age of p1: " << *p1.m_age << endl;
	Person p2(20);
	cout << "the age of p2: " << *p2.m_age << endl;

	cout << endl;
	p2 = p1;
	cout << "the age of p1: " << *p1.m_age << endl;
	cout << "the age of p2: " << *p2.m_age << endl;

	cout << endl;
	Person p11(10);
	Person p22(20);
	Person p33(30);
	p33 = p22 = p11;
	cout << "the age of p11: " << *p11.m_age << endl;
	cout << "the age of p22: " << *p22.m_age << endl;
	cout << "the age of p33: " << *p33.m_age << endl;
}

int main()
{
	test01();
	cout << endl;
	int a = 10;
	int b = 20;
	int c = 30;
	c = b = a;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	return 0;
}

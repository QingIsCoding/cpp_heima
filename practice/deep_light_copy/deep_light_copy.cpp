#include <iostream>
using namespace std;

class Person
{
	public:
		Person()
		{
			cout << "Person::constructor(no parameter)" << endl;
		}

		Person(int age, int height)
		{
			m_age = age;
			m_height = new int(height);
			cout << "Person::constructor(with parameter)" << endl;
		}

		Person(const Person&p)
		{
			cout << "Person::constructor(copy)" << endl;
			m_age = p.m_age;
			//m_height = p.m_height;
			m_height = new int(*p.m_height);
		}

		~Person()
		{
			if(m_height != NULL)
			{
				delete m_height;
				m_height = NULL;
			}
			cout << "Person::destructor" << endl;
		}

		int m_age;
		int*m_height;
};

void test01()
{
	Person p1(18, 160);
	cout << "the age of p1: " << p1.m_age << "\tthe height of p1: " << *p1.m_height << endl;
	Person p2(p1);
	cout << "the age of p2: " << p2.m_age << "\tthe height of p2: " << *p2.m_height << endl;
}

int main()
{
	test01();
	return 0;
}

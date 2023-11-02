#include <iostream>
using namespace std;

class Person
{
	public:
		string m_name;
		int m_age;

		Person(string name, int age)
		{
			m_name = name;
			m_age = age;
		}

		bool operator==(Person&p)
		{
			if(this->m_name==p.m_name && this->m_age==p.m_age)
			{
				return true;
			}
			return false;
		}

		bool operator!=(Person&p)
		{
			if(this->m_name!=p.m_name || this->m_age!=p.m_age)
			{
				return true;
			}
			return false;
		}
};

void test01()
{
	Person p1("Tom", 18);
	Person p2("Tom", 18);
	if(p1 == p2)
	{
		cout << "p1 == p2" << endl;
	}
	else
	{
		cout << "p1 != p2" << endl;
	}

	Person p3("Tom", 18);
	Person p4("Jerry", 18);
	if(p3 == p4)
	{
		cout << "p3 == p4" << endl;
	}
	else
	{
		cout << "p3 != p4" << endl;
	}

	Person p5("Tom", 18);
	Person p6("Jerry", 18);
	if(p5 != p6)
	{
		cout << "p5 != p6" << endl;
	}
	else
	{
		cout << "p5 == p6" << endl;
	}
}

int main()
{
	test01();
	return 0;
}

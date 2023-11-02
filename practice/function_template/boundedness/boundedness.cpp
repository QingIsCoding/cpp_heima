#include <iostream>
#include <string>
using namespace std;

class Person
{
	public:
		string m_name;
		int m_age;

		Person(string name, int age)
		{
			this->m_name = name;
			this->m_age = age;
		}
};

template<class T>
bool Compare(T&a, T&b)
{
	if(a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<> bool Compare(Person&p1, Person&p2)
{
	if(p1.m_name==p2.m_name && p1.m_age==p2.m_age)
	{
		return  true;
	}
	else
	{
		return  false;
	}
}

void test01()
{
	int a = 10;
	int b = 20;
	bool ret = Compare(a, b);
	if(ret)
	{
		cout << "a == b" << endl;
	}
	else
	{
		cout << "a != b" << endl;
	}
}

void test02()
{
	Person p1("Tom", 10);
	Person p2("Tom", 10);
	bool ret = Compare(p1, p2);
	if(ret)
	{
		cout << "a == b" << endl;
	}
	else
	{
		cout << "a != b" << endl;
	}
}

int main()
{
	test01();
	test02();
	return 0;
}

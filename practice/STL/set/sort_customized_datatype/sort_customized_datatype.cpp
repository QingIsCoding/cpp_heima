#include <iostream>
#include <set>
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

class ComparePerson
{
	public:
		bool operator()(const Person&p1, const Person&p2)const
		{
			return p1.m_age>p2.m_age;
		}
};

void test01()
{
	set<Person,ComparePerson> s;

	Person p1("刘备", 24);
	Person p2("关羽", 28);
	Person p3("张飞", 25);
	Person p4("赵云", 21);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);

	for(set<Person,ComparePerson>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "name: " << it->m_name
			 << "\tage: " << it->m_age << endl;
	}
}

int main()
{
	test01();
	return 0;
}

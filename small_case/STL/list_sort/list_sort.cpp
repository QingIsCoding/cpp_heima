#include <iostream>
#include <string>
#include <list>
using namespace std;

class Person
{
	public:
		string m_name;
		int m_age;
		int m_height;

		Person(string name, int age, int height)
		{
			this->m_name = name;
			this->m_age = age;
			this->m_height = height;
		}
};

bool ComparePerson(Person&p1, Person&p2)
{
	if(p1.m_age == p2.m_age)
	{
		return p1.m_height>p2.m_height;
	}
	return p1.m_age<p2.m_age;
}

void test01()
{
	list<Person> l;

	Person p1("刘备", 35, 175);
	Person p2("曹操", 45, 180);
	Person p3("孙权", 40, 170);
	Person p4("赵云", 25, 190);
	Person p5("张飞", 35, 160);
	Person p6("关羽", 35, 200);

	l.push_back(p1);
	l.push_back(p2);
	l.push_back(p3);
	l.push_back(p4);
	l.push_back(p5);
	l.push_back(p6);

	for(list<Person>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << "name: " << (*it).m_name 
			 << "\tage: " << it->m_age
			 << "\t\theight: " << it->m_height << endl;
	}

	cout << "\n--------------------sort--------------------" << endl;
	l.sort(ComparePerson);
	for(list<Person>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << "name: " << (*it).m_name 
			 << "\tage: " << it->m_age
			 << "\t\theight: " << it->m_height << endl;
	}
}

int main()
{
	test01();
	return 0;
}

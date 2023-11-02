#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class GreaterThanFive
{
	public:
		bool operator()(int val)
		{
			return val>5;
		}
};

void test01()
{
	vector<int> v;

	for(int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterThanFive());
	if(it == v.end())
	{
		cout << "not found" << endl;
	}
	else
	{
		cout << "found: " << *it << endl;
	}
}

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

class GreaterThanTwenty
{
	public:
		bool operator()(Person&p)
		{
			return p.m_age>20;
		}
};

void test02()
{
	vector<Person> v;

	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	vector<Person>::iterator it = find_if(v.begin(), v.end(), GreaterThanTwenty());
	if(it == v.end())
	{
		cout << "not found" << endl;
	}
	else
	{
		cout << "found" << endl;
		cout << "name: " << it->m_name
			 << "\tage: " << it->m_age << endl;
	}
}

int main()
{
	test01();
	cout << "---------------------------" << endl;
	test02();
	return 0;
}

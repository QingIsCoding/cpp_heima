#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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

		bool operator==(const Person&p)
		{
			if(this->m_name==p.m_name && this->m_age==p.m_age)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
};

void test01()
{
	vector<int> v;
	
	for(int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if(it == v.end())
	{
		cout << "not found" << endl;
	}
	else
	{
		cout << "found: " << *it << endl;
	}
}

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

	Person pp("bbb", 20);

	vector<Person>::iterator it = find(v.begin(), v.end(), pp);
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
	cout << "----------------------------" << endl;
	test02();
	return 0;
}

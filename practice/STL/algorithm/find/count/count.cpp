#include <iostream>
#include<string>
#include <vector>
#include <algorithm>
using namespace std;

void test01()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(40);
	v.push_back(30);
	v.push_back(40);
	v.push_back(20);
	v.push_back(40);

	int num = count(v.begin(), v.end(), 40);
	cout << "num(40): " << num << endl;
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

		bool operator==(const Person&p)
		{
			if(this->m_age == p.m_age)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
};

void test02()
{
	vector<Person> v;

	Person p1("刘备", 35);
	Person p2("关羽", 35);
	Person p3("张飞", 35);
	Person p4("赵云", 30);
	Person p5("曹操", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	Person p("诸葛亮", 35);
	
	int num = count(v.begin(), v.end(), p);
	cout << "num(age = 35): " << num << endl;
}

int main()
{
	test01();
	test02();
	return 0;
}

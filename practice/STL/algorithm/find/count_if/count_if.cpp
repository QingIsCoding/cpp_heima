#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class GreaterThanTwenty
{
	public:
		bool operator()(int val)
		{
			return val>20;
		}
};

void test01()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(40);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(20);

	int num = count_if(v.begin(), v.end(), GreaterThanTwenty());
	cout << "num(>20): " << num << endl;
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

class AgeGreaterThanTwenty
{
	public:
		bool operator()(const Person&p)
		{
			return p.m_age>20;
		}
};

void test02()
{
	vector<Person> v;

	Person p1("刘备", 35);
	Person p2("关羽", 35);
	Person p3("张飞", 35);
	Person p4("赵云", 40);
	Person p5("曹操", 20);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	int num = count_if(v.begin(), v.end(), AgeGreaterThanTwenty());
	cout << "num(age>20): " << num << endl;
}

int main()
{
	test01();
	test02();
	return 0;
}

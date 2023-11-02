#include <iostream>
using namespace std;

class Person
{
	public:
		Person()
		{
			cout << "Person::constructor(no parameter)" << endl;
		}

		Person(int age)
		{
			m_age = age;
			cout << "Person::constructor(with parameter)" << endl;
		}

		Person(const Person&p)
		{
			m_age = p.m_age;
			cout << "Person::constructor(copy)" << endl;
		}

		~Person()
		{
			cout << "Person::destructor" << endl;
		}

		int m_age;
};

void test01()
{
	Person p1(20);
	Person p2(p1);
	cout << "the age of p2: " << p2.m_age << endl;
}

void DoWork1(Person p)
{

}

void test02()
{
	Person p;
	DoWork1(p);
}

Person DoWork2()
{
	Person p1;
	cout << (int*)&p1 << endl;
	return p1;
	//return Person(p1);
}

void test03()
{
	Person p = DoWork2();
	cout << (int*)&p << endl;
}

int main()
{
	test01();
	cout << endl;
	test02();
	cout << endl;
	test03();
	return 0;
}

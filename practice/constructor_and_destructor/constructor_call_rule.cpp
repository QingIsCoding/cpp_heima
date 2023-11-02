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
			cout << "Person::constructor(with parameter)" << endl;
			m_age = age;
		}

		/*Person(const Person&p)
		{
			cout << "Person::constructor(copy)" << endl;
			m_age = p.m_age;
		}*/

		~Person()
		{
			cout << "Person::destructor" << endl;
		}

		int m_age;
};

void test01()
{
	Person p;
	p.m_age = 18;
	Person p2(p);
	cout << "the age of p2: " << p2.m_age << endl;
}

void test02()
{
	Person p;
}

int main()
{
	test01();
	cout << endl;
	test02();
	return 0;
}

#include <iostream>
using namespace std;

class Person
{
	public:
		Person(int age)
		{
			this->age = age;
		}

		Person&PersonAddAge(Person&p)
		{
			this->age += p.age;
			return *this;
		}

		int age;
};

void test01()
{
	Person p(18);
	cout << "the age of p1: " << p.age << endl;
}

void test02()
{
	Person p1(10);
	Person p2(10);
	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);
	cout << "the age of p2: " << p2.age << endl;
}

int main()
{
	test01();
	test02();
	return 0;
}

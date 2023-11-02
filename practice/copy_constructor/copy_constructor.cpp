#include <iostream>
using namespace std;

class Person
{
	public:
		Person()
		{
			cout << "Person::constructor(no parameter)" << endl;
		}

		Person(int a)
		{
			age = a;
			cout << "Person::constructor(with parameter)" << endl;
		}

		Person(const Person&p)
		{
			age = p.age;
			cout << "Person::constructor(copy)" << endl;
		}

		~Person()
		{
			cout << "Person::destructor" << endl;
		}

		int age;
};

void test01()
{
	//Person p1(); function declaration
	Person p1;
	Person p2(10);
	Person p3(p2);
	cout << "the age of p2: " << p2.age << endl;
	cout << "the age of p3: " << p3.age << endl;

	Person pe1;
	Person pe2 = Person(10);
	Person pe3 = Person(p2);
	//Person(10); anonymous object, recycle at the end of the line
	//Person(p3); error, Person(p3); <=> Person p3;
	
	Person per1 = 10;//Person per1 = 10; <=> Person per1 = Person(10);
	Person per2 = per1;
}

int main()
{
	test01();
	return 0;
}

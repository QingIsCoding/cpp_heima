#include <iostream>
#include <string>
using namespace std;

template<class T1, class T2>
class Person;
template<class T1, class T2>
void PrintPerson2(Person<T1, T2> p)
{
	cout << "implement outside class" << endl;
	cout << "name: " << p.m_name << "\tage: " << p.m_age << endl;
}

template<class T1, class T2>
class Person
{
	friend void PrintPerson1(Person<T1, T2> p)
	{
		cout << "implement inside class" << endl;
		cout << "name: " << p.m_name << "\tage: " << p.m_age << endl;
	}

	friend void PrintPerson2<>(Person<T1, T2> p);

	public:
		Person(T1 name, T2 age)
		{
			m_name = name;
			m_age = age;
		}

	private:
		T1 m_name;
		T2 m_age;
};

void test01()
{
	Person<string, int> p("Tom", 20);
	PrintPerson1(p);
}

void test02()
{
	Person<string, int> p("Jerry", 20);
	PrintPerson2(p);
}

int main()
{
	test01();
	test02();
	return 0;
}

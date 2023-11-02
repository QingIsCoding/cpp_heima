#include <iostream>
#include <string>
using namespace std;

template<class T1, class T2>
class Person
{
	public:
		T1 m_name;
		T2 m_age;

		Person(T1 name, T2 age)
		{
			m_name = name;
			m_age = age;
		}

		void ShowPerson()
		{
			cout << "name: " << m_name << "\tage: " << m_age << endl;
		}
};

void PrintPerson1(Person<string, int>&p)
{
	p.ShowPerson();
}

template<class T1, class T2>
void PrintPerson2(Person<T1, T2>&p)
{
	p.ShowPerson();
	cout << "typeid(T1).name(): " << typeid(T1).name() << endl;
	cout << "typeid(T2).name(): " << typeid(T2).name() << endl;
}

template<class T>
void PrintPerson3(T&p)
{
	p.ShowPerson();
	cout << "typeid(T).name(): " << typeid(T).name() << endl;
}

void test01()
{
	Person<string, int> p("sunwukong", 100);
	PrintPerson1(p);
}

void test02()
{
	Person<string, int> p("zhubajie", 90);
	PrintPerson2(p);
}

void test03()
{
	Person<string, int> p("tangseng", 30);
	PrintPerson3(p);
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

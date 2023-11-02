#include <iostream>
#include <string>
using namespace std;

template<class NameType, class AgeType = int>
class Person
{
	public:
		NameType m_name;
		AgeType m_age;

		Person(NameType name, AgeType age)
		{
			m_name = name;
			m_age = age;
		}

		void ShowPerson()
		{
			cout << "name: " << m_name << "\tage: " << m_age << endl;
		}
};

void test01()
{
	//Person p("sunwukong", 1000); error
	Person<string, int> p("sunwukong", 1000);
	p.ShowPerson();
}

void test02()
{
	Person<string> p("zhubajie", 999);
	p.ShowPerson();
}

int main()
{
	test01();
	test02();
	return 0;
}

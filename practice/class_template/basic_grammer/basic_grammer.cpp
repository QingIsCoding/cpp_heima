#include <iostream>
#include <string>
using namespace std;

template<class NameType, class AgeType>
class Person
{
	public:
		Person(NameType name, AgeType age)
		{
			this->m_name = name;
			this->m_age = age;
		}

		void ShowPerson()
		{
			cout << "name: " << m_name << endl;
			cout << "age: " << m_age << endl;
		}

		NameType m_name;
		AgeType m_age;
};

void test01()
{
	Person<string, int> p1("sunwukong", 999);
	p1.ShowPerson();
}

int main()
{
	test01();
	return 0;
}

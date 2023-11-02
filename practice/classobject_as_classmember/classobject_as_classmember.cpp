#include <iostream>
#include <string>
using namespace std;

class Phone
{
	public:
		Phone(string p_name)
		{
			cout << "class Phone" << endl;	
			m_pname = p_name;
		}

		~Phone()
		{
			cout << "class Phone(destructor)" << endl;	
		}

		string m_pname;
}; 

class Person
{
	public:
		Person(string name, string pname) : m_name(name),m_phone(pname)
		{
			cout << "class Person(constructor)" << endl;	
		}

		~Person()
		{
			cout << "class Person(destructor)" << endl;	
		}

		string m_name;
		Phone m_phone;
};

void test01()
{
	Person p("zhangsan", "iphone15");
	cout << p.m_name << " has " << p.m_phone.m_pname << endl;
}

int main()
{
	test01();
	return 0;
}

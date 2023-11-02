#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Person
{
	public:
		char m_name[64];
		int m_age;
};

void test01()
{
	ifstream ifs;
	ifs.open("person.txt",ios::in|ios::binary);

	if(!ifs.is_open())
	{
		return;
	}

	Person p;
	ifs.read((char*)&p, sizeof(Person));
	cout << "name: " << p.m_name << endl; 
	cout << "age: " << p.m_age << endl; 

	ifs.close();
}

int main()
{
	test01();
	return 0;
}

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
	/*ofstream ofs;
	ofs.open("person.txt",ios::out|ios::binary);*/
	ofstream ofs("person.txt",ios::out|ios::binary);
	Person p = {"zhangsan", 18};
	ofs.write((const char*)&p, sizeof(Person));
	ofs.close();
}

int main()
{
	test01();
	return 0;
}

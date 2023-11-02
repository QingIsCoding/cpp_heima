#include <iostream>
using namespace std;

class Person
{
	public:
		Person()
		{
			cout << "Person::constructor" << endl;
		}

		~Person()
		{
			cout << "Person::destructor" << endl;
		}
};

void test01()
{
	Person p;
}

int main()
{
	test01();
	return 0;
}

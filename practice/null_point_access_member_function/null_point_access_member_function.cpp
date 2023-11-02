#include <iostream>
using namespace std;

class Person
{
	public:
		void ShowClassName()
		{
			cout << "this is Person class" << endl;
		}

		void ShowPersonAge()
		{
			if(this == NULL)
			{
				return;
			}
			cout << "age = " << m_age << endl;
		}

		int m_age;
};

void test01()
{
	Person*p = NULL;
	p->ShowClassName();
	p->ShowPersonAge();
}

int main()
{
	test01();
	return 0;
}

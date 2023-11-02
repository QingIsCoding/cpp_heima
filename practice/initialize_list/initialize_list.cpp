#include <iostream>
using namespace std;

class Person
{
	public:
		/*Person(int a, int b, int c)
		{
			m_a = a;
			m_b = b;
			m_c = c;
		}*/

		/*Person() : m_a(10),m_b(20),m_c(30)
		{

		}*/

		Person(int a, int b, int c) : m_a(a),m_b(b),m_c(c)
		{

		}

		int m_a;
		int m_b;
		int m_c;
};

void test01()
{
	//Person p(10, 20, 30);
	//Person p;
	Person p(10, 20, 30);
	cout << "m_a: " << p.m_a << endl;
	cout << "m_b: " << p.m_b << endl;
	cout << "m_c: " << p.m_c << endl;
}

int main()
{
	test01();
	return 0;
}

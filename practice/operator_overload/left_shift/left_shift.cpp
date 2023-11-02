#include <iostream>
using namespace std;

class Person
{
friend ostream&operator<<(ostream&cout, Person&p);

	public:
		Person(int a, int b)
		{
			m_a = a;
			m_b = b;
		}

	private:
		int m_a;
		int m_b;
};

ostream&operator<<(ostream&cout, Person&p)
{
	cout << "m_a=" << p.m_a << "\tm_b=" << p.m_b << endl;
	return cout;
}

void test01()
{
	Person p(10, 20);
	//p.m_a = 10;
	//p.m_b = 20;

	cout << p << endl;
}

int main()
{
	test01();
	return 0;
}

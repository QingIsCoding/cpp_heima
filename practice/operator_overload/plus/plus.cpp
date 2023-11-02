#include <iostream>
using namespace std;

class Person
{
	public:
		int m_a;
		int m_b;

		/*Person operator+(Person&p)
		{
			Person temp;
			temp.m_a = this->m_a + p.m_a;
			temp.m_b = this->m_b + p.m_b;
			return temp;
		}*/
};

Person operator+(Person&p1, Person&p2)
{
	Person temp;
	temp.m_a = p1.m_a + p2.m_a;
	temp.m_b = p1.m_b + p2.m_b;
	return temp;
}

Person operator+(Person&p, int num)
{
	Person temp;
	temp.m_a = p.m_a + num;
	temp.m_b = p.m_b + num;
	return temp;
}

void test01()
{
	Person p1;
	p1.m_a = 10;
	p1.m_b = 20;

	Person p2;
	p2.m_a = 30;
	p2.m_b = 40;

	/*Person p3 = p1 + p2; <=> Person p3 = p1.operator+(p2);
	cout << "p3.m_a: " << p3.m_a << endl;
	cout << "p3.m_b: " << p3.m_b << endl;*/

	Person p4 = p1 + p2;//<=> Person p4 = operator+(p1, p2);
	cout << "p4.m_a: " << p4.m_a << endl;
	cout << "p4.m_b: " << p4.m_b << endl;

	Person p5 = p1 + 100;//<=> Person p5 = operator+(p1, 100);
	cout << "p5.m_a: " << p5.m_a << endl;
	cout << "p5.m_b: " << p5.m_b << endl;
}

int main()
{
	test01();
	return 0;
}

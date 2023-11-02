#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Person
{
	public:
		string m_name;
		int m_age;

		Person(string name, int age)
		{
			this->m_name = name;
			this->m_age = age;
		}
};

void test01()
{
	queue<Person> q;

	Person p1("唐僧", 30);
	Person p2("孙悟空", 1000);
	Person p3("猪八戒", 900);
	Person p4("沙僧", 800);

	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	while(!q.empty())
	{
		cout << "q.front().name: " << q.front().m_name
			 << "\tq.front().age: " << q.front().m_age << endl;
		cout << "q.back().name: " << q.back().m_name
			 << "\tq.back().age: " << q.back().m_age << endl;
		cout << "q.size(): " << q.size() << endl;
		cout << endl;
		q.pop();
	}

	cout << "q.size(): " << q.size() << endl;
}

int main()
{
	test01();
	return 0;
}

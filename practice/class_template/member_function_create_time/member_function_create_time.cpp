#include <iostream>
using namespace std;

class Person1
{
	public:
		void ShowPerson1()
		{
			cout << "Person1::ShowPerson1" << endl;
		}
};

class Person2
{
	public:
		void ShowPerson2()
		{
			cout << "Person2::ShowPerson2" << endl;
		}
};

template<class T>
class MyClass
{
	public:
		T obj;

		void func1()
		{
			obj.ShowPerson1();
		}

		void func2()
		{
			obj.ShowPerson2();
		}
};

void test01()
{
	MyClass<Person1> m;
	m.func1();
	//m.func2(); erroe
}

int main()
{
	test01();
	return 0;
}

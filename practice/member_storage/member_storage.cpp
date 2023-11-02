#include <iostream>
using namespace std;

class Person1
{
//0
};

class Person2
{
	public:
		int m_a2;//4
};

class Person3
{
	public:
		int m_a3;//4
		static int m_b3;//0
};

class Person4
{
	public:
		int m_a4;//4
		void func1();//0
		static void func2();//0
};

void test01()
{
	Person1 p1;
	cout << "sizeof(p): " << sizeof(p1) << endl;
}
	
void test02()
{
	Person2 p2;
	cout << "sizeof(p): " << sizeof(p2) << endl;
}

void test03()
{
	Person3 p3;
	cout << "sizeof(p): " << sizeof(p3) << endl;
}

void test04()
{
	Person4 p4;
	cout << "sizeof(p): " << sizeof(p4) << endl;
}

int main()
{
	test01();
	cout << endl;
	test02();
	cout << endl;
	test03();
	cout << endl;
	test04();
	return 0;
}

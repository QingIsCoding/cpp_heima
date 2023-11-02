#include <iostream>
using namespace std;

template<class T>
class Base
{
	public:
		T m;
};

//class Son1 : public Base//error
class Son1 : public Base<int>
{
	
};

void test01()
{
	Son1 s1;
}

template<class T1, class T2>
class Son2 : public Base<T2>
{
	public:
		T1 obj;

		Son2()
		{
			cout << "typeid(T1).name: " << typeid(T1).name() << endl;
			cout << "typeid(T2).name: " << typeid(T2).name() << endl;
		}
};

void test02()
{
	Son2<int, char> s2;
}

int main()
{
	test01();
	test02();
	return 0;
}

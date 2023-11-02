#include <iostream>
using namespace std;

class Base
{
	public:
		Base()
		{
			cout << "Base::constructor" << endl;	
		}

		~Base()
		{
			cout << "Base::destructor" << endl;
		}
};

class Son : public Base
{
	public:
		Son()
		{
			cout << "Son::constructor" << endl;	
		}

		~Son()
		{
			cout << "Son::destructor" << endl;
		}
};

void test01()
{
	//Base b;
	Son s;
}

int main()
{
	test01();
	return 0;
}

#include <iostream>
using namespace std;

class Base
{
	public:
		int m_a;
	protected:
		int m_b;
	private:
		int m_c;
};

class Son : public Base
{
	public:
		int m_d;
};

void test01()
{
	cout << "sizeof(son): " << sizeof(Son) << endl;
}

int main()
{
	test01();
	return 0;
}

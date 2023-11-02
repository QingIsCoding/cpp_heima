#include <iostream>
#include <functional>
using namespace std;

void test01()
{
	negate<int> n;
	cout << "n(50): " << n(50) << endl;;
}

void test02()
{
	plus<int> p;
	cout << "p(10, 20): " << p(10, 20) << endl;
}

int main()
{
	test01();
	cout << endl;
	test02();
	return 0;
}

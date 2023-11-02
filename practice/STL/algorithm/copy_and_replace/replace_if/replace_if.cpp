#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MyPrint
{
	public:
		void operator()(int val)
		{
			cout << val << " ";
		}
};

class GreaterThanThirty
{
	public:
		bool operator()(int val)
		{
			return val>30;
		}
};

void test01()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(40);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(30);

	cout << "before replace_if: ";
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;

	cout << "after replace_if: ";
	replace_if(v.begin(), v.end(), GreaterThanThirty(), 3000);
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
}

int main()
{
	test01();
	return 0;
}

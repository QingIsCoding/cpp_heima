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

void test01()
{
	vector<int> v;

	v.push_back(20);
	v.push_back(30);
	v.push_back(50);
	v.push_back(30);
	v.push_back(40);
	v.push_back(20);
	v.push_back(10);
	v.push_back(20);

	cout << "before replace:\t";
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;

	cout << "after replace:\t";
	replace(v.begin(), v.end(), 20, 2000);
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
}

int main()
{
	test01();
	return 0;
}

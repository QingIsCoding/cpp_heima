#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MyPrint
{
	public:
		void operator()(int val)
		{
			cout << val << "\t";
		}
};

void test01()
{
	vector<int> v1;
	vector<int> v2;

	for(int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i+100);
	}

	cout << "before swap(v1): ";
	for_each(v1.begin(), v1.end(), MyPrint());
	cout << endl;
	cout << "before swap(v2): ";
	for_each(v2.begin(), v2.end(), MyPrint());
	cout << endl;

	cout << "--------------------------------------------------------------------------------------------" << endl;
	cout << "after swap(v1):  ";
	swap(v1, v2);
	for_each(v1.begin(), v1.end(), MyPrint());
	cout << endl;
	cout << "after swap(v2):  ";
	for_each(v2.begin(), v2.end(), MyPrint());
	cout << endl;
}

int main()
{
	test01();
	return 0;
}

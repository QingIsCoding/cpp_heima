#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void MyPrint(int val)
{
	cout << val << " ";
}

void test01()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);

	cout << "before reverse:\t";
	for_each(v.begin(), v.end(), MyPrint);
	cout << endl;

	cout << "after reverse:\t";
	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), MyPrint);
	cout << endl;
}

int main()
{
	test01();
	return 0;
}

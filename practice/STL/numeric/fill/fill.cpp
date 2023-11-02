#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

void MyPrint(int val)
{
	cout << val << " ";
}

void test01()
{
	vector<int> v;

	v.resize(10);

	fill(v.begin(), v.end(), 100);

	for_each(v.begin(), v.end(), MyPrint);
	cout << endl;
}

int main()
{
	test01();
	return 0;
}

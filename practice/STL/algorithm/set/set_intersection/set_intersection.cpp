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
	vector<int> v1;
	vector<int> v2;

	for(int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i+5);
	}

	vector<int> v_target;

	v_target.resize(min(v1.size(), v2.size()));

	vector<int>::iterator it_end = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v_target.begin());

	for_each(v_target.begin(), it_end, MyPrint);
	cout << endl;
}

int main()
{
	test01();
	return 0;
}

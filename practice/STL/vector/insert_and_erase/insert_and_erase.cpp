#include <iostream>
#include <vector>
using namespace std;

void PrintVector(vector<int>&v)
{
	for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	vector<int> v1;

	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	PrintVector(v1);

	v1.pop_back();
	PrintVector(v1);

	v1.insert(v1.begin(), 100);
	PrintVector(v1);

	v1.insert(v1.begin(), 2, 1000);
	PrintVector(v1);

	v1.erase(v1.begin());
	PrintVector(v1);

	//v1.erase(v1.begin(), v1.end());
	v1.clear();
	PrintVector(v1);
}

int main()
{
	test01();
	return 0;
}

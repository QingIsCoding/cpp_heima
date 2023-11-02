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
	for(int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	PrintVector(v1);

	if(v1.empty())
	{
		cout << "empty" << endl;
	}
	else
	{
		cout << "not empty" << endl;
		cout << "capacity: " << v1.capacity() << endl;
	}

	//v1.resize(15); default:0
	v1.resize(15, 100);
	PrintVector(v1);

	v1.resize(5);
	PrintVector(v1);
}

int main()
{
	test01();
	return 0;
}

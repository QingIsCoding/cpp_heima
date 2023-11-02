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

	vector<int> v2;
	for(int i = 10; i > 0; i--)
	{
		v2.push_back(i);
	}
	PrintVector(v2);

	cout << "\nafter swap" << endl;
	v1.swap(v2);
	PrintVector(v1);
	PrintVector(v2);
}

void test02()
{
	vector<int> v;
	for(int i = 0; i < 100000; i++)
	{
		v.push_back(i);
	}
	cout << "v.capacity(): " << v.capacity() << endl;
	cout << "v.size(): " << v.size() << endl;
	cout << endl;

	v.resize(3);
	cout << "v.capacity(): " << v.capacity() << endl;
	cout << "v.size(): " << v.size() << endl;
	cout << endl;

	vector<int>(v).swap(v);
	cout << "v.capacity(): " << v.capacity() << endl;
	cout << "v.size(): " << v.size() << endl;
}

int main()
{
	test01();
	cout << "--------------------------------" << endl;
	test02();
	return 0;
}

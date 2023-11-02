#include <iostream>
#include <map>
using namespace std;

void PrintMap(map<int,int>&m)
{
	for(map<int,int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key: " << it->first
			 << "\tvalue: " << it->second << endl;
	}
	cout << endl;
}

void test01()
{
	map<int,int> m;

	m.insert(pair<int,int>(1,10));
	m.insert(pair<int,int>(2,20));
	m.insert(pair<int,int>(3,30));
	m.insert(pair<int,int>(4,40));
	PrintMap(m);

	if(m.empty())
	{
		cout << "empty" << endl;
	}
	else
	{
		cout << "not empty" << endl;
		cout << "m.size(): " << m.size() << endl;
	}
}

void test02()
{
	map<int,int> m1;
	m1.insert(pair<int,int>(1,10));
	m1.insert(pair<int,int>(2,20));
	m1.insert(pair<int,int>(3,30));
	PrintMap(m1);

	map<int,int> m2;
	m2.insert(pair<int,int>(4,100));
	m2.insert(pair<int,int>(5,200));
	m2.insert(pair<int,int>(6,300));

	cout << "----------before swap----------" << endl;
	cout << "m1" << endl;
	PrintMap(m1);
	cout << "m2" << endl;
	PrintMap(m2);

	cout << "----------after swap----------" << endl;
	m1.swap(m2);
	cout << "m1" << endl;
	PrintMap(m1);
	cout << "m2" << endl;
	PrintMap(m2);
}

int main()
{
	test01();
	cout << "=============================================" << endl;
	test02();
	return 0;
}

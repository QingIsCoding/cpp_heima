#include <iostream>
#include <map>
using namespace std;

void PrintMap(map<int,int>&m)
{
	for(map<int,int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key: " << (*it).first 
			 << "\tvalue: " << it->second << endl;
	}
}

void test01()
{
	map<int,int> m;

	m.insert(pair<int,int>(1,10));
	m.insert(pair<int,int>(3,30));
	m.insert(pair<int,int>(2,20));
	m.insert(pair<int,int>(4,40));
	PrintMap(m);

	cout << endl;
	map<int,int> m2(m);
	PrintMap(m2);

	cout << endl;
	map<int,int> m3;
	m3 = m2;
	PrintMap(m3);
}

int main()
{
	test01();
	return 0;
}

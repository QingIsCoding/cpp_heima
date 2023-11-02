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
}

void test01()
{
	map<int,int> m;

	m.insert(pair<int,int>(1,10));
	m.insert(make_pair(2,20));
	m.insert(map<int,int>::value_type(3,30));
	m[4] = 40;
	cout << m[4] << endl;
	PrintMap(m);

	cout << endl;
	m.erase(m.begin());
	PrintMap(m);

	cout << endl;
	m.erase(3);//one key = 3
	PrintMap(m);

	m.erase(30);//no key = 30
	PrintMap(m);

	cout << "-------------------" << endl;
	//m.erase(m.begin(), m.end());
	m.clear();
	PrintMap(m);
}

int main()
{
	test01();
	return 0;
}

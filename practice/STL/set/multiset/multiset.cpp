#include <iostream>
#include <set>
using namespace std;

void test01()
{
	set<int> s;

	pair<set<int>::iterator,bool> ret = s.insert(10);
	if(ret.second)
	{
		cout << "first insert success" << endl;
	}
	else
	{
		cout << "first insert fail" << endl;
	}

	ret = s.insert(10);
	if(ret.second)
	{
		cout << "second insert success" << endl;
	}
	else
	{
		cout << "second insert fail" << endl;
	}

	cout << "\nmultiset" << endl;
	multiset<int> ms;

	ms.insert(10);
	ms.insert(10);
	ms.insert(10);
	ms.insert(10);
	for(multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	test01();
	return 0;
}

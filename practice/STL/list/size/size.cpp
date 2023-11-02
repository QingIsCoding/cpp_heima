#include <iostream>
#include <list>
using namespace std;

void PrintList(const list<int>&l)
{
	for(list<int>::const_iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	list<int> l1;

	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	PrintList(l1);

	if(l1.empty())
	{
		cout << "empty" << endl;
	}
	else
	{
		cout << "not empty" << endl;
		cout << "l1.size(): " << l1.size() << endl;
	}

	l1.resize(10);
	PrintList(l1);

	l1.resize(11, 100000);
	PrintList(l1);

	l1.resize(2);
	PrintList(l1);
}

int main()
{
	test01();
	return 0;
}

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

	l1.push_back(20);
	l1.push_back(10);
	l1.push_back(50);
	l1.push_back(40);
	l1.push_back(30);
	PrintList(l1);

	cout << "reverse" << endl;
	l1.reverse();
	PrintList(l1);
}

bool MyCompare(int v1, int v2)
{
	return v1>v2;
}

void test02()
{
	list<int> l1;

	l1.push_back(20);
	l1.push_back(10);
	l1.push_back(50);
	l1.push_back(40);
	l1.push_back(30);
	PrintList(l1);

	cout << "sort" << endl;
	l1.sort();
	PrintList(l1);

	l1.sort(MyCompare);
	PrintList(l1);
}

int main()
{
	test01();
	cout << "----------------" << endl;
	test02();
	return 0;
}

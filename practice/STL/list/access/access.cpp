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

	cout << "l1.front(): " << l1.front() << endl;
	cout << "l1.back(): " << l1.back() << endl;

	list<int>::iterator it = l1.begin();
	it++;
	it--;
}

int main()
{
	test01();
	return 0;
}

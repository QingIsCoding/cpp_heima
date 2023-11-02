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
	list<int> l;

	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_front(100);
	l.push_front(200);
	l.push_front(300);
	PrintList(l);

	l.pop_back();
	PrintList(l);

	l.pop_front();
	PrintList(l);

	list<int>::iterator it = l.begin();
	l.insert(++it, 1000);
	PrintList(l);

	it = l.begin();
	l.erase(++it);
	PrintList(l);

	l.push_back(10000);
	l.push_back(10000);
	l.push_front(10000);
	l.push_front(10000);
	PrintList(l);

	l.remove(10000);
	PrintList(l);

	l.clear();
	PrintList(l);
}

int main()
{
	test01();
	return 0;
}

#include <iostream>
#include <deque>
using namespace std;

void PrintDeque(const deque<int>&d)
{
	for(deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	deque<int> d1;

	d1.push_back(10);
	d1.push_back(20);
	d1.push_front(100);
	d1.push_front(200);
	PrintDeque(d1);

	d1.pop_back();
	PrintDeque(d1);

	d1.pop_front();
	PrintDeque(d1);
}

void test02()
{
	deque<int> d2;

	d2.push_back(10);
	d2.push_back(20);
	d2.push_front(100);
	d2.push_front(200);
	PrintDeque(d2);

	d2.insert(d2.begin(), 1000);
	PrintDeque(d2);

	d2.insert(d2.begin(), 2, 10000);
	PrintDeque(d2);

	deque<int> d3;
	d3.push_back(1);
	d3.push_back(2);
	d3.push_back(3);
	PrintDeque(d3);
	d2.insert(d2.begin(), d3.begin(), d3.end());
	PrintDeque(d2);
}

void test03()
{
	deque<int> d4;

	d4.push_back(10);
	d4.push_back(20);
	d4.push_front(100);
	d4.push_front(200);
	PrintDeque(d4);

	deque<int>::iterator it = d4.begin();
	it++;
	d4.erase(it);
	PrintDeque(d4);

	//d4.erase(d4.begin(), d4.end());
	d4.clear();
	PrintDeque(d4);
}

int main()
{
	test01();
	cout << "-----------------" << endl;
	test02();
	cout << "-----------------" << endl;
	test03();
	return 0;
}

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
	for(int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	PrintDeque(d1);

	if(d1.empty())
	{
		cout << "empty" << endl;
	}
	else
	{
		cout << "not empty" << endl;
		cout << "size: " << d1.size() << endl;
	}

	//d1.resize(15);
	d1.resize(15, 1);
	PrintDeque(d1);
}

int main()
{
	test01();
	return 0;
}

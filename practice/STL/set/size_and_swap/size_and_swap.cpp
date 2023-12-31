#include <iostream>
#include <set>
using namespace std;

void PrintSet(set<int>&s)
{
	for(set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	set<int> s1;

	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	PrintSet(s1);

	if(s1.empty())
	{
		cout << "empty" << endl;
	}
	else
	{
		cout << "not empty" << endl;
		cout << "s1.size(): " << s1.size() << endl;
	}

	set<int> s2;
	
	s2.insert(100);
	s2.insert(300);
	s2.insert(200);
	s2.insert(400);
	PrintSet(s2);

	cout << "\n--------------------before swap--------------------" << endl;
	PrintSet(s1);
	PrintSet(s2);
	s1.swap(s2);
	cout << "\n--------------------after swap--------------------" << endl;
	PrintSet(s1);
	PrintSet(s2);
}

int main()
{
	test01();
	return 0;
}

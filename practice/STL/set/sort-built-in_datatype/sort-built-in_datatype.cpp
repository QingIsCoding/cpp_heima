#include <iostream>
#include <set>
using namespace std;

void PrintSet1(const set<int>&s)
{
	for(set<int>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

class MyCompare
{
	public:
		bool operator()(int v1, int v2)const
		{
			return v1>v2;
		}
};

void PrintSet2(const set<int,MyCompare>&s)
{
	for(set<int,MyCompare>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


void test01()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(40);
	s1.insert(20);
	s1.insert(50);
	s1.insert(30);
	PrintSet1(s1);

	set<int,MyCompare> s2;
	s2.insert(10);
	s2.insert(40);
	s2.insert(20);
	s2.insert(50);
	s2.insert(30);
	PrintSet2(s2);
}

int main()
{
	test01();
	return 0;
}

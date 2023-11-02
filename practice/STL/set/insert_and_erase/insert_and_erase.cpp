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

	s1.insert(30);
	s1.insert(10);
	s1.insert(20);
	s1.insert(40);
	PrintSet(s1);

	s1.erase(s1.begin());
	PrintSet(s1);

	s1.erase(30);
	PrintSet(s1);

	//s1.erase(s1.begin(), s1.end());
	s1.clear();
	PrintSet(s1);
}

int main()
{
	test01();
	return  0;
}

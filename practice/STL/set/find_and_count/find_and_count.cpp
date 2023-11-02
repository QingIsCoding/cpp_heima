#include <iostream>
#include <set>
using namespace std;

void PrindSet(set<int>&s)
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
	PrindSet(s1);
	
	set<int>::iterator pos = s1.find(300);
	if(pos != s1.end())
	{
		cout << "300-----found" << endl;
	}
	else
	{
		cout << "300-----not found" << endl;
	}
}

void test02()
{
	set<int> s1;

	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	s1.insert(30);
	PrindSet(s1);
	
	int num = s1.count(30);
	cout << "s1.count(30): " << num << endl;
}

int main()
{
	test01();
	cout << endl;
	test02();
	return 0;
}

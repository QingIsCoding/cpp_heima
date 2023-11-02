#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Print(int val)
{
	cout << val << endl;
}

void test01()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//traverse method 1
	/*vector<int>::iterator itBegin = v.begin();
	vector<int>::iterator itEnd = v.end();
	while(itBegin != itEnd)
	{
		cout << *itBegin << endl;
		itBegin++;
	}*/

	//traverse method 2
	/*for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}*/

	//traverse method 3
	for_each(v.begin(), v.end(), Print);
}

int main()
{
	test01();
	return 0;
}

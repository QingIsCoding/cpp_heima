#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

void MyPrint(int val)
{
	cout << val << " ";
}

void test01()
{
	vector<int> v;
	
	for(int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), MyPrint);
	cout << endl;
	
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), MyPrint);
	cout << endl;
}

int main()
{
	srand((unsigned int)time(NULL));
	test01();
	return 0;
}

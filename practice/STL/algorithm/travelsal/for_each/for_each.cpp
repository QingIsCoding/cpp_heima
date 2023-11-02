#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Print01(int val)
{
	cout << val << " ";
}

class Print02
{
	public:
		void operator()(int val)
		{
			cout << val << " ";
		}
};

void test01()
{
	vector<int> v;

	for(int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for_each(v.begin(), v.end(), Print01);
	cout << endl;

	for_each(v.begin(), v.end(), Print02());
	cout << endl;
}

int main()
{
	test01();
	return 0;
}

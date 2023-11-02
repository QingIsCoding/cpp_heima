#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Transform
{
	public:
		int operator()(int v)
		{
			return v;
		}
};

class MyPrint
{
	public:
		void operator()(int v)
		{
			cout << v << " ";
		}
};

void test01()
{
	vector<int> v;

	for(int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int> v_target;
	v_target.resize(v.size());

	transform(v.begin(), v.end(), v_target.begin(), Transform());
	for_each(v_target.begin(), v_target.end(), MyPrint());
	cout << endl;
}

int main()
{
	test01();
	return 0;
}

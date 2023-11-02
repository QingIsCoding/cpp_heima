#include <iostream>
#include <stack>
using namespace std;

void test01()
{
	stack<int> s;

	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	while(!s.empty())
	{
		cout << "s.size(): " << s.size() << endl;
		cout << "s.top(): " << s.top() << endl;
		s.pop();
		cout << endl;
	}
		
	cout << "s.size(): " << s.size() << endl;
}

int main()
{
	test01();
	return 0;
}

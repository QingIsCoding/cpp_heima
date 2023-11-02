#include <iostream>
#include <string>
#include "Person.cpp"
using namespace std;

void test01()
{
	Person<string, int> p("Jerry", 18);
	p.ShowPerson();
}

int main()
{
	test01();
	return 0;
}

#include <iostream>
using namespace std;

class Animal
{
	public:
		int m_age;
};

class Sheep : virtual public Animal{};

class Camel : virtual public Animal{};

class Alpaca : public Sheep, public Camel{};

void test01()
{
	Alpaca alpaca;
	alpaca.Sheep::m_age = 18;
	alpaca.Camel::m_age = 28;
	cout << "alpaca.Sheep::m_age: " << alpaca.Sheep::m_age << endl;
	cout << "alpaca.Camel::m_age: " << alpaca.Camel::m_age << endl;
	cout << "alpaca.m_age: " << alpaca.m_age << endl;
}

int main()
{
	test01();	
	return 0;
}

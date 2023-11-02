#include <iostream>
using namespace std;

const double PI = 3.14;

class Circle
{
	public:
		int m_r;
		double calculate_circumference()
		{
			return 2 * PI * m_r;
		}

};

int main()
{
	Circle c1;
	c1.m_r = 10;
	cout << "circumference of circle: " << c1.calculate_circumference() << endl;
	return 0;
}

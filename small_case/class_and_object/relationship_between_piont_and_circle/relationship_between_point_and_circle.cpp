#include <iostream>
#include "point.h"
#include "circle.h"
using namespace std;

/*class Point
{
	public:
		void SetX(int x)
		{
			m_x = x;
		}
		int GetX()
		{
			return m_x;
		}

		void SetY(int y)
		{
			m_y = y;
		}
		int GetY()
		{
			return m_y;
		}

	private:
		int m_x;
		int m_y;
};*/

/*class Circle
{
	public:
		void SetR(int r)
		{
			m_r = r;
		}
		int GetR()
		{
			return m_r;
		}

		void SetCenter(Point center)
		{
			m_center = center;
		}
		Point GetCenter()
		{
			return m_center;
		}

	private:
		int m_r;
		Point m_center;
};*/

void IsInCircle(Circle&c, Point&p)
{
	int distance =(c.GetCenter().GetX()-p.GetX())*(c.GetCenter().GetX()-p.GetX())
				  +(c.GetCenter().GetY()-p.GetY())*(c.GetCenter().GetY()-p.GetY());
	int r_distance = c.GetR()*c.GetR();
	if(distance == r_distance)
	{
		cout << "point is on the circle" << endl;
	}
	else if(distance > r_distance)
	{
		cout << "point is outside the circle" << endl;
	}
	else
	{
		cout << "point is inside the circle" << endl;
	}
}

int main()
{
	Circle c;
	c.SetR(10);
	Point center;
	center.SetX(10);
	center.SetY(0);
	c.SetCenter(center);
	Point p;
	p.SetX(10);
	p.SetY(10);
	IsInCircle(c, p);
	return 0;
}

#include "circle.h"

void Circle::SetR(int r)
{
	m_r = r;
}
int Circle::GetR()
{
	return m_r;
}

void Circle::SetCenter(Point center)
{
	m_center = center;
}
Point Circle::GetCenter()
{
	return m_center;
}

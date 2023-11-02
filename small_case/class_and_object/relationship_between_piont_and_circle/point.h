#pragma once
#include <iostream>
using namespace std;

class Point
{
	public:
		void SetX(int x);
        int GetX();
 
        void SetY(int y);
        int GetY();

	private:
		int m_x;
		int m_y;
};


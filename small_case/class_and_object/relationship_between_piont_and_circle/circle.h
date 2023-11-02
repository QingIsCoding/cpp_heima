#pragma once
#include <iostream>
#include "point.h"
using namespace std;

class Circle
{
    public:
        void SetR(int r);
        int GetR();

        void SetCenter(Point center);
        Point GetCenter();

    private:
        int m_r;
        Point m_center;
};

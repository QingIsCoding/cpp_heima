#pragma once
#include "Worker.h"
using namespace std;

class Boss : public Worker
{
    public:
        Boss(int id, string name, int department);
        virtual void ShowInfo();
        virtual string GetDepartment();
};

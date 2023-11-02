#pragma once
#include "Worker.h"
using namespace std;

class Manager : public Worker
{
    public:
        Manager(int id, string name, int department);
        virtual void ShowInfo();
        virtual string GetDepartment();
};

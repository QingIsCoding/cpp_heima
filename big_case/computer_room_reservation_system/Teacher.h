#pragma once
#include <iostream>
#include "Identity.h"
#include <string>
#include "OrderFile.h"
#include <vector>

using namespace std;

class Teacher : public Identity
{
	public:
		int t_id;

		Teacher();
		Teacher(int id, string name, string pwd);
		virtual void OpenMenu();
        void ShowAllOrder();
        void ValidOrder();
};

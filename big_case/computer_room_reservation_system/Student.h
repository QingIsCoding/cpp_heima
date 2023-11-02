#pragma once
#include <iostream>
#include "Identity.h"
#include <string>
#include <vector>
#include "ComputerRoom.h"
#include <fstream>
#include "GlobalFile.h"
#include "OrderFile.h"

using namespace std;

class Student : public Identity
{
	public:
		int s_id;
		vector<ComputerRoom> v_computer_room;

		Student();
		Student(int id, string name, string pwd);
		virtual void OpenMenu();
		void ApplyOrder();
		void ShowMyOrder();
		void ShowAllOrder();
		void CancelOrder();
};

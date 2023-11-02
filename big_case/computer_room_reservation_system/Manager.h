#pragma once
#include <iostream>
#include "Identity.h"
#include <string>
#include <fstream>
#include "GlobalFile.h"
#include <vector>
#include "Student.h"
#include "Teacher.h"
#include <algorithm>
#include "ComputerRoom.h"

using namespace std;

class Manager : public Identity
{
	public:
		vector<Student> v_student;
		vector<Teacher> v_teacher;
		vector<ComputerRoom> v_computer_room;

		Manager();
		Manager(string name, string pwd);
		virtual void OpenMenu();
		void AddPerson();
		void ShowPerson();
		void ShowComputer();
		void CleanFile();
		void InitializeVector();
		bool CheckRepeat(int id, int type);
};

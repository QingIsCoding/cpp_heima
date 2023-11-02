#pragma once
#include <iostream>
#include <fstream>
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"
#define FILENAME "EmployeeFile.txt"
using namespace std;

class Interface
{
	public:
		int m_employee_number;
		bool m_file_is_empty;

		Interface();

		void ShowMenu();
		void ExitSystem();
		Worker**m_employee_array;
		void AddEmployee();
		void Save();
		int GetNumber();
		void InitializeEmployee();
		void ShowEmployee();
		int IsExist(int id);
		void DelEmployee();
		void ModifyEmployee();
		void FindEmployee();
		void SortEmployee();
		void CleanFile();

		~Interface();
};

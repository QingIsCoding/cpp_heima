#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>
using namespace std;
#define 策划 0
#define 美术 1
#define 研发 2

class Employee
{
	public:
		string m_name;
		int m_salary;
};

void CreateEmployee(vector<Employee>&v)
{
	string name_seed = "ABCDEFGHIJ";
	for(int i = 0; i < 10; i++)
	{
		Employee employee;
		employee.m_name = "员工";
		employee.m_name += name_seed[i];
		employee.m_salary = rand()%10000+10000;
		v.push_back(employee);
	}
}

void GroupEmployee(vector<Employee>&v, multimap<int,Employee>&m)
{
	for(vector<Employee>::iterator it = v.begin(); it != v.end(); it++)
	{
		int department = rand()%3;
		m.insert(make_pair(department, *it));
	}
}

void ShowEmployee(multimap<int,Employee>&m)
{
	cout << "策划部门: " << endl;
	multimap<int,Employee>::iterator pos = m.find(策划);
	int count = m.count(策划);
	int index = 0;
	for(; pos!=m.end() && index<count; pos++, index++)
	{
		cout << "姓名: " << pos->second.m_name
			 << "\t工资: " << pos->second.m_salary << endl;
	}

	cout << "\n美术部门: " << endl;
	pos = m.find(美术);
	count = m.count(美术);
	index = 0;
	for(; pos!=m.end() && index<count; pos++, index++)
	{
		cout << "姓名: " << pos->second.m_name
			 << "\t工资: " << pos->second.m_salary << endl;
	}

	cout << "\n研发部门: " << endl;
	pos = m.find(研发);
	count = m.count(研发);
	index = 0;
	for(; pos!=m.end() && index<count; pos++, index++)
	{
		cout << "姓名: " << pos->second.m_name
			 << "\t工资: " << pos->second.m_salary << endl;
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	vector<Employee> v_employee;
	CreateEmployee(v_employee);
	multimap<int,Employee> m_employee;
	GroupEmployee(v_employee, m_employee);
	ShowEmployee(m_employee);
	//test code
	/*for(vector<Employee>::iterator it = v_employee.begin(); it != v_employee.end(); it++)
	{
		cout << "姓名: " << it->m_name
			 << "\t工资: " << it->m_salary << endl;
	}*/
	return 0;
}

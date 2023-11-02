#include "Manager.h"

Manager::Manager(int id, string name, int department)
{
    this->m_id = id; 
    this->m_name = name;
    this->m_department = department;
}

void Manager::ShowInfo()
{
    cout << "职工编号: " << this->m_id
         << "\t职工姓名: " << this->m_name
         << "\t职工岗位: " << this->GetDepartment()
         << "\t岗位职责: 完成老板交给的任务，并下发任务给员工" << endl;
}

string Manager::GetDepartment()
{
    return string("经理");
}

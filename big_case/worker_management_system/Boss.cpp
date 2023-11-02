#include "Boss.h"

Boss::Boss(int id, string name, int department)
{
    this->m_id = id; 
    this->m_name = name;
    this->m_department = department;
}

void Boss::ShowInfo()
{
    cout << "职工编号: " << this->m_id
         << "\t职工姓名: " << this->m_name
         << "\t职工岗位: " << this->GetDepartment()
         << "\t岗位职责: 管理公司所有事务" << endl;
}

string Boss::GetDepartment()
{
    return string("老板");
}

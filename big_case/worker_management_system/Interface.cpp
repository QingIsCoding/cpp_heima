#include "Interface.h"

Interface::Interface()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);

	if(!ifs.is_open())
	{
		cout << "文件不存在!" << endl;
		this->m_employee_number = 0;
		this->m_employee_array = NULL;
		this->m_file_is_empty = true;
		return;
	}

	char ch;
	ifs >> ch;

	if(ifs.eof())
	{
		cout << "文件为空!" << endl;
		this->m_employee_number = 0;
		this->m_employee_array = NULL;
		this->m_file_is_empty = true;
		return;
	}

	int number = this->GetNumber();
	cout << "职工人数为: " << number << endl;
	this->m_employee_number = number;
	this->m_employee_array = new Worker*[this->m_employee_number];
	this->InitializeEmployee();

	//test code
	/*for(int i = 0; i < this->m_employee_number; i++)
	{
		cout << "职工编号: " << this->m_employee_array[i]->m_id
			 << "\t姓名: " << this->m_employee_array[i]->m_name
			 << "\t部门编号: " << this->m_employee_array[i]->m_department << endl;
	}*/
}

void Interface::ShowMenu()
{
	cout << "******************************************" << endl;
	cout << "***********欢迎使用职工管理系统!**********" << endl;
	cout << "**************0.退出管理程序**************" << endl;
	cout << "**************1.增加职工信息**************" << endl;
	cout << "**************2.显示职工信息**************" << endl;
	cout << "**************3.删除离职职工**************" << endl;
	cout << "**************4.修改职工信息**************" << endl;
	cout << "**************5.查找职工信息**************" << endl;
	cout << "**************6.职工编号排序**************" << endl;
	cout << "**************7.清空所有文档**************" << endl;
	cout << "******************************************" << endl;
	cout << endl;
}

void Interface::ExitSystem()
{
	cout << "欢迎下次使用!" << endl;
	exit(0);
}

void Interface::AddEmployee()
{
	cout << "请输入添加的职工数量: ";
	int add_number = 0;
	cin >> add_number;
	if(add_number > 0)
	{
		int new_size = this->m_employee_number + add_number;
		Worker**new_space = new Worker*[new_size];
		if(this->m_employee_array != NULL)
		{
			for(int i = 0; i < this->m_employee_number; i++)
			{
				new_space[i] = this->m_employee_array[i];
			}
		}
		for(int i = 0; i < add_number; i++)
		{
			int id;
			string name;
			int department;

			cout << "请输入第" << i+1 << "个新职工编号: " << endl;
			cin >> id;
			cout << "请输入第" << i+1 << "个新职工姓名: " << endl;
			cin >> name;
			cout << "请输入第" << i+1 << "个新职工岗位: " << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> department;

			Worker*worker = NULL;
			switch(department)
			{
				case 1:
					worker = new Employee(id, name, department);
					break;
				case 2:
					worker = new Manager(id, name, department);
					break;
				case 3:
					worker = new Boss(id, name, department);
					break;
				default:
					break;
			}

			new_space[this->m_employee_number+i] = worker;
		}
		delete[] this->m_employee_array;
		this->m_employee_array = new_space;
		this->m_employee_number = new_size;
		this->m_file_is_empty = false;
		cout << "成功添加" << add_number << "名新职工!" << endl;
		this->Save();
	}
	else
	{
		cout << "输入有误" << endl;
	}

	system("read -p '请按任意键继续...' var");
	system("clear");
}

void Interface::Save()
{
	ofstream ofs;
	ofs.open(FILENAME,ios::out);
	
	for(int i = 0; i < this->m_employee_number; i++)
	{
		ofs << this->m_employee_array[i]->m_id << " "
			<< this->m_employee_array[i]->m_name << " "
			<< this->m_employee_array[i]->m_department << endl;
	}

	ofs.close();
}

int Interface::GetNumber()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	
	int id;
	string name;
	int department;
	int number = 0;

	while(ifs>>id && ifs>> name && ifs>>department)
	{
		number++;
	}
	return number;
}

void Interface::InitializeEmployee()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);

	int id;
	string name;
	int department;
	int index = 0;

	while(ifs>>id && ifs>>name && ifs>>department)
	{
		Worker*worker = NULL;
		if(department == 1)
		{
			worker = new Employee(id, name, department);
		}
		else if(department == 2)
		{
			worker = new Manager(id, name, department);
		}
		else
		{
			worker = new Boss(id, name, department);
		}
		this->m_employee_array[index] = worker;
		index++;
	}

	ifs.close();
}

void Interface::ShowEmployee()
{
	if(this->m_file_is_empty)
	{
		cout << "文件不存在或记录为空!" << endl;
	}
	else
	{
		for(int i = 0; i < m_employee_number; i++)
		{
			this->m_employee_array[i]->ShowInfo();
		}
	}

	system("read -p '请按任意键继续...' var");
	system("clear");
}

int Interface::IsExist(int id)
{
	int index = -1;
	
	for(int i = 0; i < this-> m_employee_number; i++)
	{
		if(this->m_employee_array[i]->m_id == id)
		{
			index = i;
			break;
		}
	}

	return index;
}

void Interface::ModifyEmployee()
{
	if(m_file_is_empty)
	{
		cout << "文件不存在或记录为空!" << endl;
	}
	else
	{
		cout << "请输入修改职工的编号: ";
		int id;
		cin >> id;

		int index = this->IsExist(id);
		if(index != -1)
		{
			delete this->m_employee_array[index];

			int new_id = 0;
			string new_name = "";
			int new_department = 0;

			cout << "查到: " << id << "号职工, 请输入新职工号: " << endl;
			cin >> new_id;
			cout << "请输入新的姓名: " << endl;
			cin >> new_name;
			cout << "请输入新的岗位: " << endl;
			cin >> new_department;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			
			Worker*worker = NULL;
			switch(new_department)
			{
				case 1:
					worker = new Employee(new_id, new_name, new_department);
					break;
				case 2:
					worker = new Manager(new_id, new_name, new_department);
					break;
				case 3:
					worker = new Boss(new_id, new_name, new_department);
					break;
				default:
					break;
			}

			this->m_employee_array[index] = worker;
			cout << "修改成功!" << endl;
			
			this->Save();
		}
		else
		{
			cout << "修改失败, 查无此人!" << endl;
		}
	}

	system("read -p '请按任意键继续...' var");
	system("clear");
}

void Interface::DelEmployee()
{
	if(this->m_file_is_empty)
	{
		cout  << "文件不存在或记录为空!" << endl;
	}
	else
	{
		cout << "请输入想要删除的职工编号: ";
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if(index != -1)
		{
			for(int i = index; i < this->m_employee_number-1; i++)
			{
				this->m_employee_array[i] = this->m_employee_array[i+1];
			}
			this->m_employee_number--;
			this->Save();
			cout << "删除成功!" << endl;
		}
		else
		{
			cout << "删除失败, 未找到该职工" << endl;
		}
	}

	system("read -p '请按任意键继续...' var");
	system("clear");
}

void Interface::FindEmployee()
{
	if(this->m_file_is_empty)
	{
		cout  << "文件不存在或记录为空!" << endl;
	}
	else
	{
		cout << "请输入查找的方式: " << endl;
		cout << "1.按职工编号查找" << endl;
		cout << "2.按职工姓名查找" << endl;
	}

	int select = 0;
	cin >> select;
	if(select == 1)
	{
		cout << "请输入想要查找的职工编号: ";
		int id = 0;
		cin >> id;

		int ret = IsExist(id);
		if(ret != -1)
		{
			cout << "查找成功! 该职工的信息如下: " << endl;
			this->m_employee_array[ret]->ShowInfo();
		}
		else
		{
			cout << "查询失败, 未找到该职工" << endl;
		}
	}
	else if(select == 2)
	{
		cout << "请输入想要查找的职工姓名: ";
		string name;
		cin >> name;

		bool flag = false;

		for(int i = 0; i < m_employee_number; i++)
		{
			if(this->m_employee_array[i]->m_name == name)
			{
				cout << "查找成功! 该职工的信息如下: " << endl;
				this->m_employee_array[i]->ShowInfo();
				flag = true;
			}
		}
		if(flag == false)
		{
			cout << "查询失败, 未找到该职工" << endl;
		}
	}
	else
	{
		cout << "输入选项有误!" << endl;
	}

	system("read -p '请按任意键继续...' var");
	system("clear");
}

void Interface::SortEmployee()
{
	if(this->m_file_is_empty)
	{
		cout  << "文件不存在或记录为空!" << endl;

		system("read -p '请按任意键继续...' var");
		system("clear");
	}
	else
	{
		cout << "请选择排序的方式: " << endl;
		cout << "1.按职工编号进行升序" << endl;
		cout << "2.按职工编号进行降序" << endl;
	}

	int select = 0;
	cin >> select;
	for(int i = 0;i < m_employee_number; i++)
	{
		int max_or_min = i;
		for(int j = i+1; j < this->m_employee_number; j++)
		{
			if(select == 1)
			{
				if(this->m_employee_array[max_or_min]->m_id > this->m_employee_array[j]->m_id)
				{
					max_or_min = j;
				}
			}
			else if(select == 2)
			{
				if(this->m_employee_array[max_or_min]->m_id < this->m_employee_array[j]->m_id)
				{
					max_or_min = j;
				}
			}
			else
			{
				cout << "输入选项有误!" << endl;
				return;	
			}
		}
		if(i != max_or_min)
		{
			Worker*temp = this->m_employee_array[i];
			this->m_employee_array[i] = this->m_employee_array[max_or_min];
			this->m_employee_array[max_or_min] = temp;
		}
	}	

	cout << "排序成功! 排序后的结果为: " << endl;
	this->Save();
	this->ShowEmployee();
}

void Interface::CleanFile()
{
	cout << "确定清空吗? " << endl;
	cout << "1.确定" << endl;
	cout << "2.返回" << endl;

	int select = 0;
	cin >> select;

	if(select == 1)
	{
		ofstream ofs(FILENAME,ios::trunc);
		ofs.close();

		if(this->m_employee_array != NULL)
		{
			for(int i = 0; i < this->m_employee_number; i++)
			{
				delete this->m_employee_array[i];
				this->m_employee_array[i] = NULL;
			}

			delete[] this->m_employee_array;
			this->m_employee_array = NULL;
			this->m_employee_number = 0;
			this->m_file_is_empty = true;
		}

		cout << "清空成功!" << endl;

		system("read -p '请按任意键继续...' var");
		system("clear");
	}
	else
	{
		return;
	}
}

Interface::~Interface()
{
	delete[] this->m_employee_array;
	this->m_employee_array = NULL;
}

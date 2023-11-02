#include "Manager.h"

Manager::Manager()
{

}

Manager::Manager(string name, string pwd)
{
	this->m_name = name;
	this->m_pwd = pwd;
	this->InitializeVector();
	
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while(ifs >> com.c_id && ifs >> com.m_maxnum)
	{
		v_computer_room.push_back(com);
	}

	ifs.close();

	cout << "机房的数量为: " << v_computer_room.size() << endl;
}

void Manager::AddPerson()
{
	cout << "请输入您要添加账号的类型:" << endl;
	cout << "1.添加学生" << endl;
	cout << "2.添加老师" << endl;
	cout << "请选择: ";

	string file_name;
	string tip;
	string error_tip;

	ofstream ofs;

	int select = 0;
	cin >> select;

	if(select == 1)
	{
		file_name = STUDENT_FILE;
		tip = "请输入您的学号: ";
		error_tip = "学号重复, 请重新输入: ";
	}
	else
	{
		file_name = TEACHER_FILE;
		tip = "请输入您的职工号: ";
		error_tip = "职工号重复, 请重新输入: ";
	}

	ofs.open(file_name, ios::out | ios::app);

	int id;
	string name;
	string pwd;

	cout << tip;
	while(true)
	{
		cin >> id;
		bool ret = CheckRepeat(id, select);
		if(ret)
		{
			cout << error_tip;
		}
		else
		{
			break;
		}
	}

	cout << "请输入您的姓名: ";
	cin >> name;
	cout << "请输入您的密码: ";
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << endl;
	cout << "添加成功!" << endl;

    system("read -p '请按回车键继续...' var");
	system("clear");

	this->InitializeVector();
}

void Manager::OpenMenu()
{
	cout << "================== 欢迎管理员:" << this->m_name << "登陆 ==================" << endl;
	cout << "\t\t--------------------------\n";
	cout << "\t\t|                        |" << endl;
	cout << "\t\t|       1.添加账号       |" << endl;
	cout << "\t\t|                        |" << endl;
	cout << "\t\t|       2.查看账号       |" << endl;
	cout << "\t\t|                        |" << endl;
	cout << "\t\t|       3.查看机房       |" << endl;
	cout << "\t\t|                        |" << endl;
	cout << "\t\t|       4.清空预约       |" << endl;
	cout << "\t\t|                        |" << endl;
	cout << "\t\t|       0.注销登陆       |" << endl;
	cout << "\t\t|                        |" << endl;
	cout << "\t\t--------------------------\n";
	cout << "请输入您的选择: ";
}

void PrintStudent(Student&s)
{
	cout << "学号: " << s.s_id
		 << "\t\t姓名: " << s.m_name
		 << "\t\t密码: " << s.m_pwd << endl;
}

void PrintTeacher(Teacher&t)
{
	cout << "职工号: " << t.t_id
		 << "\t\t姓名: " << t.m_name
		 << "\t\t密码: " << t.m_pwd << endl;
}

void Manager::ShowPerson()
{
	cout << "请选择查看内容:" << endl;
	cout << "1.查看所有学生" << endl;
	cout << "2.查看所有老师" << endl;
	cout << "请选择: ";

	int select = 0;
	cin >> select;

	if(select == 1)
	{
		cout << "所有学生信息如下:" << endl;
		for_each(v_student.begin(), v_student.end(), PrintStudent);
	}
	else
	{
		cout << "所有老师信息如下:" << endl;
		for_each(v_teacher.begin(), v_teacher.end(), PrintTeacher);
	}

    system("read -p '请按回车键继续...' var");
	system("clear");
}

void Manager::ShowComputer()
{
	cout << "所有机房信息如下:" << endl;
	for(vector<ComputerRoom>::iterator it = v_computer_room.begin(); it != v_computer_room.end(); it++)
	{
		cout << "机房编号: " << it->c_id
			 << "\t\t机房最大容量: " << it->m_maxnum << endl;
	}

    system("read -p '请按回车键继续...' var");
	system("clear");
}

void Manager::CleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空成功!" << endl;

    system("read -p '请按回车键继续...' var");
	system("clear");
}

void Manager::InitializeVector()
{
	v_student.clear();
	v_teacher.clear();

	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if(!ifs.is_open())
	{
		cout << "文件读取失败!" << endl;
		return;
	}

	Student s;
	while(ifs >> s.s_id && ifs >> s.m_name && ifs >> s.m_pwd)
	{
		v_student.push_back(s);
	}

	//test code
	cout << "当前学生数量为: " << v_student.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while(ifs >> t.t_id && ifs >> t.m_name && ifs >> t.m_pwd)
	{
		v_teacher.push_back(t);
	}

	//test code
	cout << "当前老师数量为: " << v_teacher.size() << endl;
	ifs.close();
}

bool Manager::CheckRepeat(int id, int type)
{
	if(type == 1)
	{
		for(vector<Student>::iterator it = v_student.begin(); it != v_student.end(); it++)
		{
			if(id == it->s_id)
			{
				return true;
			}
		}
	}
	else if(type == 2)
	{
		for(vector<Teacher>::iterator it = v_teacher.begin(); it != v_teacher.end(); it++)
		{
			if(id == it->t_id)
			{
				return true;
			}
		}
	}

	return false;
}

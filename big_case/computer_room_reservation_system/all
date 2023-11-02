#include <iostream>
#include "Identity.h"
#include <fstream>
#include <string>
#include "GlobalFile.h"
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"

using namespace std;

void StudentMenu(Identity*&student)
{
    while(true)
    {
        student->OpenMenu();
        Student*stu = (Student*)student;

        int select = 0;
        cin >> select;

        if(select == 1)
        {
            stu->ApplyOrder();
        }
        else if(select == 2)
        {
            stu->ShowMyOrder();
        }
        else if(select == 3)
	    {
            stu->ShowAllOrder();
        }
		else if(select == 4)
        {
            stu->CancelOrder();
        }
        else
        {
            delete student;
            cout << "注销成功!" << endl;

            system("read -p '请按回车键继续...' var");
            system("clear");

            return;
        }
    }
}

void TeacherMenu(Identity*&teacher)
{
    while(true)
    {
        teacher->OpenMenu();
        Teacher*tea = (Teacher*)teacher;

        int select = 0;
        cin >> select;

        if(select == 1)
        {
            tea->ShowAllOrder();
        }
        else if(select == 2)
        {
            tea->ValidOrder();
        }
        else
        {
            delete teacher;
            cout << "注销成功!" << endl;

            system("read -p '请按回车键继续...' var");
            system("clear");

            return;
        }
    }
}

void ManagerMenu(Identity*&manager)
{
    while(true)
    {
        manager->OpenMenu();
        Manager*man = (Manager*)manager;

        int select = 0;
        cin >> select;

        if(select == 1)
        {
            man->AddPerson();
        }
        else if(select == 2)
        {
            man->ShowPerson();
        }
        else if(select == 3)
	    {
            man->ShowComputer();
        }
		else if(select == 4)
        {
            man->CleanFile();
        }
        else
        {
            delete manager;
            cout << "注销成功!" << endl;

            system("read -p '请按回车键继续...' var");
            system("clear");

            return;
        }
    }
}

void LoginIn(string FileName, int type)
{
	Identity*person = NULL;

	ifstream ifs;
	ifs.open(FileName, ios::in);

	if(!ifs.is_open())
	{
		cout << "文件不存在!" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if(type == 1)
	{
		cout << "请输入您的学号: ";
		cin >> id;
	}
	else if(type == 2)
	{
		cout << "请输入您的职工号: ";
		cin >> id;
	}

	cout << "请输入您的用户名: ";
	cin >> name;

	cout << "请输入您的密码: ";
	cin >> pwd;

	if(type == 1)
	{
		int file_id;
		string file_name;
		string file_pwd;

		while(ifs >> file_id && ifs >> file_name && ifs >> file_pwd)
		{
			if(file_id == id && file_name == name && file_pwd == pwd)
			{
				//tesst code
				/*cout << file_id << endl;
				cout << file_name << endl;
				cout << file_pwd << endl;
				cout << endl;*/

				cout << "学生验证登陆成功!" << endl;

				system("read -p '请按回车键继续...' var");
				system("clear");

				person = new Student(id, name, pwd);

				StudentMenu(person);

				return;
			}
		}
	}
	else if(type == 2)
	{
		int file_id;
		string file_name;
		string file_pwd;

		while(ifs >> file_id && ifs >> file_name && ifs >> file_pwd)
		{
			if(file_id == id && file_name == name && file_pwd == pwd)
			{
				cout << "老师验证登陆成功!" << endl;

				system("read -p '请按回车键继续...' var");
				system("clear");

				person = new Teacher(id, name, pwd);

				TeacherMenu(person);

				return;
			}
		}
	}
	else if(type == 3)
	{
		string file_name;
		string file_pwd;

		while(ifs >> file_name && ifs >> file_pwd)
		{
			if(file_name == name && file_pwd == pwd)
			{
				cout << "管理员验证登陆成功!" << endl;

				system("read -p '请按回车键继续...' var");
				system("clear");

				person = new Manager(name, pwd);

				ManagerMenu(person);

				return;
			}
		}

	}

	cout << "验证登陆失败!" << endl;
	system("read -p '请按回车键继续...' var");
	system("clear");

	return ;
}

int main()
{
	int select = 0;

	while(true)
	{
		cout << "================== 欢迎来到机房预约系统 ==================" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t--------------------------\n";
		cout << "\t\t|                        |" << endl;
		cout << "\t\t|       1.学生代表       |" << endl;
		cout << "\t\t|                        |" << endl;
		cout << "\t\t|       2.老    师       |" << endl;
		cout << "\t\t|                        |" << endl;
		cout << "\t\t|       3.管 理 员       |" << endl;
		cout << "\t\t|                        |" << endl;
		cout << "\t\t|       0.退    出       |" << endl;
		cout << "\t\t|                        |" << endl;
		cout << "\t\t--------------------------\n";
		cout << "请输入您的选择: ";
		cin >> select;

		switch(select)
		{
			case 1:
				LoginIn(STUDENT_FILE, 1);
				break;
			case 2:
				LoginIn(TEACHER_FILE, 2);
				break;
			case 3:
				LoginIn(ADMIN_FILE, 3);
				break;
			case 0:
				cout << "欢迎您下一次的使用!" << endl;
				system("read -p '请按回车键继续...' var");
				return 0;
				break;
			default:
				cout << "您的输入有误, 请重新选择!" << endl;
				system("read -p '请按回车键继续...' var");
				break;
		}
	}

	system("read -p '请按回车键继续...' var");

	return 0;
}

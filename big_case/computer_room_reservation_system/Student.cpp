#include "Student.h"

Student::Student()
{

}

Student::Student(int id, string name, string pwd)
{
	this->s_id = id;
	this->m_name = name;
	this->m_pwd = pwd;

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while(ifs >> com.c_id && ifs >> com.m_maxnum)
	{
		v_computer_room.push_back(com);
	}

	ifs.close();
}

void Student::OpenMenu()
{
    cout << "================== 欢迎学生:" << this->m_name << "登陆 ==================" << endl;
    cout << "\t\t---------------------------\n";
    cout << "\t\t|                         |" << endl;
    cout << "\t\t|       1.申请预约        |" << endl;
    cout << "\t\t|                         |" << endl;
    cout << "\t\t|       2.查看我的预约    |" << endl;
    cout << "\t\t|                         |" << endl;
    cout << "\t\t|       3.查看所有预约    |" << endl;
    cout << "\t\t|                         |" << endl;
    cout << "\t\t|       4.取消预约        |" << endl;
    cout << "\t\t|                         |" << endl;
    cout << "\t\t|       0.注销登陆        |" << endl;
    cout << "\t\t|                         |" << endl;
    cout << "\t\t---------------------------\n";
    cout << "请输入您的选择: ";
}

void Student::ApplyOrder()
{
	int date = 0;
	int interval = 0;
	int room = 0;

	cout << "机房开放时间为周一至周五!" << endl;
	cout << "请输入您申请预约的时间:" << endl;
	cout << "1.周一" << endl;
	cout << "2.周二" << endl;
	cout << "3.周三" << endl;
	cout << "4.周四" << endl;
	cout << "5.周五" << endl;
	while(true)
	{
		cout << "请输入您的选择: ";
		cin >> date;
		if(date >= 1 && date <= 5)
		{
			break;
		}
		cout << "您的输入有误, 请您重新输入" << endl;
	}

	cout << "请输入您申请预约的时间段:" << endl;
	cout << "1.上午" << endl;
	cout << "2.下午" << endl;
	while(true)
	{
		cout << "请输入您的选择: ";
		cin >> interval;
		if(interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "您的输入有误, 请您重新输入" << endl;
	}

	cout << "请您选择机房:" << endl;
	for(int i = 0; i < v_computer_room.size(); i++)
	{
		cout << v_computer_room[i].c_id << "号机房容量为: " << v_computer_room[i].m_maxnum << endl;
	}
	while(true)
	{
		cout << "请输入您的选择: ";
		cin >> room;
		if(room >= 1 && room <= 3)
		{
			break;
		}
		cout << "您的输入有误, 请您重新输入" << endl;
	}

	cout << "预约成功! 审核中～" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);

	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "s_id:" << s_id << " ";
	ofs << "m_name:" << m_name << " ";
	ofs << "room:" << room<< " ";
	ofs << "status:" << 1 << endl;

	ofs.close();

	system("read -p '请按回车键继续...' var");
    system("clear");
}

void Student::ShowMyOrder()
{
	OrderFile of;

	if(of.m_size == 0)
	{
		cout << "无预约记录!" << endl;

		system("read -p '请按回车键继续...' var");
		system("clear");

		return;
	}

	for(int i = 0; i < of.m_size; i++)
	{
		if(this->s_id == atoi(of.m_order_data[i]["s_id"].c_str()))
		{
			cout << "预约日期: 周" << of.m_order_data[i]["date"];
			cout << "\t时间段: " << (of.m_order_data[i]["interval"] == "1" ? "上午" : "下午");
			cout << "\t机房号: " << of.m_order_data[i]["room"];
			string status = "\t状态: ";
			//1.审核中 2.预约成功 -1.预约失败, 审核未通过 0.预约已取消
			if(of.m_order_data[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if(of.m_order_data[i]["status"] == "2")
			{
				status += "预约成功";
			}
			else if(of.m_order_data[i]["status"] == "-1")
			{
				status += "预约失败, 审核未通过";
			}
			else
			{
				status += "预约已取消";
			}

			cout << status << endl;
		}
	}

	system("read -p '请按回车键继续...' var");
    system("clear");
}

void Student::ShowAllOrder()
{
	OrderFile of;

	if(of.m_size == 0)
	{
		cout << "无预约记录!" << endl;

		system("read -p '请按回车键继续...' var");
		system("clear");

		return;
	}

	for(int i = 0; i < of.m_size; i++)
	{
		cout << i + 1 << "、";
		cout << "预约日期: 周" << of.m_order_data[i]["date"];
		cout << "\t时间段: " << (of.m_order_data[i]["interval"] == "1" ? "上午" : "下午");
		cout << "\t机房号: " << of.m_order_data[i]["room"];
		cout << "\t学号: " << of.m_order_data[i]["s_id"];
		cout << "\t姓名: " << of.m_order_data[i]["m_name"];
		string status = "\t状态: ";
		//1.审核中 2.预约成功 -1.预约失败, 审核未通过 0.预约已取消
		if(of.m_order_data[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if(of.m_order_data[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if(of.m_order_data[i]["status"] == "-1")
		{
			status += "预约失败, 审核未通过";
		}
		else
		{
			status += "预约已取消";
		}

		cout << status << endl;
	}

	system("read -p '请按回车键继续...' var");
    system("clear");
}

void Student::CancelOrder()
{
	OrderFile of;

	if(of.m_size == 0)
	{
		cout << "无预约记录!" << endl;

		system("read -p '请按回车键继续...' var");
		system("clear");

		return;
	}

	cout << "审核中或预约成功的记录可以取消, 请输入您要取消的记录" << endl;

	vector<int> v;
	int index = 1;
	for(int i = 0; i < of.m_size; i++)
	{
		if(this->s_id == atoi(of.m_order_data[i]["s_id"].c_str()))
		{
			if(of.m_order_data[i]["status"] == "1" || of.m_order_data[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "、";
				cout << "预约日期: 周" << of.m_order_data[i]["date"];
				cout << "\t时间段: " << (of.m_order_data[i]["interval"] == "1" ? "上午" : "下午");
				cout << "\t机房号: " << of.m_order_data[i]["room"];
				string status = "\t状态: ";
				//1.审核中 2.预约成功 -1.预约失败, 审核未通过 0.预约已取消
				if(of.m_order_data[i]["status"] == "1")
				{
					status += "审核中";
				}
				else if(of.m_order_data[i]["status"] == "2")
				{
					status += "预约成功";
				}

				cout << status << endl;
			}
		}
	}

	cout << "请输入您要取消的预约记录, 0代表返回: ";
	int select = 0;
	while(true)
	{
		cin >> select;

		if(select >= 0 && select <= v.size())
		{
			if(select == 0)
			{
				break;
			}
			else
			{
				of.m_order_data[v[select - 1]]["status"] = "0";
				of.UpdateOrder();

				cout << "已取消预约!" << endl;

				break;
			}
		}

		cout << "输入有误, 请重新输入" << endl;
	}

	system("read -p '请按回车键继续...' var");
	system("clear");
}

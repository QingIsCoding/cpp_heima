#include "Teacher.h"

Teacher::Teacher()
{

}
        
Teacher::Teacher(int id, string name, string pwd)
{
	this->t_id = id;
	this->m_name = name;
	this->m_pwd = pwd;
}

void Teacher::OpenMenu()
{
	cout << "================== 欢迎教师:" << this->m_name << "登陆 ==================" << endl;
    cout << "\t\t---------------------------\n";
    cout << "\t\t|                         |" << endl;
    cout << "\t\t|       1.查看所有预约    |" << endl;
    cout << "\t\t|                         |" << endl;
    cout << "\t\t|       2.审核预约        |" << endl;
    cout << "\t\t|                         |" << endl;
    cout << "\t\t|       0.注销登陆        |" << endl;
    cout << "\t\t|                         |" << endl;
    cout << "\t\t---------------------------\n";
    cout << "请输入您的选择: ";
}

void Teacher::ShowAllOrder()
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
        cout << "\t\t时间段: " << (of.m_order_data[i]["interval"] == "1" ? "上午" : "下午");
        cout << "\t\t机房号: " << of.m_order_data[i]["room"];
        cout << "\t\t学号: " << of.m_order_data[i]["s_id"];
        cout << "\t\t姓名: " << of.m_order_data[i]["m_name"];
        string status = "\t\t状态: ";
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

void Teacher::ValidOrder()
{
	OrderFile of;

    if(of.m_size == 0)
    {
        cout << "无预约记录!" << endl;

        system("read -p '请按回车键继续...' var");
        system("clear");

        return;
    }
	
	cout << "待审核的预约纪录如下" << endl;

	vector<int> v;
	int index = 0;
	for(int i = 0; i < of.m_size; i++)
	{
		if(of.m_order_data[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << "、";
			cout << "预约日期: 周" << of.m_order_data[i]["date"];
			cout << "\t时间段: " << (of.m_order_data[i]["interval"] == "1" ? "上午" : "下午");
			cout << "\t机房号: " << of.m_order_data[i]["room"];
			cout << "\t学号: " << of.m_order_data[i]["s_id"];
			cout << "\t姓名: " << of.m_order_data[i]["m_name"];
			string status = "\t状态: 审核中";
			cout << status << endl;
		}
	}

	cout << "请输入您要审核的预约记录, 0代表返回" << endl;
	int select = 0;
	int ret = 0;
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
				cout << "请输入您的审核结果:" << endl;
				cout << "1.通过" << endl;
				cout << "2.不通过" << endl;
				cin >> ret;
				if(ret == 1)
				{
					of.m_order_data[v[select - 1]]["status"] = "2";
				}
				else
				{
					of.m_order_data[v[select - 1]]["status"] = "-1";
				}
				of.UpdateOrder();

                cout << "已审核完毕!" << endl;

                break;
            }
        }

        cout << "输入有误, 请重新输入" << endl;
	}

	system("read -p '请按回车键继续...' var");
	system("clear");
}

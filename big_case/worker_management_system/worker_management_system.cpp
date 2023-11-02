#include "Interface.h"
/*#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"*/
using namespace std;

int main()
{	//test code
	/*Worker*worker = NULL;
	worker = new Employee(1, "张三", 1);
	worker->ShowInfo();
	delete worker;

	worker = new Manager(2, "李四", 2);
	worker->ShowInfo();
	delete worker;

	worker = new Boss(3, "王五", 3);
	worker->ShowInfo();
	delete worker;*/
	
	Interface wm;
	int choice = 0;
	while(true)
	{
		wm.ShowMenu();
		cout << "请输入您的选择: ";
		cin >> choice;
		
		switch(choice)
		{
			case 0:
				wm.ExitSystem();
				break;
			case 1:
				wm.AddEmployee();
				break;
			case 2:
				wm.ShowEmployee();
				break;
			case 3:
				//test code
				/*{
					int ret = wm.IsExist(1);
					if(ret != -1)
					{
						cout << "职工存在" << endl;
					}
					else
					{
						cout << "职工不存在" << endl;
					}
					break;
				}*/
				wm.DelEmployee();
				break;
			case 4:
				wm.ModifyEmployee();
				break;
			case 5:
				wm.FindEmployee();
				break;
			case 6:
				wm.SortEmployee();
				break;
			case 7:
				wm.CleanFile();
				break;
			default:
				system("clear");
		}
	}

	return 0;
}

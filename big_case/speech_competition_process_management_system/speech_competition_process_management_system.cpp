#include <iostream>
#include "SpeechManager.h"
#include <string>

using namespace std;

int main()
{
	SpeechManager sm;
	//test code
	/*for(map<int,Speaker>::iterator it = sm.m_speaker.begin(); it != sm.m_speaker.end(); it++)
	{
		cout << "选手编号: " << it->first
			 << "姓名: "     << it->second.m_name
			 << "分数: "     << it->second.m_score[0] << endl;
	}*/

	int choice = 0;

	while(true)
	{
		sm.ShowMenu();

		cout << "请输入您的选择: " << endl;
		cin >> choice;

		switch(choice)
		{
			case 1:
				sm.StartSpeech();
				break;
			case 2:
				sm.ShowRecord();
				break;
			case 3:
				sm.ClearRecord();
				break;
			case 0:
				sm.ExitSystem();
				break;
			default:
				system("clear");
				break;
		}
	}

	return 0;
}

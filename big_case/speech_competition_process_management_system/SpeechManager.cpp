#include "SpeechManager.h"

SpeechManager::SpeechManager()
{
	this->InitializeSpeech();
	this->CreateSpeaker();
	this->LoadRecord();
}

void SpeechManager::ShowMenu()
{
	cout << "**********************************************" << endl;
	cout << "***************欢迎参加演讲比赛***************" << endl;
	cout << "*************** 1.开始演讲比赛 ***************" << endl;
	cout << "*************** 2.查看往届记录 ***************" << endl;
	cout << "*************** 3.清空比赛记录 ***************" << endl;
	cout << "*************** 0.退出比赛程序 ***************" << endl;
	cout << "**********************************************" << endl;
}

void SpeechManager::ExitSystem()
{
	cout << "欢迎下次使用!" << endl;
	exit(0);
}

void SpeechManager::InitializeSpeech()
{
	this->v1.clear();
	this->v2.clear();
	this->v_victory.clear();
	this->m_speaker.clear();
	this->m_index = 1;
	this->m_record.clear();
}

void SpeechManager::CreateSpeaker()
{
	string name_seed = "ABCDEFGHIJKL";
	for(int i = 0; i < name_seed.size(); i++)
	{
		string name = "选手";
		name += name_seed[i];

		Speaker sp;
		sp.m_name = name;

		for(int j = 0; j < 2; j++)
		{
			sp.m_score[j] = 0;
		}

		this->v1.push_back(i + 10001);
		this->m_speaker.insert(make_pair(i + 10001, sp));
	}
}

void SpeechManager::StartSpeech()
{
	srand((unsigned int)time(NULL));

	this->SpeechDraw();	
	this->SpeechContest();
	this->ShowScore();

	this->m_index++;
	this->SpeechDraw();	
	this->SpeechContest();
	this->ShowScore();
	
	this->SaveRecord();
	
	this->InitializeSpeech();
	this->CreateSpeaker();
	this->LoadRecord();

	cout << "----------本届比赛完毕!----------" << endl;
	system("read -p '请按任意键继续...' var");
	system("clear");
}

void SpeechManager::SpeechDraw()
{
	cout << "第<<" << this->m_index << ">>轮比赛选手正在抽签" << endl;
	cout << "---------------------------------------------------" << endl;
	cout << "抽签后的演讲顺序如下:" << endl;

	if(this->m_index == 1)
	{
		random_shuffle(v1.begin(), v1.end());
		for(vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());
		for(vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
	}
	cout << endl;

	cout << "---------------------------------------------------" << endl;
	system("read -p '请按任意键继续...' var");
}

void SpeechManager::SpeechContest()
{
	cout << "----------第" << this->m_index << "轮比赛正式开始----------" << endl;

	multimap<double,int,greater<double>> group_score;

	int num = 0;

	vector<int> v_competitor;
	if(this->m_index == 1)
	{
		v_competitor = v1;
	}
	else
	{
		v_competitor = v2;
	}

	for(vector<int>::iterator it = v_competitor.begin(); it != v_competitor.end(); it++)
	{
		num++;

		deque<double> d;
		for(int i = 0; i < 10; i++)
		{
			double score = (rand()%401 + 600) / 10.f;
			//test code
			//cout << score << "\t";
			d.push_back(score);
		}
		
		sort(d.begin(), d.end(), greater<double>());
		d.pop_front();
		d.pop_back();

		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size();
	
		//test code
		/*cout << "编号: " << *it 
			 << "\t姓名: " << this->m_speaker[*it].m_name 
			 << "\t获取平均分: " << avg << endl;*/
		
		//m_speaker<int(key,*it),Speaker(value)>
		//*it是对m_speaker(map类型)的key值, 即it(vector类型)的解引用, 得到map的key值, 从而map[key]得到value值
		this->m_speaker[*it].m_score[this->m_index - 1] = avg;

		group_score.insert(make_pair(avg,*it));

		if(num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名次: " << endl;

			for(multimap<double,int,greater<double>>::iterator it = group_score.begin(); 
				it != group_score.end(); it++)
			{
					cout << "编号: " << it->second 
						 << "\t姓名: " << this->m_speaker[it->second].m_name
						 << "\t成绩: " << this->m_speaker[it->second].m_score[this->m_index - 1] << endl;
			}

			int count = 0;
			for(multimap<double,int,greater<double>>::iterator it = group_score.begin(); 
				it != group_score.end() && count < 3; it++, count++)
			{
				if(this->m_index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					v_victory.push_back((*it).second);
				}
			}

			group_score.clear();
		}

	}

	cout << "----------第" << this->m_index << "轮比赛完毕!----------" << endl;
	system("read -p '请按任意键继续...' var");
}

void SpeechManager::ShowScore()
{
	cout << "----------第" << this->m_index << "轮晋级选手信息如下: ----------" << endl;

	vector<int> v;
	if(this->m_index == 1)
	{
		v = v2;
	}
	else
	{
		v = v_victory;
	}

	for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "选手编号: " << *it << "\t姓名: " << this->m_speaker[*it].m_name
			 << "\t得分: " << this->m_speaker[*it].m_score[this->m_index - 1] << endl;
	}

	cout << "---------------------------------------------------" << endl;
	system("read -p '请按任意键继续...' var");
	system("clear");
	this->ShowMenu();
}

void SpeechManager::SaveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);

	for(vector<int>::iterator it = v_victory.begin(); it != v_victory.end(); it++)
	{
		ofs << *it << "," << this->m_speaker[*it].m_score[1] << ",";
	}
	ofs << endl;

	ofs.close();
	cout << "记录已经保存" << endl;

	this->FileIsEmpty = false;
}

void SpeechManager::LoadRecord()
{
	ifstream ifs("speech.csv", ios::in);
	if(!ifs.is_open())
	{
		this->FileIsEmpty = true;
		//test code
		//cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if(ifs.eof())
	{
		//test code
		//cout << "文件为空" << endl;
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}

	this->FileIsEmpty = false;
	ifs.putback(ch);
	string data;
	int index = 0;

	while(ifs >> data)
	{	
		vector<string> v;

		//test code
		//cout << data << endl;
		int pos = -1;
		int start = 0;

		while(true)
		{
			pos = data.find(",", start);

			if(pos == -1)
			{
				break;	
			}

			string tmp = data.substr(start, pos - start);
			//test code
			//cout << tmp << endl;
			v.push_back(tmp);
			start = pos + 1;
		}

		this->m_record.insert(make_pair(index,v));
		index++;
	}

	ifs.close();
}

void SpeechManager::ShowRecord()
{
	if(this->FileIsEmpty)
	{
		cout << "文件不存在, 或文件为空" << endl;
	}
	/*for(map<int,vector<string>>::iterator it = m_record.begin(); it != m_record.end(); it++)
	{
		cout << "第" << it->first + 1
			 << "届冠军编号: " << it->second[0] 
			 << "\t分数: " << it->second[1] << endl;
	}*/
	//与上面一样, 但上面每次都打印"冠"军编号
	else
	{
		for(int i = 0; i < this->m_record.size(); i++)
		{
			cout << "第" << i + 1 << "届:" 
				 << "\t冠军编号: " << this->m_record[i][0] 
				 << "\t分数: " << this->m_record[i][1] << " "
				 << "\t亚军编号: " << this->m_record[i][2] 
				 << "\t分数: " << this->m_record[i][3] << " "
				 << "\t季军编号: " << this->m_record[i][4] 
				 << "\t分数: " << this->m_record[i][5] << endl;
		}
	}
	cout << "---------------------------------------------------" << endl;
	system("read -p '请按任意键继续...' var");
	system("clear");
}

void SpeechManager::ClearRecord()
{
	cout << "是否确认清空文件?" << endl;
	cout << "1.是" << endl;
	cout << "2.否" << endl;

	int select = 0;
	cin >> select;

	if(select == 1)
	{
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		this->InitializeSpeech();
		this->CreateSpeaker();
		this->LoadRecord();

		cout << "文件清空成功!" << endl;
	}

	system("read -p '请按任意键继续...' var");
	system("clear");
}

SpeechManager::~SpeechManager()
{

}

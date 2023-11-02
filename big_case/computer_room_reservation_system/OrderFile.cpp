#include "OrderFile.h"

OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;
	string interval;
	string s_id;
	string m_name;
	string room;
	string status;

	this->m_size = 0;

	while(ifs >> date && ifs >> interval && ifs >> s_id &&
		  ifs >> m_name && ifs >> room && ifs >> status)
	{
		//test code
		/*cout << date << endl;	
		cout << interval << endl;
		cout << s_id << endl;
		cout << m_name << endl;
		cout << room << endl;
		cout << status << endl;
		cout << endl;*/

		string key;
		string value;
		map<string,string> m;

		int pos = date.find(":");
		if(pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);

			m.insert(make_pair(key, value));

			//test code
			/*cout << "key: " << key << endl;
			cout << "value: " << value << endl;*/
		}

		pos = interval.find(":");
		if(pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		pos = s_id.find(":");
		if(pos != -1)
		{
			key = s_id.substr(0, pos);
			value = s_id.substr(pos + 1, s_id.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		pos = m_name.find(":");
		if(pos != -1)
		{
			key = m_name.substr(0, pos);
			value = m_name.substr(pos + 1, m_name.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		pos = room.find(":");
		if(pos != -1)
		{
			key = room.substr(0, pos);
			value = room.substr(pos + 1, room.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		pos = status.find(":");
		if(pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		this->m_order_data.insert(make_pair(this->m_size, m));
		this->m_size++;
	}

	ifs.close();

	//test code
	/*for(map<int,map<string,string>>::iterator it = m_order_data.begin(); it != m_order_data.end(); it++)
	{
		cout << "key1(条数):\n" << it->first << endl;
		cout << "value1:\n";
		for(map<string,string>::iterator mit = (*it).second.begin(); mit != it->second.end(); mit++)
		{
			cout << "\tkey2: " << mit->first
				 << "\tvalue2: " << mit->second << endl;
		}
		cout << endl;
	}*/
}

void OrderFile::UpdateOrder()
{
	if(this->m_size == 0 )
	{
		return;
	}

	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for(int i = 0; i < this->m_size; i++)
	{
		ofs << "date:" << this->m_order_data[i]["date"] << " ";
		ofs << "interval:" << this->m_order_data[i]["interval"] << " ";
		ofs << "s_id:" << this->m_order_data[i]["s_id"] << " ";
		ofs << "m_name:" << this->m_order_data[i]["m_name"] << " ";
		ofs << "room:" << this->m_order_data[i]["room"] << " ";
		ofs << "status:" << this->m_order_data[i]["status"] << endl;;
	}

	ofs.close();
}

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
using namespace std;

class Person
{
	public:
		string m_name;
		int m_score;

		Person(string name, int score)
		{
			this->m_name = name;
			this->m_score = score;
		}
};

void CreatePerson(vector<Person>&v)
{
	string name_seed = "ABCDE";
	for(int i = 0; i < 5; i++)
	{
		string name = "player";
		name += name_seed[i];
		int score = 0;
		Person p(name, score);
		v.push_back(p);
	}
}

void SetScore(vector<Person>&v)
{
	for(vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		deque<int> d;

		for(int i = 0; i < 10; i++)
		{
			int score = rand()%41 + 60;//[60, 100]
			d.push_back(score);
		}

		//test code
		/*cout << "name: " << (*it).m_name << "\tscore: ";
		for(deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			cout << *dit << " ";
		}
		cout << endl;*/

		sort(d.begin(), d.end());
		d.pop_back();
		d.pop_front();

		int sum = 0;
		for(deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}
		
		int avg = sum/d.size();
		it->m_score = avg;
	}
}

void ShowScore(vector<Person>&v)
{
	for(vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "name: " << it->m_name << "\taverage_score: " << it->m_score << endl;
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	vector<Person> v;

	CreatePerson(v);

	//test code
	/*for(vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "name: " << (*it).m_name << "\tscore: " << (*it).m_score << endl;
	}*/

	SetScore(v);

	ShowScore(v);

	return 0;
}

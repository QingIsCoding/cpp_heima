#include <iostream>
#include <string>
using namespace std;

class Student
{
	public:
		string m_name;
		int m_id;

		void ShowStudent()
		{
			cout << "name: " << m_name << "\tid: " << m_id << endl;
		}
		void SetName(string name)
		{
			m_name = name;
		}
		void SetId(int id)
		{
			m_id = id;
		}
};

int main()
{
	Student s1;
	s1.SetName("zhangsan");
	s1.SetId(1);
	s1.ShowStudent();

	Student s2;
	s1.m_name = "lisi";
	s1.m_id = 2;
	s1.ShowStudent();
	return 0;
}

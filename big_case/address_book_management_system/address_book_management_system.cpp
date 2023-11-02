#include <iostream>
#include <string>
using namespace std;
#define MAX 1000

struct Person
{
	string m_name;
	int m_sex;//1:man, 2:woman
	int m_age;
	string m_phone_number;
	string m_address;
};

struct AddressBooks
{
	struct Person person_array[MAX];
	int m_size;
};

void AddContacts(AddressBooks*abs)
{
	if(abs->m_size == MAX)
	{
		cout << "address book is full, can't add" << endl;
		return;
	}
	else
	{
		string name;
		cout << "please input name: ";
		cin >> name;
		abs->person_array[abs->m_size].m_name = name;

		cout << "1:man, 2:woman" << endl;
		cout << "please input sex: ";
		int sex = 0;
		while(true)
		{
			cin >> sex;
			if(sex == 1 || sex == 2)
			{
				abs->person_array[abs->m_size].m_sex = sex;
				break;
			}
				cout << "error, please input again" << endl;
		}

		cout << "please input age: ";
		int age = 0;
		while(true)
		{
			cin >> age;
			if(age >= 1 || age <= 100)
			{
				abs->person_array[abs->m_size].m_age = age;
				break;
			}
				cout << "error, please input again" << endl;
		}

		cout << "please input phone_number: ";
		string phone_number;
		cin >> phone_number;
		abs->person_array[abs->m_size].m_phone_number = phone_number;
	
		cout << "please input address: ";
		string address;
		cin >> address;
		abs->person_array[abs->m_size].m_address = address;

		abs->m_size++;
		cout << "add successfully" << endl;
	}
}

void DisplayContacts(AddressBooks*abs)
{
	if(abs->m_size == 0)
	{
		cout << "current record is empty" << endl;
	}
	else
	{
		for(int i = 0; i < abs->m_size; i++)
		{
			cout << "name: " << abs->person_array[i].m_name << "\t\t";
			cout << "sex: " << (abs->person_array[i].m_sex==1?"man":"woman") << "\t";
			cout << "age: " << abs->person_array[i].m_age << "\t\t";
			cout << "phone_number: " << abs->person_array[i].m_phone_number << "\t\t";
			cout << "address: " << abs->person_array[i].m_address << endl;
		}
	}
}

int IsExist(AddressBooks*abs, string name)
{
	for(int i = 0; i < abs->m_size; i++)
	{
		if(abs->person_array[i].m_name == name)
		{
			return i;
		}
	}
	return -1;
}

void DeleteContacts(AddressBooks*abs)
{
	cout << "please input a name to delete: ";
	string name;
	cin >> name;
	int ret = IsExist(abs, name);
	if(ret != -1)
	{
		for(int i = ret; i < abs->m_size; i++)
		{
			abs->person_array[i] = abs->person_array[i+1];
		}
		abs->m_size--;
		cout << "delete successfully" << endl;
	}
	else
	{
		cout << "can't find" << endl;
	}
}

void LookupContacts(AddressBooks*abs)
{
	cout << "please input a name to lookup: ";
	string name;
	cin >> name;
	int ret = IsExist(abs, name);
	if(ret != -1)
	{
		cout << "name: " << abs->person_array[ret].m_name << "\t\t";
		cout << "sex: " << (abs->person_array[ret].m_sex==1?"man":"woman") << "\t";
		cout << "age: " << abs->person_array[ret].m_age << "\t\t";
		cout << "phone_number: " << abs->person_array[ret].m_phone_number << "\t\t";
		cout << "address: " << abs->person_array[ret].m_address << endl;
	}
	else
	{
		cout << "can't find " << endl;
	}
}

void ModifyContacts(AddressBooks*abs)
{
	cout << "please input a name to modify: ";
	string name;
	cin >> name;
	int ret = IsExist(abs, name);
	if(ret != -1)
	{
		string name;
		cout << "please input name: ";
		cin >> name;
		abs->person_array[ret].m_name = name;

		cout << "1:man, 2:woman" << endl;
		cout << "please input sex: ";
		int sex = 0;
		while(true)
		{
			cin >> sex;
			if(sex == 1 || sex == 2)
			{
				abs->person_array[ret].m_sex = sex;
				break;
			}
				cout << "error, please input again" << endl;
		}

		cout << "please input age: ";
		int age = 0;
		while(true)
		{
			cin >> age;
			if(age >= 1 || age <= 100)
			{
				abs->person_array[ret].m_age = age;
				break;
			}
				cout << "error, please input again" << endl;
		}

		cout << "please input phone_number: ";
		string phone_number;
		cin >> phone_number;
		abs->person_array[ret].m_phone_number = phone_number;
	
		cout << "please input address: ";
		string address;
		cin >> address;
		abs->person_array[ret].m_address = address;

		cout << "modify successfully" << endl;
	}
	else
	{
		cout << "can't find" << endl;
	}
}

void CleanContacts(AddressBooks*abs)
{
	string confirm;
	cout << "are you sure to clean contacts?(yes/no)" << endl;
	cin >> confirm;
	if(confirm == "yes")
	{
		abs->m_size = 0;
		cout << "clear successfully" << endl;
	}
	else if(confirm == "no")
	{
		cout << "you haven't made a choice yet" << endl;
	}
	else
	{
		cout << "what do you mean???" << endl;
	}
}

void ShowMenu()
{
	cout << "******************************" << endl;
	cout << "***** 1.Add\tContacts *****" << endl;
	cout << "***** 2.Display\tContacts *****" << endl;
	cout << "***** 3.Delete\tContacts *****" << endl;
	cout << "***** 4.Lookup\tContacts *****" << endl;
	cout << "***** 5.Modify\tContacts *****" << endl;
	cout << "***** 6.Empty\tContacts *****" << endl;
	cout << "***** 7.Clear\tScreen\t *****" << endl;
	cout << "*****       0.Exit       *****" << endl;
	cout << "******************************" << endl;
	cout << "please make your choice:";
}

void PrintNone()
{
	cout << "\n\n\n" << endl;
}
int main()
{
	AddressBooks abs;
	abs.m_size = 0;
	int select = 0;
	while(true)
	{
		ShowMenu();
		cin >> select;
		switch(select)
		{
			case 1:
				AddContacts(&abs);
				PrintNone();
				break;
			case 2:
				DisplayContacts(&abs);
				PrintNone();
				break;
			case 3:
				DeleteContacts(&abs);
				PrintNone();
				break;
			case 4:
				LookupContacts(&abs);
				PrintNone();
				break;
			case 5:
				ModifyContacts(&abs);
				PrintNone();
				break;
			case 6:
				CleanContacts(&abs);
				PrintNone();
				break;
			case 7:
				system("clear");
				break;
			case 0:
				cout << "welcome to use it next time!" << endl;
				PrintNone();
				return 0;
				break;
			default:
				break;
		}
	}
	return 0;
}

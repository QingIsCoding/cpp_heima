#include <iostream>
#include <string>
#include "MyArray.hpp"
using namespace std;

void PrintIntArray(MyArray<int> &arr)
{
	for(int i = 0; i < arr.GetSize(); i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

class Person
{
	public:
		string m_name;
		int m_age;

		Person(){};
		Person(string name, int age)
		{
			this->m_name = name;
			this->m_age = age;
		}
};

void PrintPersonArray(MyArray<Person> &arr)
{
	for(int i = 0; i < arr.GetSize(); i++)
	{
		cout << "name: " << arr[i].m_name << "\tage: " << arr[i].m_age << endl;
	}
}

void test01()
{
	/*MyArray<int> arr1(5);
	MyArray<int> arr2(arr1);
	MyArray<int> arr3(100);
	arr3 = arr1;
	cout << endl;*/

	MyArray<int> arr1(5);
	for(int i = 0; i < 5; i++)
	{
		arr1.TailInsert(i);
	}
	cout << "arr1: " << endl;
	PrintIntArray(arr1);
	cout << "GetCapacity(arr1): " << arr1.GetCapacity() << endl;
	cout << "GetSize(arr1): " << arr1.GetSize() << endl;
	cout << endl;

	MyArray<int> arr2(arr1);
	cout << "arr2: " << endl; 
	PrintIntArray(arr2);
	cout << endl;

	arr2.TailDelete();
	cout << "arr2:(after TailDelete): " << endl;
	PrintIntArray(arr2);
	cout << "GetCapacity(arr2): " << arr2.GetCapacity() << endl;
	cout << "GetSize(arr2): " << arr2.GetSize() << endl;
}

void test02()
{
	MyArray<Person> arr(10);
	Person p1("sunwukong", 999);
	Person p2("hanxin", 30);
	Person p3("daji", 20);
	Person p4("zhaoyun", 25);
	Person p5("anqila", 27);

	arr.TailInsert(p1);
	arr.TailInsert(p2);
	arr.TailInsert(p3);
	arr.TailInsert(p4);
	arr.TailInsert(p5);

	PrintPersonArray(arr);
	cout << "GetCapacity(arr): " << arr.GetCapacity() << endl;
	cout << "GetSize(arr): " << arr.GetSize() << endl;
}

int main()
{
	test01();
	cout << "---------------------------------------" << endl;
	test02();
	return 0;
}

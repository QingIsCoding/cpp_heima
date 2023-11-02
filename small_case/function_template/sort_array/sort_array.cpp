#include <iostream>
using namespace std;

template<typename T>
void Swap(T&a, T&b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T> 
void Sort(T arr[], int len)
{
	for(int i = 0; i < len-1; i++)
	{
		int max = i;
		for(int j = i+1; j < len; j++)
		{
			if(arr[max] < arr[j])
			{
				max = j;
			}
		}
		if(max != i)
		{
			Swap(arr[max], arr[i]);
		}
	}
}

template<typename T>
void PrintArray(T arr[], int len)
{
	for(int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test01()
{
	char char_arr[] = "badcfeg";
	int num = sizeof(char_arr)/sizeof(char_arr[0]);
	Sort(char_arr, num);
	PrintArray(char_arr, num);
}

void test02()
{
	int int_arr[] = {3, 7, 6, 2, 8, 4, 5, 9, 1};
	int num = sizeof(int_arr)/sizeof(int_arr[0]);
	Sort(int_arr, num);
	PrintArray(int_arr, num);

}

int main()
{
	test01();
	test02();
	return 0;
}

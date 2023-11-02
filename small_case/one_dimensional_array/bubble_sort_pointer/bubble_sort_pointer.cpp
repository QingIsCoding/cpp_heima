#include <iostream>
using namespace std;

void BubbleSort(int*arr, int len)
{
	for(int i = 0; i < len; i++)
	{
		for(int j = 0; j < len-i-1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

void PrintArray(int*arr, int len)
{
	for(int i = 0; i < len; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

int main(){
	int arr[10] = {4, 3, 6, 9, 1, 2, 10, 8, 7, 5};
	int len = sizeof(arr)/sizeof(arr[0]);
	BubbleSort(arr, len);
	PrintArray(arr, len);
	return 0;
}

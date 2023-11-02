#include <iostream>
using namespace std;

int main(){
	int arr[] = {4, 2, 8, 0, 5, 7, 1, 3, 9, 6};
	int length = (sizeof(arr)/sizeof(arr[0]));
	cout << "before bubble sort" << endl;
	for(int i = 0; i < length; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	for(int i = 0; i < length-1; i++)
	{
		for(int j = 0; j < length-i-1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	cout << "after bubble sort" << endl;
	for(int i = 0; i < length; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	return 0;
}

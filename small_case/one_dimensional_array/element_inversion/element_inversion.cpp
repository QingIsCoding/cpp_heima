#include <iostream>
using namespace std;

int main(){
	int arr[] = {1, 3, 2, 5, 4};
	int start = 0;
	int length = sizeof(arr)/sizeof(arr[0]);
	int end = length - 1;
	cout << "before element inversion" << endl;
	for(int i = 0; i < length; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	while(start < end)
	{
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
	cout << "after element inversion" << endl;
	for(int i = 0; i < length; i++)
	{
		cout << arr[i] << "\t"; 
	}
	cout << endl;
	return 0;
}

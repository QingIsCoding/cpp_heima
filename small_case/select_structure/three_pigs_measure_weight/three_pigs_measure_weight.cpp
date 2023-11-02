#include <iostream>
using namespace std;

int main(){
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	cout << "please input the weight of pig A:" << endl;
	cin >> num1;
	cout << "please input the weight of pig B:" << endl;
	cin >> num2;
	cout << "please input the weight of pig C:" << endl;
	cin >> num3;
	cout << "the weight of pig A:" << num1 << endl;
	cout << "the weight of pig B:" << num2 << endl;
	cout << "the weight of pig C:" << num3 << endl;
	if(num1 > num2)
	{
		if(num1 > num3)
		{
			cout << "A is the heaviest" << endl;
		}else
		{
			cout << "C is the heaviest" << endl;
		}
	}
	else
	{
		if(num2 > num3)
		{
			cout << "B is the heaviest" << endl;
		}else
		{
			cout << "C is the heaviest" << endl;
		}
	}	
	return 0;
}

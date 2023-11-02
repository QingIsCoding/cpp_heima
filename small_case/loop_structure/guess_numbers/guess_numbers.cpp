#include <iostream>
#include <ctime>
using namespace std;

int main(){
	srand((unsigned int)time(NULL));
	int num = rand()%100 + 1;
	//cout << "num:" << num << endl;
	int val = 0;
	cout << "please guess a number:" << endl;
	while(val != num)
	{
		cin >> val;
		if(val > num)
		{
			cout << "your guess is big" << endl;
		}
		else if(val < num)
		{
			cout << "your guess is small" << endl;
		}
		else
		{
			cout << "guess right" << endl;
			break;
		}
	}
	return 0;
}

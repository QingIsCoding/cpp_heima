#include <iostream>
using namespace std;

int main(){
	cout << "please input your score:" << endl;
	int score = 0;
	cin >> score;
	cout << "your score is: " << score << endl;
	switch(score)
	{
		case 1:
			cout << "1" << endl;
			break;
		case 2:
			cout << "2" << endl;
			break;
		case 3:
			cout << "3" << endl;
			break;
		case 4:
			cout << "4" << endl;
			break;
		case 5:
			cout << "5" << endl;
			break;
		default:
			cout << "not 1-5" << endl;
			break;
	}
	return 0;
}

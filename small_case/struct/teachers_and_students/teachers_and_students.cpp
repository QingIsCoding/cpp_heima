#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct Student
{
	string sName;
	int score;
};

struct Teacher
{
	string tName;
	struct Student sArray[5];
};

void AllocateSpace(struct Teacher tArray[], int len)
{
	string nameSeed = "ABCDE";
	for(int i = 0; i < len; i++)
	{
		tArray[i].tName = "Teacher_";
		tArray[i].tName += nameSeed[i];
		for(int j = 0; j < 5; j++)
		{
			tArray[i].sArray[j].sName = "Student_";
			tArray[i].sArray[j].sName += nameSeed[j];
			int random = rand()%60+40;
			tArray[i].sArray[j].score = random;
		}
	}
}

void PrintInfo(struct Teacher tArray[], int len)
{
	for(int i = 0; i < len; i++)
	{
		cout << "the name of teacher: " << tArray[i].tName << endl;
		for(int j = 0; j < 5; j++)
		{
			cout << "\tthe name of student: " << tArray[i].sArray[j].sName 
				<< "\tthe score of student: " << tArray[i].sArray[j].score << endl;
		}
	}
}

int main(){
	srand((unsigned int)time(NULL));
	struct Teacher tArray[3];
	int len = sizeof(tArray)/sizeof(tArray[0]);
	AllocateSpace(tArray, len);
	PrintInfo(tArray, len);
	return 0;
}

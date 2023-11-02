#include <iostream>
#include <string>
using namespace std;

struct Hero
{
	string name;
	int age;
	string sex;
};

void BubbleSort(struct Hero heroArray[], int len)
{
	for(int i = 0; i < len-1; i++)
	{
		for(int j = 0; j < len-i-1; j++)
		{
			if(heroArray[j].age > heroArray[j+1].age)
			{
				struct Hero temp = heroArray[j];
				heroArray[j] = heroArray[j+1];
				heroArray[j+1] = temp;
			}
		}
	}
}

int main(){
	struct Hero heroArray[5] = 
	{
		{"liubei", 23, "man"},
		{"guanyu", 22, "man"},
		{"zhangfei", 20, "man"},
		{"zhaoyun", 21, "man"},
		{"diaochan", 19, "woman"}
	};
	int len = sizeof(heroArray)/sizeof(heroArray[0]);
	cout << "before bubble sort" << endl;
	for(int i = 0; i < len; i++)
	{
		cout << "the name of hero: " << heroArray[i].name 
			<< "\tthe age of hero: " << heroArray[i].age
			<< "\tthe sex of hero: " << heroArray[i].sex << endl;
	}
	BubbleSort(heroArray, len);
	cout << "after bubble sort" << endl;
	for(int i = 0; i < len; i++)
	{
		cout << "the name of hero: " << heroArray[i].name 
			<< "\tthe age of hero: " << heroArray[i].age
			<< "\tthe sex of hero: " << heroArray[i].sex << endl;
	}
	return 0;
}

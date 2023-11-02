#include <iostream>
#include <string>
using namespace std;

class Building;

class GoodFriend
{
	public:
		Building*building;

		GoodFriend();

		void Visit1();
		void Visit2();
};

class Building
{
friend void GoodFriend::Visit1();

	public:
		string m_sittingroom;

		Building();

	private:
		string m_bedroom;
};

Building::Building()
{
	m_sittingroom = "sitting-room";
	m_bedroom = "bedroom";
}

GoodFriend::GoodFriend()
{
	building = new Building;
}

void GoodFriend::Visit1()
{
	cout << "visit1\t" << building->m_sittingroom << endl;
	cout << "visit1\t" << building->m_bedroom << endl;
}

void GoodFriend::Visit2()
{
	cout << "visit2\t" << building->m_sittingroom << endl;
	//cout << "visit2\t" << building->m_bedroom << endl; error
}

void test01()
{
	GoodFriend gg;
	gg.Visit1();
	cout << endl;
	gg.Visit2();
}

int main()
{
	test01();
	return 0;
}

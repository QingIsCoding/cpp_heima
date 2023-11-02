#include <iostream>
#include <string>
using namespace std;

class Building;

class GoodFriend
{
	public:
		Building*building;

		GoodFriend();

		void Visit();
};

class Building
{
friend class GoodFriend;

	public:
		string m_settingroom;

		Building();

	private:
		string m_bedroom;
};

Building::Building()
{
	m_settingroom = "setting-room";
	m_bedroom = "bedroom";
}

GoodFriend::GoodFriend()
{
	building = new Building;
}

void GoodFriend::Visit()
{
	cout << "GoodFriend\t" << building->m_settingroom << endl;
	cout << "GoodFriend\t" << building->m_bedroom << endl;
}

void test01()
{
	GoodFriend gg;
	gg.Visit();
}

int main()
{
	test01();
	return 0;
}

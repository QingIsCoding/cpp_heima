#include <iostream>
using namespace std;

class Building
{
friend void GoodFriend(Building*building);

	public:
		string m_sittingroom;
		
		Building()
		{
			m_sittingroom = "sitting-room";
			m_bedroom = "bedroom";
		}

	private:
		string m_bedroom;
};

void GoodFriend(Building*building)
{
	cout << "GoodFriend\t" << building->m_sittingroom << endl;
	cout << "GoodFriend\t" << building->m_bedroom << endl;
}

void test01()
{
	Building building;
	GoodFriend(&building);
}

int main()
{
	test01();
	return 0;
}

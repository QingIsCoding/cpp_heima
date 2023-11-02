#include <iostream>
using namespace std;

class MakeBevarage
{
	public:
		virtual void Boil() = 0;
		virtual void Brew() = 0;
		virtual void Pour() = 0;
		virtual void Add() = 0;

		void Make()
		{
			Boil();
			Brew();
			Pour();
			Add();
		}
};

class Coffee : public MakeBevarage
{
	public:
		virtual void Boil()
		{
			cout << "boil water" << endl;
		}

		virtual void Brew()
		{
			cout << "brew coffee" << endl;
		}

		virtual void Pour()
		{
			cout << "pour into cup" << endl;
		}

		virtual void Add()
		{
			cout << "add sugar and milk" << endl;
		}
};

class Tea : public MakeBevarage
{
	public:
		virtual void Boil()
		{
			cout << "boil mineral water" << endl;
		}

		virtual void Brew()
		{
			cout << "brew tea" << endl;
		}

		virtual void Pour()
		{
			cout << "pour into cup" << endl;
		}

		virtual void Add()
		{
			cout << "add medlar" << endl;
		}
};

void Dowork(MakeBevarage*abs)
{
	abs->Make();
	delete abs;
}

void test01()
{
	Dowork(new Coffee);
	cout << endl;
	Dowork(new Tea);
}

int main()
{
	test01();
	return 0;
}

#include <iostream>
using namespace std;

class BasePage
{
	public:
		void header()
		{
			cout << "header" << endl;
		}

		void footer()
		{
			cout << "footer" << endl;
		}

		void left()
		{
			cout << "left" << endl;
		}
};

class Java : public BasePage
{
	public:
		void content()
		{
			cout << "java content" << endl;
		}
};

class Python : public BasePage
{
	public:
		void content()
		{
			cout << "python content" << endl;
		}
};

class CPP : public BasePage
{
	public:
		void content()
		{
			cout << "cpp content" << endl;
		}
};

void test01()
{
	cout << "-----java-----" << endl;
	Java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();

	cout << "-----Python-----" << endl;
	Python py;
	py.header();
	py.footer();
	py.left();
	py.content();

	cout << "-----CPP-----" << endl;
	CPP cpp;
	cpp.header();
	cpp.footer();
	cpp.left();
	cpp.content();
}

int main()
{
	test01();
	return 0;
}

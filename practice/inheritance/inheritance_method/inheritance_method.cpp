#include <iostream>
using namespace std;

class Base1
{
	public:
		int m_a;
	protected:
		int m_b;
	private:
		int m_c;
};

class Son1 : public Base1
{
	public:
		void func()
		{
			m_a = 10;//private
			m_b = 10;//protected
			//m_c = 10; private
		}
};

class Base2
{
	public:
		int m_a;
	protected:
		int m_b;
	private:
		int m_c;
};

class Son2 : protected Base2
{
	public:
		void func()
		{
			m_a = 100;//protected
			m_b = 100;//protected
			//m_c = 100; private
		}
};

class Base3
{
	public:
		int m_a;
	protected:
		int m_b;
	private:
		int m_c;
};

class Son3 : private Base3
{
	public:
		void func()
		{
			//m_a = 100; private
			//m_b = 100; private
			//m_c = 100; private
		}
};

class GrandSon3 : public Son3
{
	public:
		void func()
		{
			//m_a = 1000; private
			//m_b = 1000; private
			//m_c = 1000; private
		}
};

void test01()
{
	Son1 s1;
	s1.m_a = 100;//public
	//s1.m_b = 100; protected
	//s1.m_c = 100; private
}

void test02()
{
	Son2 s2;
	//s2.m_a = 100; protected
	//s2.m_b = 100; protected
	//s2.m_c = 100; private
}

void test03()
{
	Son3 s3;
	//s3.m_a = 100; private
	//s3.m_b = 100; private
	//s3.m_c = 100; private
}

int main()
{
	test01();
	test02();
	test03();
	return 0;
}

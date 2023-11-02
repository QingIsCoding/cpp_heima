#include <iostream>
#include <string>
using namespace std;

class Calculator
{
	public:
		int m_num1;
		int m_num2;

		int GetResult(string oper)
		{
			if(oper == "+")
			{
				return m_num1+m_num2;
			}
			else if(oper == "-")
			{
				return m_num1-m_num2;
			}
			else if(oper == "*")
			{
				return m_num1*m_num2;
			}
		}
};

class AbstractCalculator
{
	public:
		int m_num1;
		int m_num2;

		virtual int GetResult()
		{
			return 0;
		}
};

class AddCalculator : public AbstractCalculator
{
	int GetResult()
	{
		return m_num1+m_num2;
	}
};

class SubCalculator : public AbstractCalculator
{
	int GetResult()
	{
		return m_num1-m_num2;
	}
};

class MulCalculator : public AbstractCalculator
{
	int GetResult()
	{
		return m_num1*m_num2;
	}
};

void test01()
{
	Calculator c;
	c.m_num1 = 10;
	c.m_num2 = 10;
	cout << c.m_num1 << "+" << c.m_num2 << "=" << c.GetResult("+") << endl;
	cout << c.m_num1 << "-" << c.m_num2 << "=" << c.GetResult("-") << endl;
	cout << c.m_num1 << "*" << c.m_num2 << "=" << c.GetResult("*") << endl;
}

void test02()
{
	AbstractCalculator*abc = new AddCalculator;
	abc->m_num1 = 100;
	abc->m_num2 = 100;
	cout << abc->m_num1 << "+" << abc->m_num2 << "=" << abc->GetResult() << endl;
	delete abc;

	abc = new SubCalculator;
	abc->m_num1 = 100;
	abc->m_num2 = 100;
	cout << abc->m_num1 << "-" << abc->m_num2 << "=" << abc->GetResult() << endl;
	delete abc;

	abc = new MulCalculator;
	abc->m_num1 = 100;
	abc->m_num2 = 100;
	cout << abc->m_num1 << "*" << abc->m_num2 << "=" << abc->GetResult() << endl;
	delete abc;
}

int main()
{
	test01();
	cout << endl;
	test02();
	return 0;
}

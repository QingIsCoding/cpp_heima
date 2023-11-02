#include <iostream>
using namespace std;

class CPU
{
	public:
		virtual void Calculator() = 0;
};

class GraphicsCard
{
	public:
		virtual void Display() = 0;
};

class MemoryModule
{
	public:
		virtual void Storage() = 0;
};

class Computer
{
	public:
		Computer(CPU*cpu, GraphicsCard*gc, MemoryModule*mm)
		{
			m_cpu = cpu;
			m_gc = gc;
			m_mm = mm;
		}

		void Work()
		{
			m_cpu->Calculator();
			m_gc->Display();
			m_mm->Storage();
		}

		~Computer()
		{
			if(m_cpu != NULL)
			{
				delete m_cpu;
				m_cpu = NULL;
			}

			if(m_gc != NULL)
			{
				delete m_gc;
				m_gc = NULL;
			}
		
			if(m_mm != NULL)
			{
				delete m_mm;
				m_mm = NULL;
			}
		}

	private:
		CPU*m_cpu;
		GraphicsCard*m_gc;
		MemoryModule*m_mm;
};

class IntelCPU : public CPU
{
	public:
		virtual void Calculator()
		{
			cout << "IntelCPU is calculating" << endl;
		}
};

class IntelGraphicsCard : public GraphicsCard
{
	public:
		virtual void Display()
		{
			cout << "IntelGraphicsCard is displaying" << endl;
		}
};

class IntelMemoryModule : public MemoryModule
{
	public:
		virtual void Storage()
		{
			cout << "IntelMemoryModule is storaging" << endl;
		}
};

class LenovoCPU : public CPU
{
	public:
		virtual void Calculator()
		{
			cout << "LenovoCPU is calculating" << endl;
		}
};

class LenovoGraphicsCard : public GraphicsCard
{
	public:
		virtual void Display()
		{
			cout << "LenovoGraphicsCard is displaying" << endl;
		}
};

class LenovoMemoryModule : public MemoryModule
{
	public:
		virtual void Storage()
		{
			cout << "LenovoMemoryModule is storaging" << endl;
		}
};

void test01()
{
	CPU*Intel_CPU = new IntelCPU;
	GraphicsCard*Intel_GraphicsCard = new IntelGraphicsCard;
	MemoryModule*Intel_MemoryModule = new IntelMemoryModule;
	Computer*computer1 = new Computer(Intel_CPU, Intel_GraphicsCard, Intel_MemoryModule);
	computer1->Work();
	delete computer1;

	cout << endl;

	CPU*Lenovo_CPU = new LenovoCPU;
	GraphicsCard*Lenovo_GraphicsCard = new LenovoGraphicsCard;
	MemoryModule*Lenovo_MemoryModule = new LenovoMemoryModule;
	Computer*computer2 = new Computer(Lenovo_CPU, Lenovo_GraphicsCard, Lenovo_MemoryModule);
	computer2->Work();
	delete computer2;

	cout << endl;

	Computer*computer3 = new Computer(new LenovoCPU, new IntelGraphicsCard, new LenovoMemoryModule);
	computer3->Work();
	delete computer3;
}

int main()
{
	test01();
	return 0;
}

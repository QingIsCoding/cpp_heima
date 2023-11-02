#include <iostream>
using namespace std;

class Cube
{
	public:
		void SetL(int l)
		{
			m_l = l;
		}
		int GetL()
		{
			return m_l;
		}

		void SetW(int w)
		{
			m_w = w;
		}
		int GetW()
		{
			return m_w;
		}

		void SetH(int h)
		{
			m_h = h;
		}
		int GetH()
		{
			return m_h;
		}

		int CalculateS()
		{
			return 2*(m_l*m_w+m_l*m_h+m_w*m_h);
		}

		int CalculateV()
		{
			return m_l*m_w*m_h;
		}

		bool IsSameClass(Cube&c)
		{
			if(m_l==c.GetL() && m_w==c.GetW() && m_h==c.GetH())
			{
				return  true;
			}
			return false;
		}

	private:
		int m_l;
		int m_w;
		int m_h;
};

bool IsSame(Cube&c1, Cube&c2)
{
	if(c1.GetL()==c2.GetL() && c1.GetW()==c2.GetW() && c1.GetH()==c2.GetH())
	{
		return true;
	}
	return false;
}

int main()
{
	Cube c1;
	c1.SetL(10);
	c1.SetW(10);
	c1.SetH(10);
	cout << "c1.CalculateS(): " << c1.CalculateS() << endl;
	cout << "c1.CalculateV(): " << c1.CalculateV() << endl;

	Cube c2;
	c2.SetL(10);
	c2.SetW(10);
	c2.SetH(11);
	bool ret = IsSame(c1, c2);
	if(ret)
	{
		cout << "c1 = c2" << endl;
	}
	else
	{
		cout << "c1 != c2" << endl;
	}

	ret = c1.IsSameClass(c2);
	if(ret)
	{
		cout << "class func: c1 = c2" << endl;
	}
	else
	{
		cout << "class func: c1 != c2" << endl;
	}

	return 0;
}

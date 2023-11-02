#include <iostream>
#include <string>
using namespace std;

class Animal
{
	public:
		virtual	void speak() = 0;

		Animal()
		{
			cout << "Animal::constructor" << endl;
		}

		/*virtual ~Animal()
		{
			cout << "Animal::destructor" << endl;
		}*/

		virtual ~Animal() = 0;
};

Animal::~Animal()
{

}

class Cat : public Animal
{
	public:
		string*m_name;

		Cat(string name)
		{
			cout << "Cat::constructor" << endl;
			m_name = new string(name);
		}

		virtual void speak()
		{
			cout << *m_name << "\tcat is speaking" << endl;
		}

		~Cat()
		{
			if(m_name != NULL)
			{
				cout << "Cat::destructor" << endl;
				delete m_name;
				m_name = NULL;
			}
		}
};

void test01()
{
	Animal*animal = new Cat("Tom");
	animal->speak();
	delete animal;
}

int main()
{
	test01();
	return 0;
}

#include <iostream>
using namespace std;

class Animal
{
	public:
		virtual void speak()
		{
			cout << "animal is speaking" << endl;
		}
};

class Cat : public Animal
{
	public:
		void speak()
		{
			cout << "cat is speaking" << endl;
		}
};

class Dog : public Animal
{
	public:
		void speak()
		{
			cout << "dog is speaking" << endl;
		}
};

void DoSpeak(Animal&animal)
{
	animal.speak();
}

void test01()
{
	Cat cat;
	DoSpeak(cat);
	cout << endl;
	Dog dog;
	DoSpeak(dog);
}

int main()
{
	test01();
	return 0;
}

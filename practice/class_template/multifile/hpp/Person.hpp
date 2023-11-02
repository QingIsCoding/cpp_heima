#pragma once
#include <iostream>
#include <string>
using namespace std;

template<class T1, class T2> 
class Person
{
    public:
        T1 m_name;
        T2 m_age;

        Person(T1 name, T2 age);
        void ShowPerson();
};

template<class T1, class T2> 
Person<T1, T2>::Person(T1 name, T2 age)
{
    m_name = name;
    m_age = age;
}

template<class T1, class T2> 
void Person<T1, T2>::ShowPerson()
{
    cout << "name: " << m_name << "\tage: " << m_age << endl;
}

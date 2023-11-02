#include "Person.h"

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

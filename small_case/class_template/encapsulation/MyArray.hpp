#pragma once
#include <iostream>
using namespace std;

template<class T>
class MyArray
{
	public:
		MyArray(int capacity)
		{
			cout << "MyArray::constructor(with parameter)" << endl;
			this->m_capacity = capacity;
			this->m_size = 0;
			this->p_address = new T[m_capacity];
		}

		MyArray(const MyArray&arr)
		{
			cout << "MyArray::constructor(copy)" << endl;
			this->m_capacity = arr.m_capacity;
			this->m_size = arr.m_size;
			//this->p_address = arr.p_address; error
			this->p_address = new T[arr.m_capacity];
			for(int i = 0; i < this->m_size; i++)
			{
				this->p_address[i] = arr.p_address[i];
			}
		}

		MyArray&operator=(const MyArray&arr)
		{
			cout << "MyArray::operator=" << endl;
			if(this->p_address != NULL)
			{
				delete[] this->p_address;
				this->p_address = NULL;
				this->m_capacity = 0;
				this->m_size = 0;
			}

			this->m_capacity = arr.m_capacity;
			this->m_size = arr.m_size;
			this->p_address = new T[arr.m_capacity];
			for(int i = 0; i < this->m_size; i++)
			{
				this->p_address[i] = arr.p_address[i];
			}

			return *this; 
		}

		void TailInsert(const T&val)
		{
			if(this->m_capacity == this->m_size)
			{
				return;
			}
			this->p_address[this->m_size] = val;
			this->m_size++;
		}

		void TailDelete()
		{
			if(this->m_size == 0)
			{
				return;
			}
			this->m_size--;
		}

		T& operator[](int index)
		{
			return this->p_address[index];
		}

		int GetCapacity()
		{
			return this->m_capacity;
		}

		int GetSize()
		{
			return this->m_size;
		}

		~MyArray()
		{
			if(this->p_address != NULL)
			{
				cout << "MyArray::destructor" << endl;
				delete[] this->p_address;
				this->p_address = NULL;
			}
		}

	private:
		T*p_address;
		int m_capacity;
		int m_size;
};

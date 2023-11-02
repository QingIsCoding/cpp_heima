#pragma once
#include <iostream>

using namespace std;

class Identity
{
	public:
		string m_name;
		string m_pwd;

		virtual void OpenMenu() = 0;
};

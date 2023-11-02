#pragma once
#include <iostream>
#include "GlobalFile.h"
#include <fstream>
#include <map>
#include <string>

using namespace std;

class OrderFile
{
	public:
		int m_size;
		map<int, map<string,string>> m_order_data;

		OrderFile();
		void UpdateOrder();
};

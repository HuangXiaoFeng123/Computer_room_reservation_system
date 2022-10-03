#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include "globalFile.h"
using namespace std;

class OrderFile
{
public:
	int m_Size;
	OrderFile(void);
	void updateOrder(void);
	map<int, map<string, string>> m_orderData;
};

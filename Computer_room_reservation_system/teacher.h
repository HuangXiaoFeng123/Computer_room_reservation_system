#pragma once
#include <iostream>
#include <vector>
#include "orderFile.h"
#include "identity.h"
using namespace std;

class Teacher :public Identity
{
public:
	int m_EmpId;
	Teacher(void);
	Teacher(int empId, string name, string pwd);
	virtual void operMenu(void);
	void showAllOrder(void);
	void validOrder(void);
};
#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "identity.h"
#include "computerRoom.h"
#include "globalFile.h"
#include "orderFile.h"
using namespace std;

class Student :public Identity
{
public:
	int m_Id;
	vector<ComputerRoom> vCom;
	Student(void);
	Student(int id, string name, string pwd);
	virtual void operMenu(void);
	void applyMyOrder(void);
	void showMyOrder(void);
	void showAllOrder(void);
	void cancelOrder(void);
};
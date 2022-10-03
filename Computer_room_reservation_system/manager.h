#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "identity.h"
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "computerRoom.h"
using namespace std;

class Manager :public Identity
{
public:
	vector<Student> vStu;
	vector<Teacher> vTea;
	vector<ComputerRoom>vCom;
	Manager(void);
	Manager(string name, string pwd);
	virtual void operMenu(void);
	void addPerson(void);
	void showPerson(void);
	void showComputer(void);
	void cleanFile(void);
	void initVector(void);
	bool checkRepeat(int id, int type);
};
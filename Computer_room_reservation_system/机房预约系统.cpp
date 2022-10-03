#include "identity.h"
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
#include <fstream>
void LoginIn(string fileName, int type);
void managerMenu(Identity*& manager);
void studentMenu(Identity*& student);
void teahcerMenu(Identity*& teacher);
int main(void)
{
	int select = 0;
	while (1)
	{
		cout << "===============欢迎来到机房预约系统===============" << endl;
		cout << "请输入你的身份" << endl;
		cout << "\t-------------------------\n";
		cout << "\t|                       |\n";
		cout << "\t|      1.学生代表       |\n";
		cout << "\t|                       |\n";
		cout << "\t|      2.老    师       |\n";
		cout << "\t|                       |\n";
		cout << "\t|      3.管 理 员       |\n";
		cout << "\t|                       |\n";
		cout << "\t|      0.退    出       |\n";
		cout << "\t|                       |\n";
		cout << "\t-------------------------\n";
		cout << "请输入你的选择" << endl;
		cin >> select;
		switch (select)
		{
			case 1:
				LoginIn(STUDENT_FILE, 1);
				break;
			case 2:
				LoginIn(TEACHER_FILE, 2);
				break;
			case 3:
				LoginIn(ADMIN_FILE, 3);
				break;
			case 0:
				cout << "欢迎下次使用" << endl;
				system("pause");
				return 0;
			default:
				cout << "输入有误，请重新选择" << endl;
				system("pause");
				system("cls");
				break;
		}
	}
}
void LoginIn(string fileName, int type)
{
	Identity* person = NULL;
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		return;
	}
	int id = 0;
	string name;
	string pwd;
	if (type == 1)
	{
		cout << "请输入你的学号" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入你的职工号" << endl;
		cin >> id;
	}
	cout << "请输入用户名" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
	cin >> pwd;
	if (type == 1)
	{
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "学生验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "教师验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				teahcerMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "管理员登录验证成功" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				managerMenu(person);
				return;
			}
		}
	}
	cout << "登录失败" << endl;
	system("pause");
	system("cls");
	return;
}
void managerMenu(Identity*& manager)
{
	while (1)
	{
		manager->operMenu();
		Manager* man = (Manager*)manager;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2)
		{
			//cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3)
		{
			//cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4)
		{
			//cout << "清空预约" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			//cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
void studentMenu(Identity*& student)
{
	while (1)
	{
		student->operMenu();
		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			stu->applyMyOrder();
		}
		else if (select == 2)
		{
			stu->showMyOrder();
		}
		else if (select == 3)
		{
			stu->showAllOrder();
		}
		else if (select == 4)
		{
			stu->cancelOrder();
		}
		else
		{
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
void teahcerMenu(Identity*& teacher)
{
	while (1)
	{
		teacher->operMenu();
		Teacher* tea = (Teacher*)teacher;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
		}
	}
}
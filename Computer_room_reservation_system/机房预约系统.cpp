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
		cout << "===============��ӭ��������ԤԼϵͳ===============" << endl;
		cout << "������������" << endl;
		cout << "\t-------------------------\n";
		cout << "\t|                       |\n";
		cout << "\t|      1.ѧ������       |\n";
		cout << "\t|                       |\n";
		cout << "\t|      2.��    ʦ       |\n";
		cout << "\t|                       |\n";
		cout << "\t|      3.�� �� Ա       |\n";
		cout << "\t|                       |\n";
		cout << "\t|      0.��    ��       |\n";
		cout << "\t|                       |\n";
		cout << "\t-------------------------\n";
		cout << "���������ѡ��" << endl;
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
				cout << "��ӭ�´�ʹ��" << endl;
				system("pause");
				return 0;
			default:
				cout << "��������������ѡ��" << endl;
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
		cout << "�ļ�������" << endl;
		return;
	}
	int id = 0;
	string name;
	string pwd;
	if (type == 1)
	{
		cout << "���������ѧ��" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "���������ְ����" << endl;
		cin >> id;
	}
	cout << "�������û���" << endl;
	cin >> name;
	cout << "����������" << endl;
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
				cout << "ѧ����֤��¼�ɹ�" << endl;
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
				cout << "��ʦ��֤��¼�ɹ�" << endl;
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
				cout << "����Ա��¼��֤�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				managerMenu(person);
				return;
			}
		}
	}
	cout << "��¼ʧ��" << endl;
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
			//cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2)
		{
			//cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3)
		{
			//cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4)
		{
			//cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			//cout << "ע���ɹ�" << endl;
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
			cout << "ע���ɹ�" << endl;
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
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
		}
	}
}
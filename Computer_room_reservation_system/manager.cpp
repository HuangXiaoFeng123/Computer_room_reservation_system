#include "manager.h"

void printStudent(Student& s)
{
	cout << "ѧ�ţ�" << s.m_Id << "������" << s.m_Name << "���룺" << s.m_Pwd << endl;
}
void printTeacher(Teacher& t)
{
	cout << "ְ���ţ�" << t.m_EmpId << "������" << t.m_Name << "���룺" << t.m_Pwd << endl;
}
Manager::Manager(void)
{

}
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;
	this->initVector();
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
}
void Manager::operMenu(void)
{
	cout << "��ӭ����Ա" << this->m_Name << "��¼��" << endl;
	cout << "\t-------------------------\n";
	cout << "\t|                       |\n";
	cout << "\t|      1.����˺�       |\n";
	cout << "\t|                       |\n";
	cout << "\t|      2.�鿴�˺�       |\n";
	cout << "\t|                       |\n";
	cout << "\t|      3.�鿴����       |\n";
	cout << "\t|                       |\n";
	cout << "\t|      4.���ԤԼ       |\n";
	cout << "\t|                       |\n";
	cout << "\t|      0.ע����¼       |\n";
	cout << "\t|                       |\n";
	cout << "\t-------------------------\n";
	cout << "���������ѡ��" << endl;
}
void Manager::addPerson(void)
{
	cout << "�������˺�����" << endl;
	cout << "1.���ѧ��" << endl;
	cout << "2.�����ʦ" << endl;
	string fileName;
	string tip;
	string errorTip;
	ofstream ofs;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errorTip = "ѧ���ظ�������������";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "������ְ�����";
		errorTip = "ְ������ظ�������������";
	}
	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	while (1)
	{
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret)
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}
	cout << "����������" << endl;
	cin >> name;
	cout << "����������" << endl;
	cin >> pwd;
	ofs << id << " " << name << " " << pwd << endl;
	cout << "��ӳɹ�" << endl;
	system("pause");
	system("cls");
	ofs.close();
	this->initVector();
}
void Manager::showPerson(void)
{
	cout << "��ѡ��鿴������" << endl;
	cout << "1.�鿴����ѧ��" << endl;
	cout << "2.�鿴������ʦ" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		cout << "���е�ѧ����Ϣ���£�" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		cout << "���е���ʦ��Ϣ���£�" << endl;
		for_each(vTea.begin(),vTea.end(),printTeacher);
	}
	system("pause");
	system("cls");
}
void Manager::showComputer(void)
{
	cout << "��������Ϣ���£�" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "�����ı�ţ�" << it->m_ComId << "������������" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}
void Manager::cleanFile(void)
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
}
void Manager::initVector(void)
{
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	vStu.clear();
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	ifs.close();
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	vTea.clear();
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	ifs.close();
}
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
				return true;
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
				return true;
		}
	}
	return false;
}
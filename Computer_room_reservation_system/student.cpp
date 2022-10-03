#include "student.h"

Student::Student(void)
{

}
Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
}
void Student::operMenu(void)
{
	cout << "��ӭ����Ա" << this->m_Name << "��¼��" << endl;
	cout << "\t-----------------------------\n";
	cout << "\t|                           |\n";
	cout << "\t|      1.����ԤԼ           |\n";
	cout << "\t|                           |\n";
	cout << "\t|      2.�鿴ԤԼ           |\n";
	cout << "\t|					       |\n";
	cout << "\t|      3.�鿴����ԤԼ       |\n";
	cout << "\t|                           |\n";
	cout << "\t|      4.ȡ��ԤԼ           |\n";
	cout << "\t|                           |\n";
	cout << "\t|      0.ע����¼           |\n";
	cout << "\t|                           |\n";
	cout << "\t-----------------------------\n";
	cout << "���������ѡ��" << endl;
}
void Student::applyMyOrder(void)
{
	cout << "��������ʱ����һ������" << endl;
	cout << "����������ԤԼ��ʱ��" << endl;
	cout << "1.��һ" << endl;
	cout << "2.�ܶ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;
	int data = 0;
	int interval = 0;
	int room = 0;
	while (1)
	{
		cin >> data;
		if (data >= 1 && data <= 5)
		{
			break;
		}
		cout << "������������������" << endl;
	}
	cout << "����������ԤԼ��ʱ���" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;
	while (1)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "������������������" << endl;
	}
	cout << "��ѡ�����" << endl;
	for (int i = 0; i < vCom.size(); i++)
	{
		cout << vCom[i].m_ComId << "�Ż���������Ϊ��" << vCom[i].m_MaxNum << endl;
	}	
	while (1)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "������������������" << endl;
	}
	cout << "ԤԼ�ɹ��������" << endl;
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	ofs << "data��" << data << " ";
	ofs << "interval��" << interval << " ";
	ofs << "stuId��" << this->m_Id << " ";
	ofs << "stuName��" << this->m_Name << " ";
	ofs << "roomId��" << room << " ";
	ofs << "status��" << 1 << endl;
	ofs.close();
	system("pause");
	system("cls");
}
void Student::showMyOrder(void)
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))   //�ҵ�����ԤԼ
		{
			cout << "ԤԼ���ڣ���" << of.m_orderData[i]["data"];
			cout << "ʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << "�����ţ�" << of.m_orderData[i]["roomId"];
			string status = "״̬��";
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status += "ԤԼʧ��";
			}
			else
			{
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
}
void Student::showAllOrder(void)
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << ",";
		cout << "ԤԼ���ڣ���" << of.m_orderData[i]["data"];
		cout << "ʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
		cout << "ѧ�ţ�" << of.m_orderData[i]["stuId"];
		cout << "������" << of.m_orderData[i]["stuName"];
		cout << "�����ţ�" << of.m_orderData[i]["roomId"];
		string status = "״̬��";
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "ԤԼʧ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}
void Student::cancelOrder(void)
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л�ԤԼ�еļ�¼�ǿ���ȡ����" << endl;
	int index = 1;
	vector<int> v;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))
		{
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << ",";
				cout << "ԤԼ���ڣ�" << of.m_orderData[i]["data"];
				cout << "ʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
				cout << "�����ţ�" << of.m_orderData[i]["roomId"];
				string status = "״̬��";
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "�����";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}
				cout << status << endl;
			}
		}
	}
	cout << "������ȡ���ļ�¼(0��ʾ�˳���" << endl;
	int select = 0;
	while (1)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				of.m_orderData[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "��ȡ��ԤԼ" << endl;
			}
		}
		cout << "������������������" << endl;
	}
	system("pause");
	system("cls");
}
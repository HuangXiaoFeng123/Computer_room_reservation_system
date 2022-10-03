#include "orderFile.h"

OrderFile::OrderFile(void)
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	string data;
	string invertal;
	string stuId;
	string stuName;
	string roomId;
	string status;
	this->m_Size = 0;
	while (ifs >> data && ifs >> invertal && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		/*cout << data << endl;
		cout << invertal << endl;
		cout << stuId << endl;
		cout << stuName << endl;
		cout << roomId << endl;
		cout << status << endl;
		cout << endl;*/
		string key;
		string value;
		map<string, string> m;
		int pos = data.find(":");
		if (pos != -1)
		{
			key = data.substr(0, pos);
			value = data.substr(pos + 1, data.size() - pos - 1);
			m.insert(make_pair(key, value));

		}
		pos = invertal.find(":");
		if (pos != -1)
		{
			key = invertal.substr(0, pos);
			value = invertal.substr(pos + 1, invertal.size() - pos - 1);
			m.insert(make_pair(key, value));

		}
		pos = stuId.find(":");
		if (pos != -1)
		{
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);
			m.insert(make_pair(key, value));

		}
		pos = stuName.find(":");
		if (pos != -1)
		{
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);
			m.insert(make_pair(key, value));

		}
		pos = roomId.find(":");
		if (pos != -1)
		{
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos - 1);
			m.insert(make_pair(key, value));

		}
		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));

		}
		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}
	ifs.close();
}
void OrderFile::updateOrder(void)
{
	if (this->m_Size == 0)
		return;
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < this->m_Size; i++)
	{
		ofs << "data:" << this->m_orderData[i]["data"] << " ";
		ofs << "invertal:" << this->m_orderData[i]["invertal"] << " ";
		ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << endl;
	}
}
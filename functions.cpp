#include "functions.h"
//�ж��ļ��Ƿ����
bool isExists(const std::string& name) {
	ifstream f(name.c_str());
	return f.good();
}

//��н�ܶ����
//�ж�Ա��ְλ�Ƿ�Ϊ��ְ��Ա
bool isPart_time(Employee person) {
	if (person.getJob() == "PTECHNOLOGIST" || person.getJob() == "PSALESMAN") {
		return true;
	}
	return false;
}

//�ж�Ա���Ƿ������۾���
bool isSalesManger(Employee person) {
	if (person.getJob() == "SALESMANAGER") {
		return true;
	}
	return false;
}

////���һ�����۾����ȫ����Ϣ
//void showSMAll(Employee person) {
//	if (person.getJob() == "SALESMANAGER") {
//		int sale = 0;
//		double money = 0;
//		Psalesman parttime_Salesman = person.toPsalesman();
//		//cout << "��⵽Ա�������۾��������뵱��������:" << endl;
//		//cin >> sale;
//		//cout << "�����뵥λ�����������:" << endl;
//		//cin >> money;
//		//parttime_Salesman.display();
//		//cout << "��н�ܶ���:" << parttime_Salesman.totalSal(sale, money) << endl;
//	}
//}

////���һ����ְ��Ա��������Ϣ
//void showAll(Employee person) {
//	int sale = 0, hours = 0;
//	double money = 0;
//	if (person.getJob() == "PSALESMAN") {
//		Psalesman parttime_Salesman = person.toPsalesman();
//		//cout << "��⵽Ա���Ǽ�ְ����Ա����������/������������:" << endl;
//		//cin >> sale;
//		//cout << "�����뵥λ�������Ľ��:" << endl;
//		//cin >> money;
//		parttime_Salesman.display();
//		//cout << "��н�ܶ���:" << parttime_Salesman.totalSal(sale, money) << endl;
//	}
//	if (person.getJob() == "PTECHNOLOGIST") {
//		Ptechnologist parttime_technologist = person.toPtechnologist();
//		//cout << "��⵽Ա���Ǽ�ְ������Ա����������/�����¹���ʱ��:" << endl;
//		//cin >> hours;
//		//cout << "�����뵥λʱ���Ľ��:" << endl;
//		//cin >> money;
//		parttime_technologist.display();
//		//cout << "��н�ܶ���:" << parttime_technologist.totalSal(hours, money) << endl;
//	}
//}

////��Ա������������
//void searchByName(list<Employee> employees, string name) {
//	bool has = false;
//	for (list<Employee>::iterator nowit = employees.begin(); nowit != employees.end(); nowit++) {
//		if ((*nowit).getName() == name) {
//			(*nowit).display();
//			has = true;
//		}
//	}
//	if (!has) {
//		cout << "��Ա�������ڻ���ɾ����" << endl;
//	}
//}

////����Ա�������ͱ�Ų�ѯȫ����Ϣ
//void searchTotal(list<Employee> employees, string name, string no) {
//	bool has = false;
//	vector<Employee> persons;
//	for (list<Employee>::iterator nowit = employees.begin(); nowit != employees.end(); nowit++) {
//		if (((*nowit).getName() == name) && ((*nowit).getNo() == no)) {
//			if (isPart_time(*nowit)) {
//				//showAll(*nowit);
//			}
//			else if (isSalesManger(*nowit)) {
//				//showSMAll(*nowit);
//			}
//			else {
//				//չʾ����
//			}
//			has = true;
//		}
//	}
//	if (!has) {
//		//cout << "��Ա�������ڻ���ɾ����" << endl;
//	}
//}

////�������ֺͱ���ж�Ψһ����һԱ�������Ƿ����
//bool searchByName_NO(list<Employee> employees, string name, string no) {
//	bool has = false;
//	for (list<Employee>::iterator nowit = employees.begin(); nowit != employees.end(); nowit++) {
//		if ((*nowit).getName() == name && (*nowit).getNo() == no) {
//			has = true;
//		}
//	}
//	return has;
//}

//�ж��������Ƿ���employee����
bool contains(list<Employee> employees, Employee employee) {
	bool isContains = false;
	for (list<Employee>::iterator nowit = employees.begin(); nowit != employees.end(); nowit++) {
		if (employee.equal(*nowit)) {
			isContains = true;
			break;
		}
	}
	return isContains;
}



//ˢ��Ӳ�̵�����
void myFlush(list<Employee>* list) {
	string dbfile = "file.txt";
	ofstream fileout(dbfile.c_str(), ios::out | ios::trunc);
	fileout.close();
	std::ofstream fout("file.txt");
	boost::archive::text_oarchive oa(fout);//

	oa << *list;
	fout.close();
}

//�õ���ǰʱ��
string getSystemTime()
{
	SYSTEMTIME m_time;
	GetLocalTime(&m_time);
	char szDateTime[100] = { 0 };
	sprintf_s(szDateTime, "%02d-%02d-%02d %02d:%02d:%02d", m_time.wYear, m_time.wMonth,
		m_time.wDay, m_time.wHour, m_time.wMinute, m_time.wSecond);
	string time(szDateTime);
	return time;
}

//��־
//����ı����ַ���,��¼��½ʱ��
void journal() {
	ofstream out;
	out.open("journal.txt", ios::out | ios::app);
	out << getSystemTime() << " " << "��¼ϵͳ��" << endl;
	out.close();
}

//��¼��Ϣ����
void journal(Employee object, string operation) {
	ofstream out;
	out.open("journal.txt", ios::app);
	out << getSystemTime() << " " << "���Ϊ��" << object.getNo() << "��" << object.getName() << "��" << operation << endl;
	out.close();
}

//ͨ����Ų�����
bool searchByNumber(list<Employee> employees, string no) {
	bool has_person = false;
	for (list<Employee>::iterator nowit = employees.begin(); nowit != employees.end(); nowit++) {
		if ((*nowit).getNo() == no) {
			has_person = true;
		}
	}
	return has_person;
}

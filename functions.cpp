#include "functions.h"
//判断文件是否存在
bool isExists(const std::string& name) {
	ifstream f(name.c_str());
	return f.good();
}

//月薪总额计算
//判断员工职位是否为兼职人员
bool isPart_time(Employee person) {
	if (person.getJob() == "PTECHNOLOGIST" || person.getJob() == "PSALESMAN") {
		return true;
	}
	return false;
}

//判断员工是否是销售经理
bool isSalesManger(Employee person) {
	if (person.getJob() == "SALESMANAGER") {
		return true;
	}
	return false;
}

////输出一个销售经理的全部信息
//void showSMAll(Employee person) {
//	if (person.getJob() == "SALESMANAGER") {
//		int sale = 0;
//		double money = 0;
//		Psalesman parttime_Salesman = person.toPsalesman();
//		//cout << "检测到员工是销售经理，请输入当月销售量:" << endl;
//		//cin >> sale;
//		//cout << "请输入单位销售量的提成:" << endl;
//		//cin >> money;
//		//parttime_Salesman.display();
//		//cout << "月薪总额是:" << parttime_Salesman.totalSal(sale, money) << endl;
//	}
//}

////输出一个兼职人员的所有信息
//void showAll(Employee person) {
//	int sale = 0, hours = 0;
//	double money = 0;
//	if (person.getJob() == "PSALESMAN") {
//		Psalesman parttime_Salesman = person.toPsalesman();
//		//cout << "检测到员工是兼职销售员，请输入他/她的月销售量:" << endl;
//		//cin >> sale;
//		//cout << "请输入单位销售量的金额:" << endl;
//		//cin >> money;
//		parttime_Salesman.display();
//		//cout << "月薪总额是:" << parttime_Salesman.totalSal(sale, money) << endl;
//	}
//	if (person.getJob() == "PTECHNOLOGIST") {
//		Ptechnologist parttime_technologist = person.toPtechnologist();
//		//cout << "检测到员工是兼职技术人员，请输入他/她的月工作时长:" << endl;
//		//cin >> hours;
//		//cout << "请输入单位时长的金额:" << endl;
//		//cin >> money;
//		parttime_technologist.display();
//		//cout << "月薪总额是:" << parttime_technologist.totalSal(hours, money) << endl;
//	}
//}

////按员工的姓名查找
//void searchByName(list<Employee> employees, string name) {
//	bool has = false;
//	for (list<Employee>::iterator nowit = employees.begin(); nowit != employees.end(); nowit++) {
//		if ((*nowit).getName() == name) {
//			(*nowit).display();
//			has = true;
//		}
//	}
//	if (!has) {
//		cout << "该员工不存在或已删除！" << endl;
//	}
//}

////根据员工姓名和编号查询全部信息
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
//				//展示内容
//			}
//			has = true;
//		}
//	}
//	if (!has) {
//		//cout << "该员工不存在或已删除！" << endl;
//	}
//}

////根据名字和编号判断唯一的这一员工对象是否存在
//bool searchByName_NO(list<Employee> employees, string name, string no) {
//	bool has = false;
//	for (list<Employee>::iterator nowit = employees.begin(); nowit != employees.end(); nowit++) {
//		if ((*nowit).getName() == name && (*nowit).getNo() == no) {
//			has = true;
//		}
//	}
//	return has;
//}

//判断容器中是否含有employee对象
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



//刷新硬盘的链表
void myFlush(list<Employee>* list) {
	string dbfile = "file.txt";
	ofstream fileout(dbfile.c_str(), ios::out | ios::trunc);
	fileout.close();
	std::ofstream fout("file.txt");
	boost::archive::text_oarchive oa(fout);//

	oa << *list;
	fout.close();
}

//得到当前时间
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

//日志
//输出文本到字符串,记录登陆时间
void journal() {
	ofstream out;
	out.open("journal.txt", ios::out | ios::app);
	out << getSystemTime() << " " << "登录系统！" << endl;
	out.close();
}

//记录信息操作
void journal(Employee object, string operation) {
	ofstream out;
	out.open("journal.txt", ios::app);
	out << getSystemTime() << " " << "编号为：" << object.getNo() << "的" << object.getName() << "被" << operation << endl;
	out.close();
}

//通过编号查找人
bool searchByNumber(list<Employee> employees, string no) {
	bool has_person = false;
	for (list<Employee>::iterator nowit = employees.begin(); nowit != employees.end(); nowit++) {
		if ((*nowit).getNo() == no) {
			has_person = true;
		}
	}
	return has_person;
}

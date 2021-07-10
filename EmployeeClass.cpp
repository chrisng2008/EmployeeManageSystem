#include"EmployeeClass.h"

extern class Manager;

Manager::Manager() {}
Manager::Manager(string name, string no, string salGrade, double sal, string job) {
    this->name = name;
    this->no = no;
    this->salGrade = salGrade;
    this->salary = sal;
    this->job = job;
}

Psalesman::Psalesman() {}
Psalesman::Psalesman(string name, string no, string salGrade, double sal, string job) {
    this->name = name;
    this->no = no;
    this->salGrade = salGrade;
    this->salary = sal;
    this->job = job;
}
//��ְ������Ա��н�ǹ̶���н+������*��λ������нˮ
double Psalesman::totalSal(double saleNum, double money) {
    return this->salary + saleNum * money;
}

Ptechnologist::Ptechnologist() {}
Ptechnologist::Ptechnologist(string name, string no, string salGrade, double sal, string job) {
    this->name = name;
    this->no = no;
    this->salGrade = salGrade;
    this->salary = sal;
    this->job = job;
}
//��ְ������Ա��н�ǹ̶���н+Сʱ*Сʱнˮ
double Ptechnologist::totalSal(int hours, double money) {
    return this->salary + hours * money;
}

SaleManager::SaleManager() {}
SaleManager::SaleManager(string name, string no, string salGrade, double sal, string job) {
    this->name = name;
    this->no = no;
    this->salGrade = salGrade;
    this->salary = sal;
    this->job = job;
}
double SaleManager::total(int sales, double money) {
    return this->salary + sales * money;
}

Employee::Employee() {}
Employee::Employee(string name, string no, string salGrade, double sal, string job) {
    this->name = name;
    this->no = no;
    this->salGrade = salGrade;
    this->salary = sal;
    this->job = job;
}
Employee::~Employee() {}

//���·���ʵ��Ա�����ֵ�����
void Employee::setName(string newData) {
    this->name = newData;
}

//�޸�Ա���ı��
void Employee::setNo(string newNo) {
    this->no = newNo;
}

//�޸�Ա���Ĺ��ʵȼ�
void Employee::setSalgrade(string newData) {
    this->salGrade = newData;
}

//�޸�Ա������
void Employee::setSalary(double newSal) {
    this->salary = newSal;
}
void Employee::setJob(string newJob) {
    if (!(newJob == "MANAGER" || newJob == "PTECHNOLOGIST" || newJob == "SALESMANAGER" ||
        newJob == "PSALESMAN" || newJob == "noWorked")) {
        //cout << "���������Ϣ���Ϸ�������������:" << endl;
    }
    this->job = newJob;
}

//Ա���ӱ��ְλ��ɼ�ְ������Ա
Ptechnologist Employee::toPtechnologist() {
    Ptechnologist ptechnologist(this->name, this->no, this->salGrade, this->salary, "PTECHNOLOGIST");
    return ptechnologist;
}

//Ա���ӱ��ְλ��ɾ���
Manager Employee::toManager() {
    Manager manager(this->name, this->no, this->salGrade, this->salary, "MANAGER");
    return  manager;
}

//Ա���ӱ��ְλ������۾���
SaleManager Employee::toSaleManager() {
    SaleManager salemanager(this->name, this->no, this->salGrade, this->salary, "SALESMANAGER");
    return salemanager;
}

//Ա���ӱ��ְλ��ɼ�ְ����Ա
Psalesman Employee::toPsalesman() {
    Psalesman psalesman(this->name, this->no, this->salGrade, this->salary, "PSALESMAN");
    return psalesman;
}

//����Ա����н�ܶ�������
double Employee::totalSal() {
    return this->salary;
}

//�õ�Ա������
string Employee::getName() {
    return this->name;
}

//�õ�Ա���ı��
string Employee::getNo() {
    return this->no;
}

//�õ�Ա���ĸ�λ����
string Employee::getJob() {
    return this->job;
}

//�õ�Ա���Ĺ�н�ȼ�
string Employee::getSalGrade() {
    return this->salGrade;
}

//�õ�Ա���ĵ�н
double Employee::getSalary() {
    return this->salary;
}

//�Ƚ�����Ա���Ƿ���ͬ
bool Employee::equal(Employee other) {
    if (this->name == other.getName() && this->no == other.getNo()) {
        return true;
    }
    return false;
}
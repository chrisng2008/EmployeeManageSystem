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
//兼职销售人员月薪是固定月薪+销售量*单位销售量薪水
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
//兼职技术人员月薪是固定月薪+小时*小时薪水
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

//以下方法实现员工名字的设置
void Employee::setName(string newData) {
    this->name = newData;
}

//修改员工的编号
void Employee::setNo(string newNo) {
    this->no = newNo;
}

//修改员工的工资等级
void Employee::setSalgrade(string newData) {
    this->salGrade = newData;
}

//修改员工工资
void Employee::setSalary(double newSal) {
    this->salary = newSal;
}
void Employee::setJob(string newJob) {
    if (!(newJob == "MANAGER" || newJob == "PTECHNOLOGIST" || newJob == "SALESMANAGER" ||
        newJob == "PSALESMAN" || newJob == "noWorked")) {
        //cout << "您输入的信息不合法！请重新输入:" << endl;
    }
    this->job = newJob;
}

//员工从别的职位变成兼职技术人员
Ptechnologist Employee::toPtechnologist() {
    Ptechnologist ptechnologist(this->name, this->no, this->salGrade, this->salary, "PTECHNOLOGIST");
    return ptechnologist;
}

//员工从别的职位变成经理
Manager Employee::toManager() {
    Manager manager(this->name, this->no, this->salGrade, this->salary, "MANAGER");
    return  manager;
}

//员工从别的职位变程销售经理
SaleManager Employee::toSaleManager() {
    SaleManager salemanager(this->name, this->no, this->salGrade, this->salary, "SALESMANAGER");
    return salemanager;
}

//员工从别的职位变成兼职销售员
Psalesman Employee::toPsalesman() {
    Psalesman psalesman(this->name, this->no, this->salGrade, this->salary, "PSALESMAN");
    return psalesman;
}

//计算员工月薪总而并返回
double Employee::totalSal() {
    return this->salary;
}

//得到员工姓名
string Employee::getName() {
    return this->name;
}

//得到员工的编号
string Employee::getNo() {
    return this->no;
}

//拿到员工的岗位名称
string Employee::getJob() {
    return this->job;
}

//得到员工的工薪等级
string Employee::getSalGrade() {
    return this->salGrade;
}

//得到员工的底薪
double Employee::getSalary() {
    return this->salary;
}

//比较两个员工是否相同
bool Employee::equal(Employee other) {
    if (this->name == other.getName() && this->no == other.getNo()) {
        return true;
    }
    return false;
}
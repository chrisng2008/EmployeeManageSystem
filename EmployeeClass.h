#pragma once
#include <iostream>
#include <string.h>
#include <boost/serialization/list.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <list>
#include <fstream>
#include <windows.h>//用于得到windows的系统时间

typedef boost::archive::text_iarchive iarchive;
typedef boost::archive::text_oarchive oarchive;
using namespace std;

enum  Order {
    ADD = 49, DETELE, UPDATE, SEARCH, TOTALSALARY, EXIT
};
enum Update {
    NAME = 49, NO, SALGRADE, SALARY, JOB
};

extern class Manager;
extern class SaleManager;
extern class Ptechnologist;
extern class Psalesman;

class Employee {
    friend class boost::serialization::access;

protected:   
    string name;            //员工姓名
    string no;              //员工编号
    string salGrade;        //员工薪等级
    double salary;          //员工当月薪水
    string job;             //员工的工作

	list<Employee> list;
	template<class Arichive>
	void serialize(Arichive& ar, const unsigned int)
	{
		ar& name;
		ar& no;
		ar& salGrade;
		ar& salary;
		ar& job;
	}

public:
    Employee();
    Employee(string name, string no, string salGrade, double sal, string job);
    ~Employee();
    void setName(string newData);           //修改员工的名字
    void setNo(string newNo);               //修改员工的编号
    void setSalgrade(string newData);       //修改员工的工资等级
    void setSalary(double newSal);          //修改员工的工资
    void setJob(string newJob);             //修改员工的职位
    Ptechnologist toPtechnologist();        //把员工从别的职位转为兼职技术人员
    Manager toManager();                    //把员工从别的职位转为经理
    SaleManager toSaleManager();            //把员工从别的职位转为销售经理
    Psalesman toPsalesman();                //把员工从别的职位转为兼职销售人员
    double totalSal();                      //计算员工月薪总额并返回
    string getName();                       //得到员工姓名
    string getNo();                         //得到员工的编号
    string getJob();                        //拿到员工的岗位名称
    string getSalGrade();                   //拿到员工的工薪等级
    double getSalary();                     //拿到员工的月薪底薪
    bool equal(Employee other);             //比较两个员工是否相同
};

class Manager :
    public Employee
{
public:
    Manager();
    Manager(string name, string no, string salGrade, double sal, string job);
};

class Psalesman :
    public Employee
{
public:
    Psalesman(string name, string no, string salGrade, double sal, string job);
    Psalesman();
    double totalSal(double saleNum, double money);//兼职销售人员月薪是固定月薪+销售量*单位销售量薪水
};

class Ptechnologist :
    public Employee
{
public:
    Ptechnologist();
    Ptechnologist(string name, string no, string salGrade, double sal, string job);
    double totalSal(int hours, double money);//兼职技术人员月薪是固定月薪+小时*小时薪水
};

class SaleManager :
    public Employee
{
public:
    SaleManager();
    SaleManager(string name, string no, string salGrade, double sal, string job);
    double total(int sales, double money);//根据当月的提成和固定月薪得到月薪总额
};

/*static void saveData(const Employee& obj, std::string fileName)
{
    std::ofstream ofs(fileName.c_str());
    oarchive oa(ofs);
    oa << obj;
}


static void loadData(Employee& obj, std::string fileName)
{
    std::ifstream ifs(fileName.c_str());
    iarchive ia(ifs);
    ia >> obj;
}*/
#pragma once
#include <iostream>
#include <string.h>
#include <boost/serialization/list.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <list>
#include <fstream>
#include <windows.h>//���ڵõ�windows��ϵͳʱ��

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
    string name;            //Ա������
    string no;              //Ա�����
    string salGrade;        //Ա��н�ȼ�
    double salary;          //Ա������нˮ
    string job;             //Ա���Ĺ���

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
    void setName(string newData);           //�޸�Ա��������
    void setNo(string newNo);               //�޸�Ա���ı��
    void setSalgrade(string newData);       //�޸�Ա���Ĺ��ʵȼ�
    void setSalary(double newSal);          //�޸�Ա���Ĺ���
    void setJob(string newJob);             //�޸�Ա����ְλ
    Ptechnologist toPtechnologist();        //��Ա���ӱ��ְλתΪ��ְ������Ա
    Manager toManager();                    //��Ա���ӱ��ְλתΪ����
    SaleManager toSaleManager();            //��Ա���ӱ��ְλתΪ���۾���
    Psalesman toPsalesman();                //��Ա���ӱ��ְλתΪ��ְ������Ա
    double totalSal();                      //����Ա����н�ܶ����
    string getName();                       //�õ�Ա������
    string getNo();                         //�õ�Ա���ı��
    string getJob();                        //�õ�Ա���ĸ�λ����
    string getSalGrade();                   //�õ�Ա���Ĺ�н�ȼ�
    double getSalary();                     //�õ�Ա������н��н
    bool equal(Employee other);             //�Ƚ�����Ա���Ƿ���ͬ
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
    double totalSal(double saleNum, double money);//��ְ������Ա��н�ǹ̶���н+������*��λ������нˮ
};

class Ptechnologist :
    public Employee
{
public:
    Ptechnologist();
    Ptechnologist(string name, string no, string salGrade, double sal, string job);
    double totalSal(int hours, double money);//��ְ������Ա��н�ǹ̶���н+Сʱ*Сʱнˮ
};

class SaleManager :
    public Employee
{
public:
    SaleManager();
    SaleManager(string name, string no, string salGrade, double sal, string job);
    double total(int sales, double money);//���ݵ��µ���ɺ͹̶���н�õ���н�ܶ�
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
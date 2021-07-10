#pragma once
#include "EmployeeClass.h"

//判断文件是否存在
bool isExists(const std::string& name);

//判断员工职位是否为兼职人员
bool isPart_time(Employee person);

//判断员工是否是销售经理
bool isSalesManger(Employee person);

//输出一个销售经理的全部信息
//void showSMAll(Employee person);

//输出一个兼职人员的所有信息
//void showAll(Employee person);

//按员工的姓名查找
//void searchByName(list<Employee> employees, string name);

//按员工的编号查询
void searchByNo(list<Employee> employees, string no);

////根据员工姓名和编号查询全部信息
//void searchTotal(list<Employee> employees, string name, string no);
//
////根据名字和编号判断唯一的这一员工对象是否存在
//bool searchByName_NO(list<Employee> employees, string name, string no);

//判断容器中是否含有employee对象
bool contains(list<Employee> employees, Employee employee);

//刷新硬盘的链表
void myFlush(list<Employee>* list);

//得到当前时间
string getSystemTime();

//日志
//输出文本到字符串,记录登陆时间
void journal();

//记录信息操作
void journal(Employee object, string operation);

//通过编号查找人
bool searchByNumber(list<Employee> employees, string no);
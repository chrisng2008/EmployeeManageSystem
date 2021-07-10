#pragma once
#include "EmployeeClass.h"

//�ж��ļ��Ƿ����
bool isExists(const std::string& name);

//�ж�Ա��ְλ�Ƿ�Ϊ��ְ��Ա
bool isPart_time(Employee person);

//�ж�Ա���Ƿ������۾���
bool isSalesManger(Employee person);

//���һ�����۾����ȫ����Ϣ
//void showSMAll(Employee person);

//���һ����ְ��Ա��������Ϣ
//void showAll(Employee person);

//��Ա������������
//void searchByName(list<Employee> employees, string name);

//��Ա���ı�Ų�ѯ
void searchByNo(list<Employee> employees, string no);

////����Ա�������ͱ�Ų�ѯȫ����Ϣ
//void searchTotal(list<Employee> employees, string name, string no);
//
////�������ֺͱ���ж�Ψһ����һԱ�������Ƿ����
//bool searchByName_NO(list<Employee> employees, string name, string no);

//�ж��������Ƿ���employee����
bool contains(list<Employee> employees, Employee employee);

//ˢ��Ӳ�̵�����
void myFlush(list<Employee>* list);

//�õ���ǰʱ��
string getSystemTime();

//��־
//����ı����ַ���,��¼��½ʱ��
void journal();

//��¼��Ϣ����
void journal(Employee object, string operation);

//ͨ����Ų�����
bool searchByNumber(list<Employee> employees, string no);
#pragma once

#include <QWidget>
#include <Qmessagebox>
#include "ui_ModifyWidget.h"
#include "enumHead.h"
#include "EmployeeClass.h"
#include "functions.h"

class ModifyWidget : public QWidget
{
	Q_OBJECT

public:
	ModifyWidget(QWidget *parent = Q_NULLPTR);
	~ModifyWidget();

signals:
	void display_Widget(int number);

private slots:
	void on_returnButton_clicked();	//���˵���ť
	void on_deleteButton_clicked();	//ɾ����ť
	void on_modifyButton_clicked(); //�޸İ�ť

private:
	Ui::ModifyWidget ui;
};

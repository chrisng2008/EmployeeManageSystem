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
	void on_returnButton_clicked();	//主菜单按钮
	void on_deleteButton_clicked();	//删除按钮
	void on_modifyButton_clicked(); //修改按钮

private:
	Ui::ModifyWidget ui;
};

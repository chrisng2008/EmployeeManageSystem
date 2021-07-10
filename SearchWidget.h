#pragma once

#include <QWidget>
#include "ui_SearchWidget.h"
#include "enumHead.h"
#include <QMessageBox>

#include "EmployeeClass.h"
#include "functions.h"

class SearchWidget : public QWidget
{
	Q_OBJECT

public:
	SearchWidget(QWidget *parent = Q_NULLPTR);
	~SearchWidget();

signals:
	void display_Widget(int number);

private slots:
	void on_returnButton_clicked();	//主菜单按钮
	void on_searchButton_clicked();	//搜索按钮
private:
	Ui::SearchWidget ui;
};

#pragma once
#include <QWidget>
#include "ui_AddWidget.h"
#include "enumHead.h"
#include <QMessageBox>
#include "qstring.h"
#include "EmployeeClass.h"

class AddWidget : public QWidget
{
	Q_OBJECT

public:
	AddWidget(QWidget *parent = Q_NULLPTR);
	~AddWidget();

signals:
	void display_Widget(int number);

private slots:
	void on_returnButton_clicked();
	void on_addButton_clicked();

private:
	Ui::AddWidget ui;
};

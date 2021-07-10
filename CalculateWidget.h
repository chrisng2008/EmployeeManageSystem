#pragma once

#include <QWidget>
#include <QButtongroup>
#include <QMessageBox>
#include "ui_CalculateWidget.h"
#include "EmployeeClass.h"
#include "enumHead.h"
#include "functions.h"

class CalculateWidget : public QWidget
{
	Q_OBJECT

public:
	CalculateWidget(QWidget *parent = Q_NULLPTR);
	~CalculateWidget();

signals:
	void display_Widget(int number);

private slots:
	void on_returnButton_clicked();
	void on_calculateButton_clicked();
	void on_searchButton_clicked();
	void on_refleshButton_clicked();
private:
	Ui::CalculateWidget ui;
	QButtonGroup* typeInButtonGroup;
	double salary;
	int kindOfJob = 0;
};

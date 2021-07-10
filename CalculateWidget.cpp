#include "CalculateWidget.h"

CalculateWidget::CalculateWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

CalculateWidget::~CalculateWidget()
{
}

void CalculateWidget::on_returnButton_clicked()
{
	emit display_Widget(menuWidget);
}

//查询按钮
void CalculateWidget::on_searchButton_clicked()
{
	string tnumber = ui.numberLineEdit->text().toStdString();
	extern list<Employee> employees;
	for (list<Employee>::iterator nowit = employees.begin(); nowit != employees.end(); nowit++)
	{
		if ((*nowit).getNo() == tnumber) {
			salary = (*nowit).getSalary();
			if ((*nowit).getJob() == "MANAGER") {
				ui.jobShowLabel->setText("The employee is a manager");
				ui.totalSalShowLabel->setText(QString::number(salary));
				return;
			}
			else if ((*nowit).getJob() == "SALESMANAGER" ) {
				ui.jobShowLabel->setText("The empolyee is a sales manager");
				ui.typeInShowLabel->setText("please enter the sales:");
				kindOfJob = 1;
				return;
			}
			else if ((*nowit).getJob() == "PSALESMAN") {
				ui.jobShowLabel->setText("The employee is a Part-time sales staff");
				ui.typeInShowLabel->setText("please enter the sales:");
				kindOfJob = 1;
				return;
			}
			else {
				ui.jobShowLabel->setText("The employee is Part-time technician");
				ui.typeInShowLabel->setText("please enter the length of work:");
				kindOfJob = 2;
				return;
			}
		}
	}
}

//计算按钮
void CalculateWidget::on_calculateButton_clicked()
{
	double typeIn = ui.typeInLineEdit->text().toDouble();
	double totalSal = 0;
	switch (kindOfJob)
	{
	case 0:
		totalSal = salary;
		break;
	case 1:
		totalSal = salary + sales * typeIn;
		break;
	case 2:
		totalSal = salary + workHour * typeIn;
		break;
	}
	ui.totalSalShowLabel->setText(QString::number(totalSal));
}

//清空按钮
void CalculateWidget::on_refleshButton_clicked()
{
	ui.numberLineEdit->clear();
	ui.jobShowLabel->clear();
	ui.typeInShowLabel->clear();
	ui.typeInLineEdit->clear();
	ui.totalSalShowLabel->clear();
}
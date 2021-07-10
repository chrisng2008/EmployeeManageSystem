#include "SearchWidget.h"

SearchWidget::SearchWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

SearchWidget::~SearchWidget()
{
}

//主菜单按钮点击
void SearchWidget::on_returnButton_clicked() {
	//将控件重新初始化
	ui.numberrLineEdit->clear();
	ui.nameShowLabel->setText("NULL");
	ui.salGradeShowLabel->setText("NULL");
	ui.salaryShowLabel->setText("NULL");
	ui.jobShowLabel->setText("NULL");

	emit display_Widget(menuWidget);
}


//查询按钮点击
void SearchWidget::on_searchButton_clicked() {
	extern list<Employee> employees;
	if (ui.numberrLineEdit->text() == "")
	{
		QMessageBox::about(NULL, "WARNING", "Number cannot be empty");
		return;
	}

	QString number = ui.numberrLineEdit->text();
	string tnumber = number.toStdString();

	bool has_person = false;

	for (list<Employee>::iterator nowit = employees.begin(); nowit != employees.end(); nowit++) {
		if ((*nowit).getNo() == tnumber)
		{	
			has_person = true;
			ui.nameShowLabel->setText(QString::fromStdString((*nowit).getName()));
			ui.salGradeShowLabel->setText(QString::fromStdString((*nowit).getSalGrade()));
			ui.salaryShowLabel->setText(QString("%1").arg((*nowit).getSalary()));
			ui.jobShowLabel->setText(QString::fromStdString((*nowit).getJob()));
			return;
		}
	}
	
	if  (!has_person)
	{
		QMessageBox::about(NULL, "WARNING", "The number does not exist");
		return;
	}
}
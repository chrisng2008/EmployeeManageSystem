#include "AddWidget.h"
#include "functions.h"

AddWidget::AddWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

AddWidget::~AddWidget()
{
}

//主菜单按钮点击
void AddWidget::on_returnButton_clicked() 
{
	ui.nameLineEdit->clear();
	ui.numberLineEdit->clear();
	ui.jobLineEdit->clear();
	ui.salGradeLineEdit->clear();
	ui.salaryLineEdit->clear();

	emit display_Widget(menuWidget);
}

//添加按钮点击
void AddWidget::on_addButton_clicked()
{
	//填写信息必须完整，否则提示错误
	if (ui.nameLineEdit->text() == "" || ui.numberLineEdit->text() == "" ||
		ui.salGradeLineEdit->text() == "" || ui.salaryLineEdit->text() == "")
	{
		QMessageBox::about(NULL, "WARNING", "Please fill in the complete information");
		return;
	}

	//名字、编号、工薪等级、工作
	QString name =  ui.nameLineEdit->text();
	QString no = ui.numberLineEdit->text();
	QString salGrade = ui.salGradeLineEdit->text();
	QString job = ui.jobLineEdit->text();
	double tsalary = ui.salaryLineEdit->text().toDouble();

	string tname = name.toStdString();
	string tno = no.toStdString();
	string tsalGrade = salGrade.toStdString();
	string tjob = job.toStdString();

	//判断职位输入是否合法
	if (!(tjob == "MANAGER" || tjob == "PTECHNOLOGIST" || tjob == "SALESMANAGER" || tjob == "PSALESMAN" || tjob == "noWorked"))
	{
		QMessageBox::about(NULL, "WARNING", "Please enter the correct job");
		return;
	}

	extern list<Employee> employees;

	if (!searchByNumber) {
		QMessageBox::about(NULL, "WARNING", "The employee already exists");
		return;
	}

	Employee* person = new Employee(tname, tno, tsalGrade, tsalary, tjob);

	employees.push_back(*person);
	myFlush(&employees);
	QMessageBox::about(NULL, "REACTION", "Added successfully");
	journal(*person, "添加!");

	//删除文件中已经有的链表对象，把内存中更新后的链表重新反序列化回文件中
	myFlush(&employees);

	ui.nameLineEdit->clear();
	ui.numberLineEdit->clear();
	ui.jobLineEdit->clear();
	ui.salGradeLineEdit->clear();
	ui.salaryLineEdit->clear();
}
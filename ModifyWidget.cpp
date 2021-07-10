#include "ModifyWidget.h"

ModifyWidget::ModifyWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

ModifyWidget::~ModifyWidget()
{
}

//主菜单按钮
void ModifyWidget::on_returnButton_clicked() {
	ui.nameLineEdit->clear();
	ui.jobLineEdit->clear();
	ui.salGradeLineEdit->clear();
	ui.salaryLineEdit->clear();
	ui.numberLineEdit->clear();

	emit display_Widget(menuWidget);
}

//删除按钮
void ModifyWidget::on_deleteButton_clicked() 
{
	extern list<Employee> employees;
	bool has = true;
	char user_input_todelete = '\0';

	QString name = ui.nameLineEdit->text();
	QString no = ui.numberLineEdit->text();
	string tname = name.toStdString();
	string tno = no.toStdString();

	for (list<Employee>::iterator nowit = employees.begin(); nowit != employees.end(); nowit++) 
	{
		if ((*nowit).getName() == tname && (*nowit).getNo() == tno) {
			journal(*nowit, "删除!");
			employees.erase(nowit);
			myFlush(&employees);
			QMessageBox::about(NULL, "REACTION", "successfully deleted");										//此处可增加代码用于删除时进行提问再次确认
			return;
		}
		else {
			QMessageBox::about(NULL, "WARNING", "The employee does not exist or has been deleted");
		}
	}

	ui.nameLineEdit->clear();
	ui.numberLineEdit->clear();
}

//修改按钮
void ModifyWidget::on_modifyButton_clicked() 
{
	extern list<Employee> employees;

	QString name = ui.nameLineEdit->text();
	QString no = ui.numberLineEdit->text();
	QString salGrade = ui.salGradeLineEdit->text();
	QString job = ui.jobLineEdit->text();
	double tsalary = ui.salaryLineEdit->text().toDouble();

	string tname = name.toStdString();
	string tno = no.toStdString();
	string tsalGrade = salGrade.toStdString();
	string tjob = job.toStdString();


	//修改信息也要填写完整
	if (ui.nameLineEdit->text() == "" || ui.numberLineEdit->text() == "" ||
		ui.salaryLineEdit->text() == "" || ui.salGradeLineEdit->text() == "")
	{
		QMessageBox::about(NULL, "WARNING", "Please modify the complete information");
		return;
	}

	//对应删除和增加
	for (list<Employee>::iterator nowit = employees.begin(); nowit != employees.end(); nowit++) {
		if ((*nowit).getNo() == tno)
		{
			Employee* person = new Employee(tname, tno, tsalGrade, tsalary, tjob);
			employees.push_back(*person);
			journal(*nowit, "删除!");
			journal(*person, "增加!");
			employees.erase(nowit);
			myFlush(&employees);
			QMessageBox::about(NULL, "REACTION", "The modification was successful");

			ui.nameLineEdit->clear();
			ui.numberLineEdit->clear();
			ui.salGradeLineEdit->clear();
			ui.jobLineEdit->clear();
			ui.salaryLineEdit->clear();

			return;
		}
	}
}
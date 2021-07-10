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

//���˵���ť���
void AddWidget::on_returnButton_clicked() 
{
	ui.nameLineEdit->clear();
	ui.numberLineEdit->clear();
	ui.jobLineEdit->clear();
	ui.salGradeLineEdit->clear();
	ui.salaryLineEdit->clear();

	emit display_Widget(menuWidget);
}

//��Ӱ�ť���
void AddWidget::on_addButton_clicked()
{
	//��д��Ϣ����������������ʾ����
	if (ui.nameLineEdit->text() == "" || ui.numberLineEdit->text() == "" ||
		ui.salGradeLineEdit->text() == "" || ui.salaryLineEdit->text() == "")
	{
		QMessageBox::about(NULL, "WARNING", "Please fill in the complete information");
		return;
	}

	//���֡���š���н�ȼ�������
	QString name =  ui.nameLineEdit->text();
	QString no = ui.numberLineEdit->text();
	QString salGrade = ui.salGradeLineEdit->text();
	QString job = ui.jobLineEdit->text();
	double tsalary = ui.salaryLineEdit->text().toDouble();

	string tname = name.toStdString();
	string tno = no.toStdString();
	string tsalGrade = salGrade.toStdString();
	string tjob = job.toStdString();

	//�ж�ְλ�����Ƿ�Ϸ�
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
	journal(*person, "���!");

	//ɾ���ļ����Ѿ��е�������󣬰��ڴ��и��º���������·����л����ļ���
	myFlush(&employees);

	ui.nameLineEdit->clear();
	ui.numberLineEdit->clear();
	ui.jobLineEdit->clear();
	ui.salGradeLineEdit->clear();
	ui.salaryLineEdit->clear();
}
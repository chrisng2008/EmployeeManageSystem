#include "MenuWidget.h"

MenuWidget::MenuWidget(QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    extern list<Employee> employees;
    int sizeOf_list = 0;

    //计算list长度
    for (list<Employee>::iterator nowit = employees.begin(); nowit != employees.end(); nowit++) {
        sizeOf_list++;
    }

    /*if (sizeOf_list == 0)
    {
        QMessageBox::about(NULL, "REACTION", "No employee information");
    }*/

    //设置和list长度一样的行数
    ui.tableWidget->setRowCount(sizeOf_list);
    ui.tableWidget->setColumnCount(5);

    //表格头行
    QStringList headerLabels;
    headerLabels << tr("NAME") << tr("ID") << tr("JOB") << tr("SAL_GRADE") << tr("SALARY");
    ui.tableWidget->setHorizontalHeaderLabels(headerLabels);
    //根据总宽度调整列宽
    ui.tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //设置显示格子线
    ui.tableWidget->setShowGrid(true);
    //禁止编辑
    ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //生成表格
    list<Employee>::iterator nowit = employees.begin();
    Employee temp = *nowit;
    for (int i = 0; i < sizeOf_list; i++) {
        ui.tableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString((*nowit).getName())));
        ui.tableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString((*nowit).getNo())));
        ui.tableWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString((*nowit).getJob())));
        ui.tableWidget->setItem(i, 3, new QTableWidgetItem(QString::fromStdString((*nowit).getSalGrade())));
        ui.tableWidget->setItem(i, 4, new QTableWidgetItem(QString("%1").arg((*nowit).getSalary())));
        nowit++;
    }
}

//页面的跳转
void MenuWidget::on_addButton_clicked()
{
    emit display_Widget(addWidget);
}
void MenuWidget::on_searchButton_clicked()
{
    emit display_Widget(searchWidget);
}

void MenuWidget::on_modifyButton_clicked()
{
    emit display_Widget(modifyWidget);
}

void MenuWidget::on_exitButton_clicked()
{
    
}

void MenuWidget::on_calculateButton_clicked()
{
    emit display_Widget(calculateWidget);
}

void MenuWidget::on_reflashButton_clicked()
{
    ui.tableWidget->clearContents();

    extern list<Employee> employees;
    int sizeOf_list = 0;

    //计算list长度
    for (list<Employee>::iterator nowit = employees.begin(); nowit != employees.end(); nowit++) {
        sizeOf_list++;
    }

    list<Employee>::iterator nowit = employees.begin();
    Employee temp = *nowit;
    for (int i = 0; i < sizeOf_list; i++) {
        ui.tableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString((*nowit).getName())));
        ui.tableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString((*nowit).getNo())));
        ui.tableWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString((*nowit).getJob())));
        ui.tableWidget->setItem(i, 3, new QTableWidgetItem(QString::fromStdString((*nowit).getSalGrade())));
        ui.tableWidget->setItem(i, 4, new QTableWidgetItem(QString("%1").arg((*nowit).getSalary())));
        nowit++;
    }
}
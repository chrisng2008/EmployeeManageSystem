#pragma once

#include <QtWidgets/QWidget>
#include <QMessageBox>
#include "ui_MenuWidget.h"
#include "enumHead.h"
#include "EmployeeClass.h"
#include "functions.h"

class MenuWidget : public QWidget
{
    Q_OBJECT
       
public:
    MenuWidget(QWidget *parent = Q_NULLPTR);

signals:
    void display_Widget(int number);

private slots:
    void on_addButton_clicked();
    void on_searchButton_clicked();
    void on_modifyButton_clicked();
    void on_exitButton_clicked();
    void on_reflashButton_clicked();
    void on_calculateButton_clicked();
private:
    Ui::MenuWidgetClass ui;
    int sizeOf_list = 0;
};

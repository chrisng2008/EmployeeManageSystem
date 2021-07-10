#pragma once
#include <QWidget>
#include "ui_MainWidget.h"
#include <QStackedLayout>
#include "MenuWidget.h"
#include "AddWidget.h"
#include "SearchWidget.h"
#include "ModifyWidget.h"
#include "CalculateWidget.h"
#include "functions.h"

class MainWidget : public QWidget
{
	Q_OBJECT

public:
	MainWidget(QWidget *parent = Q_NULLPTR);
	~MainWidget();

private:
	Ui::MainWidget ui;

	MenuWidget* menu_widget;			//菜单窗口
	AddWidget* add_widget;				//添加员工窗口
	SearchWidget* search_widget;		//查询窗口
	ModifyWidget* modify_widget;		//修改窗口
	CalculateWidget* calculate_widget;	//计算窗口
	QStackedLayout* stackLayout;		//QStackedLayout布局
};

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

	MenuWidget* menu_widget;			//�˵�����
	AddWidget* add_widget;				//���Ա������
	SearchWidget* search_widget;		//��ѯ����
	ModifyWidget* modify_widget;		//�޸Ĵ���
	CalculateWidget* calculate_widget;	//���㴰��
	QStackedLayout* stackLayout;		//QStackedLayout����
};

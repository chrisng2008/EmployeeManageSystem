#include "MainWidget.h"

MainWidget::MainWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setFixedSize(500, 500);

	menu_widget = new MenuWidget;
	add_widget = new AddWidget;
	search_widget = new SearchWidget;
	modify_widget = new ModifyWidget;
	calculate_widget = new CalculateWidget;
	stackLayout = new QStackedLayout;

	stackLayout->addWidget(menu_widget);
	stackLayout->addWidget(add_widget);
	stackLayout->addWidget(search_widget);
	stackLayout->addWidget(modify_widget);
	stackLayout->addWidget(calculate_widget);
	setLayout(stackLayout);

	connect(menu_widget, &MenuWidget::display_Widget, stackLayout, &QStackedLayout::setCurrentIndex);
	connect(add_widget, &AddWidget::display_Widget, stackLayout, &QStackedLayout::setCurrentIndex);
	connect(search_widget, &SearchWidget::display_Widget, stackLayout, &QStackedLayout::setCurrentIndex);
	connect(modify_widget, &ModifyWidget::display_Widget, stackLayout, &QStackedLayout::setCurrentIndex);
	connect(calculate_widget, &CalculateWidget::display_Widget, stackLayout, &QStackedLayout::setCurrentIndex);
}

MainWidget::~MainWidget()
{
}

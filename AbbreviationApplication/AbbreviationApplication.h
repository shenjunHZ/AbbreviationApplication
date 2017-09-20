#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_AbbreviationApplication.h"

class AbbreviationApplication : public QMainWindow
{
	Q_OBJECT

public:
	AbbreviationApplication(QWidget *parent = Q_NULLPTR);

private:
	Ui::AbbreviationApplicationClass ui;
};

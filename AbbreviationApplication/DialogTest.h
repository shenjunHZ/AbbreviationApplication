#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QDialog>

#include "ui_DialogTest.h"

namespace Ui
{
	class DialogTest;
}

namespace TestWidget
{
	class DialogTest : public QDialog
	{
	public:
		DialogTest(QWidget* pParent = nullptr);
		~DialogTest();

	private:
		Ui::DialogTest* m_pUi;
	};
}
#include "DialogTest.h"

namespace TestWidget
{

	DialogTest::DialogTest(QWidget* pParent/* = nullptr*/)
		: QDialog(pParent),
		m_pUi(nullptr)
	{
		m_pUi = new Ui::DialogTest();
		m_pUi->setupUi(this);

		this->setWindowFlags(windowFlags() | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
	}

	DialogTest::~DialogTest()
	{

	}

}
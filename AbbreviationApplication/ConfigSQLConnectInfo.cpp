#include "ConfigSQLConnectInfo.h"
#include "commonControl.h"
#include "ui_ConfigSQLConnectInfo.h"

#include <QtCore/QRect>

namespace mainApp
{

	ConfigSQLConnectInfo::ConfigSQLConnectInfo(QWidget* pParent /*= nullptr*/)
		: QDialog(pParent),
		m_pUi(nullptr)
	{
		m_pUi = new Ui::ConfigSQLConnectInfo();
		m_pUi->setupUi(this);
		this->setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
		//m_pUi->setupUi(this->GetCentralWidget());

		InitUI();
		ConnectSgn();
		SET_MODULE_STYLE_BY_PATH("ConfigSQLConnectInfo");
	}

	ConfigSQLConnectInfo::~ConfigSQLConnectInfo()
	{

	}

	void ConfigSQLConnectInfo::InitUI()
	{
		m_pUi->m_pLocalSQL->setChecked(true); // Ä¬ÈÏ±¾µØ

		m_pUi->m_pLineEditIP->setText("127.0.0.1");
		m_pUi->m_pLineEditPort->setText("10086");
		m_pUi->m_pLineEditUserName->setText("root");
		m_pUi->m_pLineEditPassword->setText("root");
		SetConfigEnable(false);

		QWidget* pParent = (QWidget*)this->parent();
		QRect rect = pParent->geometry();
		this->setGeometry( (rect.x() + (pParent->width() - this->width()) / 2), (rect.y() + (pParent->height() - this->height()) / 2),
			width(), height());
		//this->move( (pParent->width() - this->width()) / 2,  (pParent->height() - this->height()) / 2);
	}

	void ConfigSQLConnectInfo::ConnectSgn()
	{
		connect(m_pUi->m_pLocalSQL,  SIGNAL(toggled(bool)), this, SLOT(OnLocalSQLToggled(bool)));
		connect(m_pUi->m_pServerSQL, SIGNAL(toggled(bool)), this, SLOT(OnServiceSQLToggled(bool)));
		connect(m_pUi->m_btnCancel,  SIGNAL(clicked()),     this, SLOT(OnClickCancel()));
		connect(m_pUi->m_btnSave,    SIGNAL(clicked()),     this, SLOT(OnClickSave()));
	}

	void ConfigSQLConnectInfo::SetConfigEnable(bool bEnable)
	{
		if (bEnable)
		{
			m_pUi->m_pLineEditIP->setDisabled(false);
			m_pUi->m_pLineEditUserName->setDisabled(false);
			m_pUi->m_pLineEditPassword->setDisabled(false);
			m_pUi->m_pLineEditPort->setDisabled(false);
		}
		else
		{
			m_pUi->m_pLineEditIP->setDisabled(true);
			m_pUi->m_pLineEditUserName->setDisabled(true);
			m_pUi->m_pLineEditPassword->setDisabled(true);
			m_pUi->m_pLineEditPort->setDisabled(true);
		}
	}

	mainApp::SQLType_e ConfigSQLConnectInfo::GetSQLType()
	{
		if (m_pUi->m_pServerSQL->isChecked())
		{
			return SQLType_e::SQL_TYPE_SERVICE;
		}
		else if (m_pUi->m_pLocalSQL->isChecked())
		{
			return SQLType_e::SQL_TYPE_LOCAL;
		}

		return SQLType_e::SQL_TYPE_SERVICE;
	}

	void ConfigSQLConnectInfo::OnLocalSQLToggled(bool bChecked)
	{
		if (bChecked)
		{
			SetConfigEnable(false);
		}
	}

	void ConfigSQLConnectInfo::OnServiceSQLToggled(bool bChecked)
	{
		if (bChecked)
		{
			SetConfigEnable(true);
		}
	}

	void ConfigSQLConnectInfo::OnClickCancel()
	{
		hide();
	}

	void ConfigSQLConnectInfo::OnClickSave()
	{
		SQLConnectInfo_s info;
		info.strHostName = m_pUi->m_pLineEditIP->text();
		info.iPort       = m_pUi->m_pLineEditPort->text().toInt();
		info.strUserName = m_pUi->m_pLineEditUserName->text();
		info.strPassword = m_pUi->m_pLineEditPassword->text();

		emit sgnConnectSQL(info);
		//hide();
	}

} // end namespace mainApp
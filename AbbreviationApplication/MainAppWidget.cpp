#include "MainAppWidget.h"
#include "commonControl.h"
#include "Common/GlobalDataCenter/GlobalDataCenter.h"
#include "SearchEdit/SearchEdit.h"
#include "ConfigSQLConnectInfo.h"
#include "SqliteDB.h"
#include "AbbreviationTable.h"
#include "MessageNotify/MessageNotify.h"
#include "MysqlDB.h"
#include "ui_MainAppWidget.h"

#include <QtGui/QPixmap>
#include <QtCore/QString>
#include <QtWidgets/QDesktopWidget>
#include <iostream>

const int g_iConstInitial = 0;
const int g_iWidthWidow = 803;
const int g_iHeighWidow = 603;

namespace mainApp
{
	MainAppWidget::MainAppWidget(QWidget* pParent /*= nullptr*/)
		: DSGUI::DSDialog(pParent, CloseButtonHint | MinimizeButtonHint| MaximizeButtonHint),
		m_pUi(nullptr),
		m_pConfigWidget(nullptr),
		m_pSqliteDB(nullptr),
		m_pAbbreviationTable(nullptr),
		m_pMysqlDB(nullptr),
		m_sqlType(SQLType::SQL_TYPE_LOCAL)
	{
		m_pUi = new Ui::MainAppWidget();  // auto delete by parent widget
		m_pUi->setupUi(this->GetCentralWidget());
		this->setAttribute(Qt::WA_TranslucentBackground, false);
		this->resize(g_iWidthWidow, g_iHeighWidow);
		this->SetTitle("5G_U8");
		this->setObjectName("MainAppWidget");
		this->SetCloseAnimaEnable(true);
		this->setWindowFlags(windowFlags() | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);

		// move to middle
		QDesktopWidget* pDeskWidget = QApplication::desktop();
		int iWidth = pDeskWidget->width();
		int iHeight = pDeskWidget->height();
		this->move((iWidth - width()) / 2, (iHeight - height()) / 2);

		OpenSqlitDB();
		StartSqlitDB();
		m_pMysqlDB = new MysqlDB::CMysqlDB();

		InitUI();
		ConnectSgn();
		SET_MODULE_STYLE_BY_PATH("MainAppWidget");
	}

	MainAppWidget::~MainAppWidget()
	{
		m_pSqliteDB->Close();
		delete m_pSqliteDB;
		m_pSqliteDB = nullptr;

		delete m_pMysqlDB;
		m_pMysqlDB = nullptr;
	}

	void MainAppWidget::InitUI()
	{
		QIcon iconItemSearch;
		iconItemSearch.addPixmap(QPixmap(commonSpace::GetSkinPath("AbbreviationApplication") + "search_normal.png"), QIcon::Normal);
		iconItemSearch.addPixmap(QPixmap(commonSpace::GetSkinPath("AbbreviationApplication") + "search_hover.png"), QIcon::Active);
		iconItemSearch.addPixmap(QPixmap(commonSpace::GetSkinPath("AbbreviationApplication") + "search_pressed.png"), QIcon::Selected);
		m_pUi->m_pToolListView->AddItem(iconItemSearch, QObject::tr("Search"));
		m_pUi->m_pToolListView->SetCurrentIndex(g_iConstInitial);

		QIcon iconItemAdd;
		iconItemAdd.addPixmap(QPixmap(commonSpace::GetSkinPath("AbbreviationApplication") + "ADD-n.png"), QIcon::Normal);
		iconItemAdd.addPixmap(QPixmap(commonSpace::GetSkinPath("AbbreviationApplication") + "ADD-h.png"), QIcon::Active);
		iconItemAdd.addPixmap(QPixmap(commonSpace::GetSkinPath("AbbreviationApplication") + "ADD-p.png"), QIcon::Selected);
		m_pUi->m_pToolListView->AddItem(iconItemAdd, QObject::tr("Add"));

		m_pUi->m_pSearchWidget->SetAbbreviationTable(m_pAbbreviationTable, m_pMysqlDB);
		m_pUi->m_pAddWidget->SetAbbreviationTable(m_pAbbreviationTable, m_pMysqlDB);

		m_pUi->funcStackedWidget->setCurrentWidget(m_pUi->m_pSearchWidget);
		m_pConfigWidget = new ConfigSQLConnectInfo(this);
		m_pConfigWidget->hide(); // first hide treate
	}

	void MainAppWidget::ConnectSgn()
	{
		bool bRet = connect(m_pUi->m_pToolListView, SIGNAL(SignalCurrentIndexChanged(int)), this, SLOT(OnCurrentIndexChanged(int)));
		std::cout << "this is for test bRet: " << bRet <<std::endl;

		connect(m_pUi->m_pSearchWord, SIGNAL(SignalSearchBtnClicked(QString&)), this, SLOT(OnSearchBtnClicked(QString&)));
		connect(m_pUi->m_btnConfig,   SIGNAL(clicked()),                        this, SLOT(OnConfigWidgetShow()));
		connect(m_pConfigWidget,      SIGNAL(sgnConnectSQL(SQLConnectInfo_s&)), this, SLOT(OnConnectSQL(SQLConnectInfo_s&)));
		connect(this,                 SIGNAL(sgnShowNotifyDlg(QString&)),       this, SLOT(OnShowNotifyDlg(QString&)));
	}

	void MainAppWidget::SetSelectWidgetType(widgetType_e nType)
	{
		switch (nType)
		{
		case widgetType_e::WIDGET_TYPE_SEARCH:
		{
			m_pUi->funcStackedWidget->setCurrentWidget(m_pUi->m_pSearchWidget);
		}
			break;
		case widgetType_e::WIDGET_TYPE_ADD:
		{
			m_pUi->funcStackedWidget->setCurrentWidget(m_pUi->m_pAddWidget);
		}
			break;
		default:
			break;
		}
	}

	void MainAppWidget::OnCurrentIndexChanged(int nIndex)
	{
		SetSelectWidgetType((widgetType_e)nIndex);
	}

	void MainAppWidget::OnSearchBtnClicked(QString& strSearchWord)
	{
		m_pUi->m_pToolListView->SetCurrentIndex(g_iConstInitial);
		SetSelectWidgetType(widgetType_e::WIDGET_TYPE_SEARCH);

		m_pUi->m_pSearchWidget->SetAcronymText(strSearchWord);
	}

	void MainAppWidget::OnConfigWidgetShow()
	{
		//ConfigSQLConnectInfo* pConfigWidget = new ConfigSQLConnectInfo(this);
		QRect rect = this->geometry();
		m_pConfigWidget->setGeometry((rect.x() + (this->width() - m_pConfigWidget->width()) / 2),
			(rect.y() + (this->height() - m_pConfigWidget->height()) / 2),
			m_pConfigWidget->width(), m_pConfigWidget->height());

		m_pConfigWidget->exec();
	}

	void MainAppWidget::ShowNotifyDlg(const QString& strNotify) const
	{
		if (!strNotify.isEmpty())
		{
			DSGUI::DSMessageNotify::Instance().AddTextNotification(strNotify);
		}
	}

	void MainAppWidget::OnShowNotifyDlg(QString& strNotify)
	{
		ShowNotifyDlg(strNotify);
	}
	/***************************about sqlit**********************************/

	bool MainAppWidget::StartSqlitDB()
	{
		m_pAbbreviationTable = new SqliteDB::AbbreviationTable("AbbreviationTable", m_pSqliteDB);

		return m_pAbbreviationTable->CreateTable();
	}

	void MainAppWidget::OpenSqlitDB()
	{
		m_pSqliteDB = new SqliteDB::CSqliteDB();

		// database_connection¶ÔÏó
		bool bOpen = m_pSqliteDB->OpenDB(Common::CGlobalDataCenter::GetInstance().GetCurrentDirPath_UTF8() + "/Abbreviation.db");
		if (!bOpen)
		{
			emit sgnShowNotifyDlg(QString::fromStdString("Open Sqlit SQL Abbreviation DB failed !"));
			return;
		}
	}

	/***********************************************************************/

	/******************************about mysql********************************************/
	void MainAppWidget::OnConnectSQL(SQLConnectInfo_s& info)
	{
		SQLType_e sqlType = m_pConfigWidget->GetSQLType();
		if (SQLType::SQL_TYPE_SERVICE == sqlType)
		{
			if (nullptr == m_pMysqlDB)
			{
				return;
			}
			bool bRec = m_pMysqlDB->connectToSql(info.strHostName, info.iPort, info.strUserName, info.strPassword);
			if (bRec)
			{
				m_pConfigWidget->hide();
			}
			else
			{
				OnShowNotifyDlg(QObject::tr("Connect MySql failed, please check the information!"));
			}

			m_sqlType = SQLType::SQL_TYPE_SERVICE;
		}
		else
		{
			m_sqlType = SQLType::SQL_TYPE_LOCAL;
			m_pConfigWidget->hide();
		}
		
		m_pUi->m_pSearchWidget->SetSQLType(m_sqlType);
		m_pUi->m_pAddWidget->SetSQLType(m_sqlType);
	}

// 	bool MainAppWidget::StartMySqlDB()
// 	{
// 		if (nullptr == m_pMysqlDB)
// 		{
// 			return;
// 		}
// 
// 		return m_pMysqlDB->CreateTable("AbbreviationTable");
// 	}
	/*************************************************************************************/

} // end namespace mainApp
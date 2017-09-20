/*
@tool    Abbreviation Search Main interface
@author  sj
@data    2017-9-3
@version 1.0
*/
#pragma once

#include <QtWidgets/QWidget>

#include "Dialog/Dialog.h"

namespace Ui
{
	class MainAppWidget;
}

namespace SqliteDB
{
	class CSqliteDB;
	class AbbreviationTable;
}

namespace MysqlDB
{
	class CMysqlDB;
}

namespace mainApp
{
	class ConfigSQLConnectInfo;
	typedef struct SQLConnectInfo SQLConnectInfo_s;
	typedef enum class SQLType SQLType_e;

	typedef enum class widgetType
	{
		WIDGET_TYPE_SEARCH = 0,
		WIDGET_TYPE_ADD    = 1,
		WIDGET_TYPE_DELETE = 2,
		WIDGET_TYPE_UPDATE = 3,
		WIDGET_TYPE_UNKNOW = 4,
	}widgetType_e;

	class MainAppWidget : public DSGUI::DSDialog
	{
		Q_OBJECT

	public:
		MainAppWidget(QWidget* pParent = nullptr);
		~MainAppWidget();

	private:
		void InitUI();
		void SetSelectWidgetType(widgetType_e nType);
		void ConnectSgn();
		void OpenSqlitDB();
		void ShowNotifyDlg(const QString& strNotify) const;
		bool StartSqlitDB();

	signals:
		void sgnShowNotifyDlg(QString& strNotify);

	private slots:
		void OnCurrentIndexChanged(int nIndex);
		void OnSearchBtnClicked(QString& strSearchWord);
		void OnConfigWidgetShow();
		void OnShowNotifyDlg(QString& strNotify);
		void OnConnectSQL(SQLConnectInfo_s& info);

	private:
		Ui::MainAppWidget*              m_pUi;
		ConfigSQLConnectInfo*           m_pConfigWidget;
		SqliteDB::CSqliteDB*            m_pSqliteDB; // local SQL
		SqliteDB::AbbreviationTable*    m_pAbbreviationTable;
		MysqlDB::CMysqlDB*              m_pMysqlDB;
		SQLType_e                       m_sqlType;
	};
}
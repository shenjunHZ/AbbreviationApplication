/*
@tool    use for select local or service function to save
@        the abbreviation.
@author  sj
@data    2017-9-6
@version 1.0
*/
#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QDialog>

#include "Dialog/Dialog.h"

namespace Ui
{
	class ConfigSQLConnectInfo;
}

namespace mainApp
{
	typedef enum class SQLType
	{
		SQL_TYPE_LOCAL   = 0,
		SQL_TYPE_SERVICE = 1,
	}SQLType_e;

	typedef struct SQLConnectInfo
	{
		QString strHostName;
		int     iPort;
		QString strUserName;
		QString strPassword;
	}SQLConnectInfo_s;

	class ConfigSQLConnectInfo : public QDialog/*public DSGUI::DSDialog*/
	{
		Q_OBJECT

	public:
		ConfigSQLConnectInfo(QWidget* pParent = nullptr);
		~ConfigSQLConnectInfo();

		// get current SQL type
		SQLType_e GetSQLType();

	signals:
		void sgnConnectSQL(SQLConnectInfo_s& info);

	private:
		void InitUI();
		void ConnectSgn();
		void SetConfigEnable(bool bEnable);

	private slots:
		void OnLocalSQLToggled(bool bChecked);
		void OnServiceSQLToggled(bool bChecked);
		void OnClickCancel();
		void OnClickSave();

	private:
		Ui::ConfigSQLConnectInfo* m_pUi;
	};
}
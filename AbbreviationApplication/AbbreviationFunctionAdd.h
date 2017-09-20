/*
@tool    Abbreviation add Function interface
@author  sj
@data    2017-9-8
@version 1.0
*/
#pragma once

#include <QtWidgets/QWidget>

namespace Ui
{
	class AbbreviationFunctionAdd;
}
namespace SqliteDB
{
	class AbbreviationTable;
	typedef struct AbbreviationInfo AbbreviationInfo_s;
}
namespace MysqlDB
{
	class CMysqlDB;
}

namespace mainApp
{
	typedef enum class SQLType SQLType_e;

	class AbbreviationFunctionAdd : public QWidget
	{
		Q_OBJECT

	public:
		AbbreviationFunctionAdd(QWidget* pParent = nullptr);
		~AbbreviationFunctionAdd();
		// search from sql
		void SetAbbreviationTable(SqliteDB::AbbreviationTable* pAbbreviationTable, MysqlDB::CMysqlDB* pMysqlDB);

		void SetSQLType(const SQLType_e& type);

	private:
		void ConnectSgn();
		// search from sql
		bool AddDefinitionFromSQL(const SqliteDB::AbbreviationInfo_s& sInfo);

	private slots:
		void OnSaveClicked();
		void OnCancelClicked();

	private:
		Ui::AbbreviationFunctionAdd*    m_pUi;
		SqliteDB::AbbreviationTable*    m_pAbbreviationTable;
		MysqlDB::CMysqlDB*              m_pMysqlDB;
		SQLType_e                       m_sqlType;
	};
}
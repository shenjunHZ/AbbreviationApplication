/*
@tool    Abbreviation Search Function interface
@author  sj
@data    2017-9-8
@version 1.0
*/
#pragma once

#include <QWidget>
#include "ui_AbbreviationFunctionSearch.h"

namespace Ui
{
	class AbbreviationFunctionSearch;
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

	class AbbreviationFunctionSearch : public QWidget
	{
		Q_OBJECT

	public:
		AbbreviationFunctionSearch(QWidget *parent = Q_NULLPTR);
		~AbbreviationFunctionSearch();

		// set search word text
		bool SetAcronymText(const QString& strText);
		// db table
		void SetAbbreviationTable(SqliteDB::AbbreviationTable* pAbbreviationTable, MysqlDB::CMysqlDB* pMysqlDB);

		void SetSQLType(const SQLType_e& type);

	private:
		void InitUI();
		void ConnectSgn();
		// add definition list info
		bool AddDefinition(const std::vector<SqliteDB::AbbreviationInfo_s>& vecDefinition);
		// search from sql
		bool SearchDefinitionFromSQL(const QString& strText);
		// clear definition list info
		bool ClearDefinition();
		// delete definition by Primary Key
		bool AbbreviationFunctionSearch::DeleteDefinition(uint64_t iPrimaryKey, QListWidgetItem* pItem);

	private slots:
		void OnDeleteDefinition(uint64_t iPrimaryKey, QListWidgetItem* pItem);

	private:
		Ui::AbbreviationFunctionSearch* m_pUi;
		SqliteDB::AbbreviationTable*    m_pAbbreviationTable;
		MysqlDB::CMysqlDB*              m_pMysqlDB;
		std::vector<SqliteDB::AbbreviationInfo_s> m_vecDefinitionInfos;
		SQLType_e                       m_sqlType;
	};

} // end namesapce mainApp
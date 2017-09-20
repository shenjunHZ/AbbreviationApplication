/*
Qt提供的对不同数据库的驱动支持：

Driver Type Description：
QDB2        IBM DB2
QIBASE      Borland InterBase Driver
QMYSQL      MySQL Driver
QOCI        Oracle Call Interface Driver
QODBC       ODBC Driver (includes Microsoft SQL Server)
QPSQL       PostgreSQL Driver
QSQLITE     SQLite version 3 or above
QSQLITE2    SQLite version 2
QTDS        Sybase Adaptive Server

*/
#pragma once

#include <vector>
#include <QtSql/QSqlDatabase>
#include <map>

namespace MysqlDB
{
	class CMysqlDB
	{
	public:
		CMysqlDB();
		~CMysqlDB();

		bool connectToSql(const QString& strHostName, const int& iPort, const QString& strUserName, const QString& strPassword);
		std::map<int, std::string> outputWithPreparedQuery(const QString &name);
		bool addQuery(const QString &name, const QString & expression);
		bool deleteQuery(const int id);

	private:
		QSqlDatabase m_Database;
	};
}

#include "SqliteDB.h"
#include "SqlCommExec.h"

#include "libdsl/DPrintLog.h"
#include "sqlitedsl/sqlite3.h"

namespace SqliteDB
{
	CSqliteDB::CSqliteDB(void)
		: m_pSqlite(nullptr)
	{
		m_pSqlCommExec = new CSqlCommExec(this);
	}

	CSqliteDB::~CSqliteDB(void)
	{
		Close();
		SAFE_DELETE(m_pSqlCommExec);
	}

	bool CSqliteDB::OpenDB(const std::string& strDBPath)
	{
		Close();

		bool bFlag = false;
		if ( sqlite3_open(strDBPath.c_str(), &m_pSqlite) != SQLITE_OK )
		{
			DLOG_ERR("Open DB = %s is failed", strDBPath.c_str());
			m_pSqlite = nullptr;
		}
		else
		{
			bFlag = true;
		}

		return bFlag;
	}

	void CSqliteDB::Close()
	{
		if ( nullptr != m_pSqlite )
		{
			sqlite3_close(m_pSqlite);
			m_pSqlite = NULL;
		}
	}

	bool CSqliteDB::ExecCmdText(const std::string& strCmdText)
	{
		return m_pSqlCommExec->ExecCmdText(strCmdText);
	}

	CSqlDataReader CSqliteDB::ExecQueryCmdText(const std::string& strCmdText)
	{
		return m_pSqlCommExec->ExecQueryCmdText(strCmdText);
	}

	CSqlDataWriter CSqliteDB::ExecAddCmdText(const std::string& strCmdText)
	{
		return m_pSqlCommExec->ExecAddCmdText(strCmdText);
	}

	bool CSqliteDB::BeginTransaction()
	{
		return m_pSqlCommExec->ExecCmdText("BEGIN TRANSACTION;");
	}

	bool CSqliteDB::CommitTransaction()
	{
		return m_pSqlCommExec->ExecCmdText("COMMIT TRANSACTION;");
	}

	bool CSqliteDB::RollbackTransaction()
	{
		return m_pSqlCommExec->ExecCmdText("ROLLBACK  TRANSACTION;");
	}
}
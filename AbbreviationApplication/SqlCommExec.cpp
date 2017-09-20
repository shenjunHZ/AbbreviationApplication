#include "SqlCommExec.h"
#include "SqliteDB.h"
#include "sqlitedsl/sqlite3.h"
#include "libdsl/DPrintLog.h"

#include <assert.h>

namespace SqliteDB
{
	CSqlCommExec::CSqlCommExec(CSqliteDB* pSqliteDB)
		: m_pSqliteDB(pSqliteDB)
	{
		assert(pSqliteDB);
	}

	CSqlCommExec::~CSqlCommExec(void)
	{
		m_pSqliteDB = nullptr;
	}

	bool CSqlCommExec::ExecCmdText(const std::string& strCmdText)
	{
		bool bFlag = false;
		char* pErrMsg = nullptr;

		if ( nullptr != m_pSqliteDB->m_pSqlite )
		{
			if ( sqlite3_exec(m_pSqliteDB->m_pSqlite, strCmdText.c_str(), 0, 0, &pErrMsg) == SQLITE_OK )
			{
				bFlag = true;
			}
			else
			{
				DLOG_ERR("Exec sql cmd = %s failed, error msg = %s", strCmdText.c_str(), pErrMsg);
			}
		}

		if ( nullptr != pErrMsg )
		{
			sqlite3_free(pErrMsg);
		}

		return bFlag;
	}

	CSqlDataReader CSqlCommExec::ExecQueryCmdText(const std::string& strCmdText)
	{
		sqlite3_stmt* pStmt = nullptr;
		int iRec = -1; // 临时变量，查看sql转换结果，方便调试
		if ( nullptr != m_pSqliteDB->m_pSqlite )
		{
			if ( iRec = sqlite3_prepare_v2(m_pSqliteDB->m_pSqlite, strCmdText.c_str(), -1, &pStmt, NULL) != SQLITE_OK )
			{
				if ( nullptr != pStmt )
				{
					sqlite3_finalize(pStmt);
					pStmt = nullptr;
				}
				DLOG_ERR("Exec query sql cmd = %s failed", strCmdText.c_str());
			}
		}

		return CSqlDataReader(pStmt);
	}

	//执行sql批量插入的命令，具体的插入动作在CSqlDataWriter中去执行
	CSqlDataWriter CSqlCommExec::ExecAddCmdText(const std::string& strCmdText)
	{
		sqlite3_stmt* pStmt = nullptr;
		if ( nullptr != m_pSqliteDB->m_pSqlite )
		{
			if ( sqlite3_prepare_v2(m_pSqliteDB->m_pSqlite, strCmdText.c_str(), -1, &pStmt, NULL) != SQLITE_OK )
			{
				//FIXME 如果查询失败，pStmt是否会申请内存信息，需不需要人为释放？
				if ( nullptr != pStmt )
				{
					sqlite3_finalize(pStmt);
					pStmt = nullptr;
				}
				DLOG_ERR("Exec sql cmd = %s failed", strCmdText.c_str());
			}
		}

		return CSqlDataWriter(pStmt);
	}
}
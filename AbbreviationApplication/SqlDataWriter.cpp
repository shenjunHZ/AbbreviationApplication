#include "SqlDataWriter.h"
#include "sqlitedsl/sqlite3.h"

namespace SqliteDB
{
	CSqlDataWriter::CSqlDataWriter(sqlite3_stmt *pStmt)
		: m_pStmt(pStmt)
	{
	}

	CSqlDataWriter::~CSqlDataWriter(void)
	{
		Close();
	}

	//对象有效状态 true：有效,数据可取	false：无效，失败
	bool CSqlDataWriter::ObjectValidState()
	{
		bool bFlag = false;

		if ( nullptr != m_pStmt )
		{
			bFlag = true;
		}

		return bFlag;
	}

	bool CSqlDataWriter::BindIntValue(int iCol, int iValue)
	{
		bool bFlag = false;
		if ( nullptr != m_pStmt )
		{
			if ( sqlite3_bind_int(m_pStmt, iCol, iValue) == SQLITE_OK )
			{
				bFlag = true;
			}
		}

		return bFlag;
	}

	bool CSqlDataWriter::BindStringValue(int iCol, const std::string& strValue)
	{
		bool bFlag = false;
		if ( nullptr != m_pStmt )
		{
			if ( sqlite3_bind_text(m_pStmt, iCol, strValue.c_str(), -1, SQLITE_TRANSIENT) == SQLITE_OK )
			{
				bFlag = true;
			}
		}

		return bFlag;
	}

	bool CSqlDataWriter::BindUInt64Value(int iCol, uint64_t uValue)
	{
		bool bFlag = false;
		if ( nullptr != m_pStmt )
		{
			if ( sqlite3_bind_int64(m_pStmt, iCol, uValue) == SQLITE_OK )
			{
				bFlag = true;
			}
		}

		return bFlag;
	}

	bool CSqlDataWriter::WriteOneRecord()
	{
		bool bFlag = false;
		if ( nullptr != m_pStmt )
		{
			sqlite3_step(m_pStmt);   
			if ( (sqlite3_reset(m_pStmt) == SQLITE_OK) )
			{
				bFlag = true;
			}
		}

		return bFlag;
	}

	void CSqlDataWriter::Close()
	{
		if ( nullptr != m_pStmt )
		{
			sqlite3_finalize(m_pStmt);
			m_pStmt = nullptr;
		}
	}
}
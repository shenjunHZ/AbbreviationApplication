#include "SqlDataReader.h"
#include "sqlitedsl/sqlite3.h"

namespace SqliteDB
{
	CSqlDataReader::CSqlDataReader(sqlite3_stmt *pStmt)
		: m_pStmt(pStmt)
	{

	}

	CSqlDataReader::~CSqlDataReader(void)
	{
		Close();
	}

	// 对象有效状态 true：有效,数据可取	false：无效，失败
	bool CSqlDataReader::ObjectValidState()
	{
		bool bFlag = false;

		if ( nullptr != m_pStmt )
		{
			bFlag = true;
		}

		return bFlag;
	}

	bool CSqlDataReader::ReadOneRecord()
	{
		bool bFlag = false;

		if ( nullptr != m_pStmt )
		{
			if ( sqlite3_step(m_pStmt) == SQLITE_ROW )
			{
				bFlag = true;
			}
		}

		return bFlag;
	}

	// 关闭读取	读取结束后调用
	void CSqlDataReader::Close()
	{
		if ( nullptr != m_pStmt )
		{
			sqlite3_finalize(m_pStmt);
			m_pStmt = nullptr;
		}
	}

	// 获取某列的值<字符串>
	std::string CSqlDataReader::GetStringValue(int iCol)
	{
		std::string strResult;
		const unsigned char* pResult = sqlite3_column_text(m_pStmt, iCol);
		if ( NULL != pResult )
		{
			strResult = (char*)pResult;
		}

		return strResult;
	}

	// 获取某列的值<整形>
	int CSqlDataReader::GetIntValue(int iCol)
	{
		return sqlite3_column_int(m_pStmt, iCol);
	}

	// 获取某列的值<无符号整形>
	uint64_t CSqlDataReader::GetUInt64Value(int iCol)
	{
		return (uint64_t)sqlite3_column_int64(m_pStmt, iCol);
	}
}
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

	// ������Ч״̬ true����Ч,���ݿ�ȡ	false����Ч��ʧ��
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

	// �رն�ȡ	��ȡ���������
	void CSqlDataReader::Close()
	{
		if ( nullptr != m_pStmt )
		{
			sqlite3_finalize(m_pStmt);
			m_pStmt = nullptr;
		}
	}

	// ��ȡĳ�е�ֵ<�ַ���>
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

	// ��ȡĳ�е�ֵ<����>
	int CSqlDataReader::GetIntValue(int iCol)
	{
		return sqlite3_column_int(m_pStmt, iCol);
	}

	// ��ȡĳ�е�ֵ<�޷�������>
	uint64_t CSqlDataReader::GetUInt64Value(int iCol)
	{
		return (uint64_t)sqlite3_column_int64(m_pStmt, iCol);
	}
}
#include "TableBase.h"
#include "SqliteDB.h"
#include "libdsl/DStr.h"

#include <assert.h>

namespace SqliteDB
{
	CTableBase::CTableBase(const std::string& strTableName, CSqliteDB* pSqliteDB)
		: m_strTableName(strTableName),
		  m_pSqliteDB(pSqliteDB)
	{
		assert(m_pSqliteDB);
	}

	CTableBase::~CTableBase(void)
	{
		m_pSqliteDB = nullptr;
	}

	bool CTableBase::IsTableExist()
	{
		char szInfo[256] = {0};
		dsl::DStr::sprintf_x(szInfo, sizeof(szInfo), "SELECT COUNT(*) FROM sqlite_master WHERE type = \"table\" and name=\"%s\";",
			m_strTableName.c_str());

		CSqlDataReader sqlDataReader = m_pSqliteDB->ExecQueryCmdText(szInfo);
		bool bFlag = false;
		if ( sqlDataReader.ObjectValidState() )
		{
			if ( sqlDataReader.ReadOneRecord() )
			{
				if ( sqlDataReader.GetIntValue(0) > 0 ) // count
				{
					bFlag = true;
				}
			}
			sqlDataReader.Close();
		}

		return bFlag;
	}

	bool CTableBase::ClearTableData()
	{
		char szDelSql[256] = {0};
		dsl::DStr::sprintf_x(szDelSql, sizeof(szDelSql),
			"DELETE FROM %s;", m_strTableName.c_str());

		return m_pSqliteDB->ExecCmdText(szDelSql);
	}
}
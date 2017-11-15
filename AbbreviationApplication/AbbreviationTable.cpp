#include "AbbreviationTable.h"
#include "libdsl/DStr.h"
#include "SqliteDB.h"
#include "SqlDataReader.h"
#include "SqlDataWriter.h"

#include <vector>
#include <string>

namespace SqliteDB
{
	AbbreviationTable::AbbreviationTable(const std::string& strTableName, CSqliteDB* pSqliteDB)
		: CTableBase(strTableName, pSqliteDB)
	{

	}

	AbbreviationTable::~AbbreviationTable()
	{

	}

	bool AbbreviationTable::CreateTable()
	{
		/******************************************************************************************
		创建表		表字段大小是根据server db来定义
		ID						bigint,						自动编号
		ACRONYM 				varchar(64),				缩写KEY
		DEFINITION				varchar(512),				定义说明
		******************************************************************************************/

		bool bFlag = false;
		if (CTableBase::IsTableExist())
		{
			bFlag = true;
		}
		else
		{
			char szCreateTbSql[1024] = { 0 };
			dsl::DStr::sprintf_x(szCreateTbSql, sizeof(szCreateTbSql),
				"CREATE TABLE %s(ID bigint NOT NULL PRIMARY KEY,\
				ACRONYM varchar(64) NOT NULL,\
				DEFINITION varchar(512) NOT NULL);", m_strTableName.c_str());
			bFlag = m_pSqliteDB->ExecCmdText(szCreateTbSql);
		}

		return bFlag;  
		// 主键：表中经常有一个列或多列的组合，其值能唯一地标识表中的每一行(不能重复)。
		// 主键 AUTOINCREMENT 自动编号
	}

	CSqlDataWriter AbbreviationTable::CreateSqlDataWriter()
	{
		char szAddSql[1024] = { 0 };
		dsl::DStr::sprintf_x(szAddSql, sizeof(szAddSql),
			"INSERT INTO %s(ID, ACRONYM, DEFINITION)VALUES\
			(?, ?, ?)", m_strTableName.c_str());

		return m_pSqliteDB->ExecAddCmdText(szAddSql);
	}

	int AbbreviationTable::QueryDataCount(const std::string& strAcronym)
	{
		int nRecordCount = 0;
		char szSelectSql[1024] = { 0 };

		dsl::DStr::sprintf_x(szSelectSql, sizeof(szSelectSql),
			"SELECT COUNT(*) as NUM FROM %s %s;", m_strTableName.c_str(), strAcronym.c_str());

		CSqlDataReader sqlDataReader = m_pSqliteDB->ExecQueryCmdText(szSelectSql);
		if (sqlDataReader.ObjectValidState() && sqlDataReader.ReadOneRecord())
		{
			nRecordCount = sqlDataReader.GetIntValue(0);
		}

		return nRecordCount;
	}

	int AbbreviationTable::QueryDataCount()
	{
		int nRecordCount = 0;
		char szSelectSql[1024] = { 0 };

		dsl::DStr::sprintf_x(szSelectSql, sizeof(szSelectSql),
			"SELECT COUNT(*) FROM %s;", m_strTableName.c_str());

		CSqlDataReader sqlDataReader = m_pSqliteDB->ExecQueryCmdText(szSelectSql);
		if (sqlDataReader.ObjectValidState() && sqlDataReader.ReadOneRecord())
		{
			nRecordCount = sqlDataReader.GetIntValue(0);
		}

		return nRecordCount;
	}

	uint64_t AbbreviationTable::GetMaxPrimaryKey()
	{
		uint64_t nMaxPrimaryKey = 0;
		char szSelectSql[1024] = { 0 };

		dsl::DStr::sprintf_x(szSelectSql, sizeof(szSelectSql),
			"SELECT * FROM %s ORDER BY ID DESC LIMIT 1;", m_strTableName.c_str());

		CSqlDataReader sqlDataReader = m_pSqliteDB->ExecQueryCmdText(szSelectSql);
		if (sqlDataReader.ObjectValidState() && sqlDataReader.ReadOneRecord())
		{
			nMaxPrimaryKey = sqlDataReader.GetUInt64Value(0);
		}

		return nMaxPrimaryKey;
	}

	/******************************insert interface*******************************************************/

	bool AbbreviationTable::InsertOneRecord(CSqlDataWriter* pSqlDataWriter, uint64_t nIndex, const AbbreviationInfo_s* pInfo)
	{
		bool bRet = false;
		if (nullptr == pSqlDataWriter || nullptr == pInfo)
		{
			return bRet;
		}
		int iCol = 1; // fix why 1?
		//pSqlDataWriter->BindIntValue(iCol++, nIndex);
		pSqlDataWriter->BindUInt64Value(iCol++, nIndex);
		pSqlDataWriter->BindStringValue(iCol++, pInfo->strAcronym);
		pSqlDataWriter->BindStringValue(iCol++, pInfo->strDefinition);
		return pSqlDataWriter->WriteOneRecord();
	}

	bool AbbreviationTable::FlushTable(const AbbreviationInfo_s& sInfo)
	{
		if(nullptr == m_pSqliteDB || !m_pSqliteDB->BeginTransaction())
		{
			return false;
		}

		uint64_t nMaxCount = GetMaxPrimaryKey();
	
		CSqlDataWriter sqlDataWrite = CreateSqlDataWriter();

		if (!InsertOneRecord(&sqlDataWrite, nMaxCount + 1, &sInfo))
		{
			// 失败，回滚
			m_pSqliteDB->RollbackTransaction();

			return false;
		}

		m_pSqliteDB->CommitTransaction();
		return true;
	}
	/**********************************delete interface******************************************************/
	bool AbbreviationTable::DeleteDefinition(uint64_t iPrimaryKey)
	{
		char szSelectSql[1024] = { 0 };

		dsl::DStr::sprintf_x(szSelectSql, sizeof(szSelectSql),
			"DELETE FROM %s WHERE ID = %lu;", m_strTableName.c_str(), iPrimaryKey);

		return m_pSqliteDB->ExecCmdText(szSelectSql);
	}

	/***************************query interface********************************************************/

	bool AbbreviationTable::QueryDefinition(std::string strAcronym, std::vector<AbbreviationInfo_s>& vecDefinitionInfos)
	{
		char szSelectSql[1024] = { 0 };

		dsl::DStr::sprintf_x(szSelectSql, sizeof(szSelectSql),
			"SELECT * FROM %s WHERE ACRONYM = '%s' COLLATE NOCASE;",
			m_strTableName.c_str(), strAcronym.c_str());

		//Common::DSMutexLock mutexGuard(m_mtxData);
		//iRecordCount = QueryDataCount(strHandleInfo);
		return QueryData(szSelectSql, vecDefinitionInfos);
	}

	bool AbbreviationTable::QueryData(const std::string& strSelectInfo, std::vector<AbbreviationInfo_s>& vecDefinitionInfos)
	{
		bool bFlag = false;
		vecDefinitionInfos.clear();

		CSqlDataReader sqlDataReader = m_pSqliteDB->ExecQueryCmdText(strSelectInfo);
		if (sqlDataReader.ObjectValidState())
		{
			bFlag = true;
			while (true)
			{
				AbbreviationInfo_s abbreInfo;
				if (GetOneRecord(&sqlDataReader, abbreInfo))
				{
					vecDefinitionInfos.push_back(abbreInfo);
				}
				else
				{
					break;
				}
			}
		}

		return bFlag;
	}

	bool AbbreviationTable::GetOneRecord(CSqlDataReader* pSqlDataReader, AbbreviationInfo_s& abbreInfo)
	{
		bool bFlag = false;

		if (nullptr != pSqlDataReader && pSqlDataReader->ReadOneRecord())
		{
			bFlag = true;
			int iCol = 0;
			abbreInfo.iPrimaryKey = pSqlDataReader->GetUInt64Value(iCol++);
			abbreInfo.strAcronym = pSqlDataReader->GetStringValue(iCol++);
			abbreInfo.strDefinition = pSqlDataReader->GetStringValue(iCol++);
		}

		return bFlag;
	}

}

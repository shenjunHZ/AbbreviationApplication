/**
 @tool: sqlit sqlִ�з�װ
 @author  sj
 @data    2017-9-3
 @��ǰ�汾��1.0
 */

#pragma once

#include "SqlDataReader.h"
#include "SqlDataWriter.h"

namespace SqliteDB
{
	class CSqliteDB;
	class CSqlCommExec
	{
	public:
		CSqlCommExec(CSqliteDB* pSqliteDB);
		~CSqlCommExec(void);

	public:
		//ִ��sql�ǲ�ѯ�������
		bool ExecCmdText(const std::string& strCmdText);
		//ִ��sql��ѯ��������ѯ�����CSqlDataReader��ȥȡ
		CSqlDataReader ExecQueryCmdText(const std::string& strCmdText);
		//ִ��sql����������������Ĳ��붯����CSqlDataWriter��ȥִ��
		CSqlDataWriter ExecAddCmdText(const std::string& strCmdText);

	private:
		CSqliteDB*		m_pSqliteDB;
	};

} // end namespace mainApp

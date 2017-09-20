/**
 @tool: sqlit sql执行封装
 @author  sj
 @data    2017-9-3
 @当前版本：1.0
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
		//执行sql非查询类的命令
		bool ExecCmdText(const std::string& strCmdText);
		//执行sql查询类的命令，查询结果从CSqlDataReader中去取
		CSqlDataReader ExecQueryCmdText(const std::string& strCmdText);
		//执行sql批量插入的命令，具体的插入动作在CSqlDataWriter中去执行
		CSqlDataWriter ExecAddCmdText(const std::string& strCmdText);

	private:
		CSqliteDB*		m_pSqliteDB;
	};

} // end namespace mainApp

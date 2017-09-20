/**
 *
 * file：SqliteDB.h
 * tool：sqlite Sql operate
 *
 * 当前版本：1.0
 */

#pragma once

#include "SqlDataReader.h"
#include "SqlDataWriter.h"

struct sqlite3;

namespace SqliteDB
{
	class CSqlCommExec;
	class CSqliteDB
	{
	public:
		friend class CSqlCommExec;

		CSqliteDB(void);
		~CSqliteDB(void);

	public:
		//打开数据库，如果已打开数据库，会自动先关闭
		bool OpenDB(const std::string& strDBPath);

		//关闭数据库
		void Close();

		// 执行sql非查询类的命令
		bool ExecCmdText(const std::string& strCmdText);

		// 执行sql查询类的命令，查询结果从CSqlDataReader中去取
		CSqlDataReader ExecQueryCmdText(const std::string& strCmdText);

		// 执行sql批量插入的命令，具体的插入动作在CSqlDataWriter中去执行
		CSqlDataWriter ExecAddCmdText(const std::string& strCmdText);

	public:
		//开启事务
		bool BeginTransaction();
		//提交事务
		bool CommitTransaction();
		//回滚事务
		bool RollbackTransaction();

	private:
		sqlite3*		m_pSqlite;
		CSqlCommExec*	m_pSqlCommExec;
	};

} // end namespace SqliteDB

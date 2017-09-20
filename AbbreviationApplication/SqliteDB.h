/**
 *
 * file��SqliteDB.h
 * tool��sqlite Sql operate
 *
 * ��ǰ�汾��1.0
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
		//�����ݿ⣬����Ѵ����ݿ⣬���Զ��ȹر�
		bool OpenDB(const std::string& strDBPath);

		//�ر����ݿ�
		void Close();

		// ִ��sql�ǲ�ѯ�������
		bool ExecCmdText(const std::string& strCmdText);

		// ִ��sql��ѯ��������ѯ�����CSqlDataReader��ȥȡ
		CSqlDataReader ExecQueryCmdText(const std::string& strCmdText);

		// ִ��sql����������������Ĳ��붯����CSqlDataWriter��ȥִ��
		CSqlDataWriter ExecAddCmdText(const std::string& strCmdText);

	public:
		//��������
		bool BeginTransaction();
		//�ύ����
		bool CommitTransaction();
		//�ع�����
		bool RollbackTransaction();

	private:
		sqlite3*		m_pSqlite;
		CSqlCommExec*	m_pSqlCommExec;
	};

} // end namespace SqliteDB

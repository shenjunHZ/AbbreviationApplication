/**
 * Copyright (c)
 * All rights reserved.
 *
 * author:  sj
 * tool: ��ṹ����
 * version��1.0
 * data: 2017-9-7
 */

#pragma once

#include "SqlDataWriter.h"

namespace SqliteDB
{
	class CSqliteDB;
	class CTableBase
	{
	public:
		CTableBase(const std::string& strTableName, CSqliteDB* pSqliteDB);
		virtual ~CTableBase(void);

	public:
		// ������
		virtual bool CreateTable() = 0;

	protected:
		// �жϱ��Ƿ����
		bool IsTableExist();
		// ��ձ�����
		bool ClearTableData();
	protected:
		CSqliteDB*	m_pSqliteDB;
		std::string m_strTableName;
	};

} // end namespace SqliteDB

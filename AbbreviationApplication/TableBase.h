/**
 * Copyright (c)
 * All rights reserved.
 *
 * author:  sj
 * tool: 表结构基类
 * version：1.0
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
		// 创建表
		virtual bool CreateTable() = 0;

	protected:
		// 判断表是否存在
		bool IsTableExist();
		// 清空表数据
		bool ClearTableData();
	protected:
		CSqliteDB*	m_pSqliteDB;
		std::string m_strTableName;
	};

} // end namespace SqliteDB

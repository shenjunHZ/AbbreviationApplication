/**
@tool: 写数据封装
@author  sj
@data    2017-9-3
@当前版本：1.0
 */

#pragma once

#include "libdsl/dslbase.h"
#include <string>

struct sqlite3_stmt;

namespace SqliteDB
{
	class CSqlDataWriter
	{
	public:
		CSqlDataWriter(sqlite3_stmt *pStmt);
		~CSqlDataWriter(void);

	public:
		//对象有效状态 true：有效,数据可取	false：无效，失败
		bool ObjectValidState();

		/********************begin***************************************/
		/*
		1、先绑定对应列的数据
		2、执行WriteOneRecord
		3、批量插入循环1,2
		*/
		bool BindIntValue(int iCol, int iValue);
		bool BindStringValue(int iCol, const std::string& strValue);
		bool BindUInt64Value(int iCol, uint64_t uValue);
		bool WriteOneRecord();
		/*********************end****************************************/

		//关闭写入	所有数据写入结束后调用
		void Close();
	private:
		sqlite3_stmt*		m_pStmt;
	};

} // end namespace SqliteDB

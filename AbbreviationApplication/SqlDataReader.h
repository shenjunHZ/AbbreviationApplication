/**
 @tool: 读取数据封装
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
	class CSqlDataReader
	{
	public:
		CSqlDataReader(sqlite3_stmt *pStmt);
		~CSqlDataReader(void);

	public:
		//对象有效状态 true：有效,数据可取	false：无效，失败
		bool ObjectValidState();

		/*	读取一条记录，如果要读取所有的数据，需反复调用，直到return false为止
		接口调用的前提是ObjectValidState返回true
		*/
		bool ReadOneRecord();

		//关闭读取	读取结束后调用
		void Close();

		/*******************BEGIN*******************/
		//以下接口应该在ReadOneRecord调用成功后调用

		//获取某列的值<字符串>
		std::string GetStringValue(int iCol);

		//获取某列的值<整形>
		int GetIntValue(int iCol);

		//获取某列的值<无符号整形>
		uint64_t GetUInt64Value(int iCol);
		/*********************END*******************/

	private:
		sqlite3_stmt*		m_pStmt;
	};

} // end namespace SqliteDB

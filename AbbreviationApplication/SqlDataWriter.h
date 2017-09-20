/**
@tool: д���ݷ�װ
@author  sj
@data    2017-9-3
@��ǰ�汾��1.0
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
		//������Ч״̬ true����Ч,���ݿ�ȡ	false����Ч��ʧ��
		bool ObjectValidState();

		/********************begin***************************************/
		/*
		1���Ȱ󶨶�Ӧ�е�����
		2��ִ��WriteOneRecord
		3����������ѭ��1,2
		*/
		bool BindIntValue(int iCol, int iValue);
		bool BindStringValue(int iCol, const std::string& strValue);
		bool BindUInt64Value(int iCol, uint64_t uValue);
		bool WriteOneRecord();
		/*********************end****************************************/

		//�ر�д��	��������д����������
		void Close();
	private:
		sqlite3_stmt*		m_pStmt;
	};

} // end namespace SqliteDB

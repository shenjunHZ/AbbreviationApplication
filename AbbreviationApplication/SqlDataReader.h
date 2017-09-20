/**
 @tool: ��ȡ���ݷ�װ
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
	class CSqlDataReader
	{
	public:
		CSqlDataReader(sqlite3_stmt *pStmt);
		~CSqlDataReader(void);

	public:
		//������Ч״̬ true����Ч,���ݿ�ȡ	false����Ч��ʧ��
		bool ObjectValidState();

		/*	��ȡһ����¼�����Ҫ��ȡ���е����ݣ��跴�����ã�ֱ��return falseΪֹ
		�ӿڵ��õ�ǰ����ObjectValidState����true
		*/
		bool ReadOneRecord();

		//�رն�ȡ	��ȡ���������
		void Close();

		/*******************BEGIN*******************/
		//���½ӿ�Ӧ����ReadOneRecord���óɹ������

		//��ȡĳ�е�ֵ<�ַ���>
		std::string GetStringValue(int iCol);

		//��ȡĳ�е�ֵ<����>
		int GetIntValue(int iCol);

		//��ȡĳ�е�ֵ<�޷�������>
		uint64_t GetUInt64Value(int iCol);
		/*********************END*******************/

	private:
		sqlite3_stmt*		m_pStmt;
	};

} // end namespace SqliteDB

/*
@tool    sqlite table interface
@author  sj
@data    2017-9-8
@version 1.0
*/
#pragma once

#include <vector>

#include "TableBase.h"

namespace SqliteDB
{
    class CSqliteDB;
    class CSqlDataReader;
    class CSqlDataWriter;

    typedef struct AbbreviationInfo
    {
        uint64_t    iPrimaryKey;
        std::string strAcronym;
        std::string strDefinition;

        AbbreviationInfo()
        {
            iPrimaryKey = 0;
            strAcronym = "";
            strDefinition = "";
        }
    }AbbreviationInfo_s;

    class AbbreviationTable : public CTableBase
    {
    public:
        AbbreviationTable(const std::string& strTableName, CSqliteDB* pSqliteDB);
        ~AbbreviationTable();

        // ������
        bool CreateTable();
        // д���ݣ�to do �����ݶ�Ļ��������������һ���Բ���
        bool FlushTable(const AbbreviationInfo_s& sInfo);
        // ����������ѯ����
        bool QueryDefinition(std::string strAcronym, std::vector<AbbreviationInfo_s>& vecDefinitionInfos);
        // ��������ɾ������
        bool DeleteDefinition(uint64_t iPrimaryKey);
        // ��������
        bool updateDefinition(uint64_t iPrimaryKey, std::string strDefinition);

    private:
        // ��д����
        CSqlDataWriter CreateSqlDataWriter();
        // ��������
        bool InsertOneRecord(CSqlDataWriter* pSqlDataWriter, uint64_t nIndex, const AbbreviationInfo_s* pInfo);
        // ��ѯ
        bool QueryData(const std::string& strSelectInfo, std::vector<AbbreviationInfo_s>& vecDefinitionInfos);
        // ��ȡһ������
        bool GetOneRecord(CSqlDataReader* pSqlDataReader, AbbreviationInfo_s& strInfo);
        // ��������
        int AbbreviationTable::QueryDataCount(const std::string& strAcronym);
        // �ܹ�����
        int AbbreviationTable::QueryDataCount();
        // ��ȡ�������ֵ
        uint64_t GetMaxPrimaryKey();
    };
}
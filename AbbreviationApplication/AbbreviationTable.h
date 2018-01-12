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

        // 创建表
        bool CreateTable();
        // 写数据，to do 若数据多的话后面改用容器，一次性操作
        bool FlushTable(const AbbreviationInfo_s& sInfo);
        // 根据条件查询数据
        bool QueryDefinition(std::string strAcronym, std::vector<AbbreviationInfo_s>& vecDefinitionInfos);
        // 根据主键删除数据
        bool DeleteDefinition(uint64_t iPrimaryKey);
        // 更新数据
        bool updateDefinition(uint64_t iPrimaryKey, std::string strDefinition);

    private:
        // 建写数据
        CSqlDataWriter CreateSqlDataWriter();
        // 插入数据
        bool InsertOneRecord(CSqlDataWriter* pSqlDataWriter, uint64_t nIndex, const AbbreviationInfo_s* pInfo);
        // 查询
        bool QueryData(const std::string& strSelectInfo, std::vector<AbbreviationInfo_s>& vecDefinitionInfos);
        // 获取一条数据
        bool GetOneRecord(CSqlDataReader* pSqlDataReader, AbbreviationInfo_s& strInfo);
        // 存在条数
        int AbbreviationTable::QueryDataCount(const std::string& strAcronym);
        // 总共条数
        int AbbreviationTable::QueryDataCount();
        // 获取最大主键值
        uint64_t GetMaxPrimaryKey();
    };
}
#include "AbbreviationFunctionAdd.h"
#include "commonControl.h"
#include "ui_AbbreviationFunctionAdd.h"
#include "AbbreviationTable.h"
#include "ConfigSQLConnectInfo.h"
#include "MysqlDB.h"

#include <iostream>

namespace mainApp
{

    AbbreviationFunctionAdd::AbbreviationFunctionAdd(QWidget* pParent /*= nullptr*/)
        : QWidget(pParent),
        m_pUi(nullptr),
        m_pAbbreviationTable(nullptr),
        m_pMysqlDB(nullptr),
        m_sqlType(SQLType::SQL_TYPE_LOCAL)
    {
        m_pUi = new Ui::AbbreviationFunctionAdd();
        m_pUi->setupUi(this);

        ConnectSgn();
        SET_MODULE_STYLE_BY_PATH("AbbreviationFunctionAdd");
    }

    AbbreviationFunctionAdd::~AbbreviationFunctionAdd()
    {
        m_pAbbreviationTable = nullptr; // ÉÏ²ãÊÍ·Å
        m_pMysqlDB = nullptr;
    }

    void AbbreviationFunctionAdd::SetAbbreviationTable(SqliteDB::AbbreviationTable* pAbbreviationTable, MysqlDB::CMysqlDB* pMysqlDB)
    {
        m_pAbbreviationTable = pAbbreviationTable;
        m_pMysqlDB = pMysqlDB;
    }

    void AbbreviationFunctionAdd::SetSQLType(const SQLType_e& type)
    {
        m_sqlType = type;
    }

    void AbbreviationFunctionAdd::ConnectSgn()
    {
        connect(m_pUi->m_btnSave,   SIGNAL(clicked()), this, SLOT(OnSaveClicked()));
        connect(m_pUi->m_btnCancel, SIGNAL(clicked()), this, SLOT(OnCancelClicked()));
    }

    bool AbbreviationFunctionAdd::AddDefinitionFromSQL(const SqliteDB::AbbreviationInfo_s& sInfo)
    {
        if (SQLType::SQL_TYPE_LOCAL == m_sqlType)
        {
            if (nullptr == m_pAbbreviationTable)
            {
                return false;
            }

            // to do sql
            return m_pAbbreviationTable->FlushTable(sInfo);
        }
        else if (SQLType::SQL_TYPE_SERVICE == m_sqlType)
        {
            return m_pMysqlDB->addQuery(QString::fromStdString(sInfo.strAcronym), QString::fromStdString(sInfo.strDefinition));
        }

        return false;
    }

    void AbbreviationFunctionAdd::OnSaveClicked()
    {
        QString strAcronym = m_pUi->m_pLineEditAcronym->text();
        QString strDefinition = m_pUi->m_pTextEditDefinition->toPlainText();

        SqliteDB::AbbreviationInfo_s sInfo;
        sInfo.strAcronym = strAcronym.toStdString();
        sInfo.strDefinition = strDefinition.toStdString();

        if (AddDefinitionFromSQL(sInfo))
        {
            m_pUi->m_pLineEditAcronym->clear();
            m_pUi->m_pTextEditDefinition->clear();
        }
    }

    void AbbreviationFunctionAdd::OnCancelClicked()
    {
        m_pUi->m_pLineEditAcronym->clear();
        m_pUi->m_pTextEditDefinition->clear();
    }

}
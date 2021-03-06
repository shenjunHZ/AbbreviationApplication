#include "AbbreviationFunctionSearch.h"
#include "ModifyDefinitionDialog.h"
#include "commonControl.h"
#include "AbbreviationTable.h"
#include "ConfigSQLConnectInfo.h"
#include "MysqlDB.h"

#include <map>
#include <QtGui/QDesktopServices>
#include <QtCore/QUrl>

const int g_iDefinitionOffset = 4;

namespace mainApp
{
    AbbreviationFunctionSearch::AbbreviationFunctionSearch(QWidget *parent)
        : QWidget(parent),
        m_pUi(nullptr),
        m_pAbbreviationTable(nullptr),
        m_pMysqlDB(nullptr),
        m_sqlType(SQLType::SQL_TYPE_LOCAL),
        m_pModifyDefinitionDialog(nullptr)
    {
        m_pUi = new Ui::AbbreviationFunctionSearch();
        m_pUi->setupUi(this);
        m_vecDefinitionInfos.clear();
        m_pModifyDefinitionDialog = new ModifyDefinitionDialog();

        ConnectSgn();
        SET_MODULE_STYLE_BY_PATH("AbbreviationFunctionSearch");
    }

    AbbreviationFunctionSearch::~AbbreviationFunctionSearch()
    {
        m_pAbbreviationTable = nullptr; // 上层释放
        m_pMysqlDB = nullptr;

        delete m_pModifyDefinitionDialog;
        m_pModifyDefinitionDialog = nullptr;
    }

    void AbbreviationFunctionSearch::InitUI()
    {

    }

    void AbbreviationFunctionSearch::ConnectSgn()
    {
        connect(m_pUi->m_listWidgetDefinition, SIGNAL(sgnDeleteDefinition(uint64_t, QListWidgetItem*)), this, SLOT(OnDeleteDefinition(uint64_t, QListWidgetItem*)));
        connect(m_pUi->m_listWidgetDefinition, SIGNAL(sgnEditDefinition(uint64_t, QListWidgetItem*)),   this, SLOT(OnEditDefinition(uint64_t, QListWidgetItem*)));
        // 某人给我提的是网址的话，可以双击打开
        connect(m_pUi->m_listWidgetDefinition, SIGNAL(itemDoubleClicked(QListWidgetItem*)),             this, SLOT(OnItemDoubleClicked(QListWidgetItem*)));
        connect(m_pModifyDefinitionDialog,     SIGNAL(sgnModifyDefinition(uint64_t, std::string)),      this, SLOT(onModifyDefinition(uint64_t, std::string)));
    }

    bool AbbreviationFunctionSearch::SetAcronymText(const QString& strText)
    {
        if ("" == strText)
        {
            return false;
        }

        m_pUi->m_labelEditACronym->setText(strText);
        ClearDefinition();
        SearchDefinitionFromSQL(strText);
        return true;
    }

    bool AbbreviationFunctionSearch::ClearDefinition()
    {
        int nCount = m_pUi->m_listWidgetDefinition->count();

        for (int nIndexCount = nCount; nIndexCount > 0; nIndexCount--)
        {
            QListWidgetItem* pItem = m_pUi->m_listWidgetDefinition->item(nIndexCount - 1);
            m_pUi->m_listWidgetDefinition->removeItemWidget(pItem);
            delete pItem;
            pItem = nullptr;
        }
        m_pUi->m_listWidgetDefinition->clear();

        return true;
    }

    bool AbbreviationFunctionSearch::AddDefinition(const std::vector<SqliteDB::AbbreviationInfo_s>& vecDefinition)
    {
        //QStringList strList;
        for (int iIndex = 0; iIndex < vecDefinition.size(); iIndex++)
        {
            //strList.push_back(QString::fromStdString(vecDefinition[iIndex].strDefinition));
            QString strDefinition = QString::fromStdString(vecDefinition[iIndex].strDefinition);
            if (!strDefinition.isEmpty())
            {
                QString strIndex = QString::number(iIndex + 1);
                QListWidgetItem *pItem = new QListWidgetItem(strIndex + ".  " + strDefinition);
                QFont font = pItem->font();
                font.setPixelSize(16);
                pItem->setFont(font);
                QStringList strList = strDefinition.split("\n");
                pItem->setTextAlignment(Qt::AlignTop | Qt::AlignLeft);
                //pItem->setToolTip(strDefinition);
                if (0 == iIndex % 2)
                {
                    //pItem->setBackgroundColor(QColor(201, 81, 0));
                    pItem->setBackgroundColor(QColor(58, 62, 67));
                }
                else
                {
                    pItem->setBackgroundColor(QColor(53, 57, 62));
                }
                pItem->setFlags(pItem->flags() & ~Qt::ItemIsSelectable);
                pItem->setData(Qt::UserRole, vecDefinition[iIndex].iPrimaryKey); // 存入主键值
                QSize size(100, 40 * strList.size());
                pItem->setSizeHint(size);
                m_pUi->m_listWidgetDefinition->addItem(pItem);
            }
        }

        return true;
    }

    void AbbreviationFunctionSearch::SetAbbreviationTable(SqliteDB::AbbreviationTable* pAbbreviationTable, MysqlDB::CMysqlDB* pMysqlDB)
    {
        m_pAbbreviationTable = pAbbreviationTable;
        m_pMysqlDB = pMysqlDB;
    }

    void AbbreviationFunctionSearch::SetSQLType(const SQLType_e& type)
    {
        m_sqlType = type;
    }

    bool AbbreviationFunctionSearch::SearchDefinitionFromSQL(const QString& strText)
    {
        // 用同步还是异步定时器，先看SQL封装后查询的效果
        if (SQLType::SQL_TYPE_LOCAL == m_sqlType)
        {
            if (nullptr == m_pAbbreviationTable)
            {
                return false;
            }

            m_vecDefinitionInfos.clear();
            m_pAbbreviationTable->QueryDefinition(strText.toStdString(), m_vecDefinitionInfos);

            return AddDefinition(m_vecDefinitionInfos);
        }
        else if (SQLType::SQL_TYPE_SERVICE == m_sqlType)
        {
            m_vecDefinitionInfos.clear();
            std::map<int, std::string> mapDefinition = m_pMysqlDB->outputWithPreparedQuery(strText);
            std::map<int, std::string>::iterator itMap = mapDefinition.begin();
            for (; itMap != mapDefinition.end(); itMap++)
            {
                SqliteDB::AbbreviationInfo_s info;
                info.iPrimaryKey = itMap->first;
                info.strDefinition = itMap->second;
                info.strAcronym = strText.toStdString();
                m_vecDefinitionInfos.push_back(info);
            }

            return AddDefinition(m_vecDefinitionInfos);
        }

        return false;
    }

    void AbbreviationFunctionSearch::OnDeleteDefinition(uint64_t iPrimaryKey, QListWidgetItem* pItem)
    {
        DeleteDefinition(iPrimaryKey, pItem);
    }

    void AbbreviationFunctionSearch::OnItemDoubleClicked(QListWidgetItem* pItem)
    {
        if (nullptr == pItem)
        {
            return;
        }

        QString strHttp = "";
        std::count_if(m_vecDefinitionInfos.begin(), m_vecDefinitionInfos.end(),
            [&strHttp, pItem] (SqliteDB::AbbreviationInfo_s info) 
        {
            if (pItem->data(Qt::UserRole).toInt() == info.iPrimaryKey)
            {
                QString strDefinition = QString::fromStdString(info.strDefinition);
                if (strDefinition.contains("http://"))
                {
                    int iIdex = strDefinition.indexOf("http://");
                    if (iIdex >= 0)
                    {
                        strHttp = strDefinition.mid(iIdex);
                        return true;
                    }
                }
                else if (strDefinition.contains("https://"))
                {
                    int iIdex = strDefinition.indexOf("https://");
                    if (iIdex >= 0)
                    {
                        strHttp = strDefinition.mid(iIdex);
                        return true;
                    }
                }
            }
            return false;
        });

        if (!strHttp.isEmpty())
        {
            QDesktopServices::openUrl(QUrl(strHttp));
        }
    }

    void AbbreviationFunctionSearch::OnEditDefinition(uint64_t iPrimaryKey, QListWidgetItem* pItem)
    {
        editDefinition(iPrimaryKey, pItem);
    }

    void AbbreviationFunctionSearch::onModifyDefinition(uint64_t iPrimaryKey, std::string strDefinition)
    {
        bool bRec = false;
        if (SQLType::SQL_TYPE_LOCAL == m_sqlType)
        {
            bRec = m_pAbbreviationTable->updateDefinition(iPrimaryKey, strDefinition);
        }
        else if (SQLType::SQL_TYPE_SERVICE == m_sqlType)
        {
            // to do
        }
        if (bRec)
        {
            QString strText = m_pUi->m_labelEditACronym->text();
            ClearDefinition();
            SearchDefinitionFromSQL(strText);
        }
    }

    bool AbbreviationFunctionSearch::DeleteDefinition(uint64_t iPrimaryKey, QListWidgetItem* pItem)
    {
        if (nullptr == m_pAbbreviationTable || nullptr == pItem)
        {
            return false;
        }

        bool bRec = false;
        if (SQLType::SQL_TYPE_LOCAL == m_sqlType)
        {
            bRec = m_pAbbreviationTable->DeleteDefinition(iPrimaryKey);
        }
        else if (SQLType::SQL_TYPE_SERVICE == m_sqlType)
        {
            bRec = m_pMysqlDB->deleteQuery(iPrimaryKey);
        }
        
        if (bRec)
        {
            m_pUi->m_listWidgetDefinition->removeItemWidget(pItem);
            delete pItem;
            pItem = nullptr;
            m_pUi->m_listWidgetDefinition->update();
        }

        return bRec;
    }


    bool AbbreviationFunctionSearch::editDefinition(uint64_t iPrimaryKey, QListWidgetItem* pItem)
    {
        if (nullptr == m_pModifyDefinitionDialog || nullptr == pItem)
        {
            return false;
        }

        QString strText = pItem->text();
        QString strDefinetion = strText.right(strText.length() - g_iDefinitionOffset);
        QRect rect = this->geometry();
        QPoint point = mapToGlobal(this->pos());
        m_pModifyDefinitionDialog->setGeometry((point.x() + (this->width() - m_pModifyDefinitionDialog->width()) / 2),
            (point.y() + (this->height() - m_pModifyDefinitionDialog->height()) / 2),
            m_pModifyDefinitionDialog->width(), m_pModifyDefinitionDialog->height());
        m_pModifyDefinitionDialog->showDialog(iPrimaryKey, strDefinetion.toStdString());

        return true;
    }

} // end namesapce mainApp


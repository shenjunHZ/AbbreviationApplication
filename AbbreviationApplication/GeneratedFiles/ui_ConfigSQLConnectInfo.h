/********************************************************************************
** Form generated from reading UI file 'ConfigSQLConnectInfo.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGSQLCONNECTINFO_H
#define UI_CONFIGSQLCONNECTINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "LineEdit/LineEdit.h"
#include "PushButton/PushButton.h"

QT_BEGIN_NAMESPACE

class Ui_ConfigSQLConnectInfo
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QRadioButton *m_pLocalSQL;
    QSpacerItem *horizontalSpacer;
    QRadioButton *m_pServerSQL;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QLabel *label;
    DSGUI::DSLineEdit *m_pLineEditIP;
    QLabel *label_4;
    DSGUI::DSLineEdit *m_pLineEditPort;
    QLabel *label_2;
    DSGUI::DSLineEdit *m_pLineEditUserName;
    QLabel *label_3;
    DSGUI::DSLineEdit *m_pLineEditPassword;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    DSGUI::DSPushButton *m_btnSave;
    QSpacerItem *horizontalSpacer_4;
    DSGUI::DSPushButton *m_btnCancel;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *ConfigSQLConnectInfo)
    {
        if (ConfigSQLConnectInfo->objectName().isEmpty())
            ConfigSQLConnectInfo->setObjectName(QStringLiteral("ConfigSQLConnectInfo"));
        ConfigSQLConnectInfo->resize(347, 329);
        verticalLayout = new QVBoxLayout(ConfigSQLConnectInfo);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        m_pLocalSQL = new QRadioButton(ConfigSQLConnectInfo);
        m_pLocalSQL->setObjectName(QStringLiteral("m_pLocalSQL"));

        horizontalLayout->addWidget(m_pLocalSQL);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        m_pServerSQL = new QRadioButton(ConfigSQLConnectInfo);
        m_pServerSQL->setObjectName(QStringLiteral("m_pServerSQL"));

        horizontalLayout->addWidget(m_pServerSQL);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(ConfigSQLConnectInfo);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        m_pLineEditIP = new DSGUI::DSLineEdit(ConfigSQLConnectInfo);
        m_pLineEditIP->setObjectName(QStringLiteral("m_pLineEditIP"));

        gridLayout->addWidget(m_pLineEditIP, 0, 1, 1, 1);

        label_4 = new QLabel(ConfigSQLConnectInfo);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        m_pLineEditPort = new DSGUI::DSLineEdit(ConfigSQLConnectInfo);
        m_pLineEditPort->setObjectName(QStringLiteral("m_pLineEditPort"));

        gridLayout->addWidget(m_pLineEditPort, 1, 1, 1, 1);

        label_2 = new QLabel(ConfigSQLConnectInfo);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        m_pLineEditUserName = new DSGUI::DSLineEdit(ConfigSQLConnectInfo);
        m_pLineEditUserName->setObjectName(QStringLiteral("m_pLineEditUserName"));

        gridLayout->addWidget(m_pLineEditUserName, 2, 1, 1, 1);

        label_3 = new QLabel(ConfigSQLConnectInfo);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        m_pLineEditPassword = new DSGUI::DSLineEdit(ConfigSQLConnectInfo);
        m_pLineEditPassword->setObjectName(QStringLiteral("m_pLineEditPassword"));

        gridLayout->addWidget(m_pLineEditPassword, 3, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer_3 = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        m_btnSave = new DSGUI::DSPushButton(ConfigSQLConnectInfo);
        m_btnSave->setObjectName(QStringLiteral("m_btnSave"));

        horizontalLayout_2->addWidget(m_btnSave);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        m_btnCancel = new DSGUI::DSPushButton(ConfigSQLConnectInfo);
        m_btnCancel->setObjectName(QStringLiteral("m_btnCancel"));

        horizontalLayout_2->addWidget(m_btnCancel);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 73, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(ConfigSQLConnectInfo);

        QMetaObject::connectSlotsByName(ConfigSQLConnectInfo);
    } // setupUi

    void retranslateUi(QWidget *ConfigSQLConnectInfo)
    {
        ConfigSQLConnectInfo->setWindowTitle(QApplication::translate("ConfigSQLConnectInfo", "Config", Q_NULLPTR));
        m_pLocalSQL->setText(QApplication::translate("ConfigSQLConnectInfo", "Local", Q_NULLPTR));
        m_pServerSQL->setText(QApplication::translate("ConfigSQLConnectInfo", "Service", Q_NULLPTR));
        label->setText(QApplication::translate("ConfigSQLConnectInfo", "IP:", Q_NULLPTR));
        label_4->setText(QApplication::translate("ConfigSQLConnectInfo", "Port:", Q_NULLPTR));
        m_pLineEditPort->setText(QString());
        label_2->setText(QApplication::translate("ConfigSQLConnectInfo", "UserName:", Q_NULLPTR));
        label_3->setText(QApplication::translate("ConfigSQLConnectInfo", "Password:", Q_NULLPTR));
        m_btnSave->setText(QApplication::translate("ConfigSQLConnectInfo", "Save", Q_NULLPTR));
        m_btnCancel->setText(QApplication::translate("ConfigSQLConnectInfo", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ConfigSQLConnectInfo: public Ui_ConfigSQLConnectInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGSQLCONNECTINFO_H

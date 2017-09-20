/********************************************************************************
** Form generated from reading UI file 'AbbreviationFunctionSearch.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABBREVIATIONFUNCTIONSEARCH_H
#define UI_ABBREVIATIONFUNCTIONSEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ListWidgetDefinition.h"

QT_BEGIN_NAMESPACE

class Ui_AbbreviationFunctionSearch
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *m_labelEditACronym;
    QSpacerItem *horizontalSpacer;
    mainApp::ListWidgetDefinition *m_listWidgetDefinition;

    void setupUi(QWidget *AbbreviationFunctionSearch)
    {
        if (AbbreviationFunctionSearch->objectName().isEmpty())
            AbbreviationFunctionSearch->setObjectName(QStringLiteral("AbbreviationFunctionSearch"));
        AbbreviationFunctionSearch->resize(505, 384);
        verticalLayout = new QVBoxLayout(AbbreviationFunctionSearch);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(AbbreviationFunctionSearch);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        m_labelEditACronym = new QLabel(AbbreviationFunctionSearch);
        m_labelEditACronym->setObjectName(QStringLiteral("m_labelEditACronym"));

        horizontalLayout->addWidget(m_labelEditACronym);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        m_listWidgetDefinition = new mainApp::ListWidgetDefinition(AbbreviationFunctionSearch);
        m_listWidgetDefinition->setObjectName(QStringLiteral("m_listWidgetDefinition"));

        verticalLayout->addWidget(m_listWidgetDefinition);


        retranslateUi(AbbreviationFunctionSearch);

        QMetaObject::connectSlotsByName(AbbreviationFunctionSearch);
    } // setupUi

    void retranslateUi(QWidget *AbbreviationFunctionSearch)
    {
        AbbreviationFunctionSearch->setWindowTitle(QApplication::translate("AbbreviationFunctionSearch", "AbbreviationFunctionSearch", Q_NULLPTR));
        label->setText(QApplication::translate("AbbreviationFunctionSearch", "Acronym:", Q_NULLPTR));
        m_labelEditACronym->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AbbreviationFunctionSearch: public Ui_AbbreviationFunctionSearch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABBREVIATIONFUNCTIONSEARCH_H

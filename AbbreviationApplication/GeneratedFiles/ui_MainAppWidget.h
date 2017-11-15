/********************************************************************************
** Form generated from reading UI file 'MainAppWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINAPPWIDGET_H
#define UI_MAINAPPWIDGET_H

#include <Abbreviationfunctionsearch.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "Abbreviationfunctionadd.h"
#include "SearchEdit/SearchEdit.h"
#include "ToolListView/ToolListView.h"

QT_BEGIN_NAMESPACE

class Ui_MainAppWidget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *m_btnIcon;
    DSGUI::DSToolListView *m_pToolListView;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    DSGUI::DSSearchEdit *m_pSearchWord;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *m_btnConfig;
    QStackedWidget *funcStackedWidget;
    mainApp::AbbreviationFunctionSearch *m_pSearchWidget;
    mainApp::AbbreviationFunctionAdd *m_pAddWidget;

    void setupUi(QWidget *MainAppWidget)
    {
        if (MainAppWidget->objectName().isEmpty())
            MainAppWidget->setObjectName(QStringLiteral("MainAppWidget"));
        MainAppWidget->resize(732, 467);
        horizontalLayout_2 = new QHBoxLayout(MainAppWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        m_btnIcon = new QPushButton(MainAppWidget);
        m_btnIcon->setObjectName(QStringLiteral("m_btnIcon"));
        m_btnIcon->setMinimumSize(QSize(160, 160));
        m_btnIcon->setMaximumSize(QSize(160, 160));

        verticalLayout->addWidget(m_btnIcon);

        m_pToolListView = new DSGUI::DSToolListView(MainAppWidget);
        m_pToolListView->setObjectName(QStringLiteral("m_pToolListView"));
        m_pToolListView->setMinimumSize(QSize(160, 0));
        m_pToolListView->setMaximumSize(QSize(160, 16777215));
        m_pToolListView->setFrameShape(QFrame::StyledPanel);
        m_pToolListView->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(m_pToolListView);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        m_pSearchWord = new DSGUI::DSSearchEdit(MainAppWidget);
        m_pSearchWord->setObjectName(QStringLiteral("m_pSearchWord"));
        m_pSearchWord->setMinimumSize(QSize(0, 32));
        m_pSearchWord->setMaximumSize(QSize(16777215, 32));

        horizontalLayout->addWidget(m_pSearchWord);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        m_btnConfig = new QPushButton(MainAppWidget);
        m_btnConfig->setObjectName(QStringLiteral("m_btnConfig"));
        m_btnConfig->setMinimumSize(QSize(20, 20));
        m_btnConfig->setMaximumSize(QSize(20, 20));

        horizontalLayout->addWidget(m_btnConfig);


        verticalLayout_2->addLayout(horizontalLayout);

        funcStackedWidget = new QStackedWidget(MainAppWidget);
        funcStackedWidget->setObjectName(QStringLiteral("funcStackedWidget"));
        m_pSearchWidget = new mainApp::AbbreviationFunctionSearch();
        m_pSearchWidget->setObjectName(QStringLiteral("m_pSearchWidget"));
        funcStackedWidget->addWidget(m_pSearchWidget);
        m_pAddWidget = new mainApp::AbbreviationFunctionAdd();
        m_pAddWidget->setObjectName(QStringLiteral("m_pAddWidget"));
        funcStackedWidget->addWidget(m_pAddWidget);

        verticalLayout_2->addWidget(funcStackedWidget);


        horizontalLayout_2->addLayout(verticalLayout_2);


        retranslateUi(MainAppWidget);

        funcStackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainAppWidget);
    } // setupUi

    void retranslateUi(QWidget *MainAppWidget)
    {
        MainAppWidget->setWindowTitle(QApplication::translate("MainAppWidget", "5G_U8", Q_NULLPTR));
        m_btnIcon->setText(QString());
        m_btnConfig->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainAppWidget: public Ui_MainAppWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINAPPWIDGET_H

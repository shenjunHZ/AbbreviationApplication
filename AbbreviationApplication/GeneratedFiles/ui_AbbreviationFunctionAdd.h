/********************************************************************************
** Form generated from reading UI file 'AbbreviationFunctionAdd.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABBREVIATIONFUNCTIONADD_H
#define UI_ABBREVIATIONFUNCTIONADD_H

#include <LineEdit/LineEdit.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "PushButton/PushButton.h"

QT_BEGIN_NAMESPACE

class Ui_AbbreviationFunctionAdd
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    DSGUI::DSLineEdit *m_pLineEditAcronym;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *m_pTextEditDefinition;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    DSGUI::DSPushButton *m_btnSave;
    QSpacerItem *horizontalSpacer_4;
    DSGUI::DSPushButton *m_btnCancel;

    void setupUi(QWidget *AbbreviationFunctionAdd)
    {
        if (AbbreviationFunctionAdd->objectName().isEmpty())
            AbbreviationFunctionAdd->setObjectName(QStringLiteral("AbbreviationFunctionAdd"));
        AbbreviationFunctionAdd->resize(653, 491);
        verticalLayout = new QVBoxLayout(AbbreviationFunctionAdd);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(AbbreviationFunctionAdd);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        horizontalLayout_3->addWidget(label);

        m_pLineEditAcronym = new DSGUI::DSLineEdit(AbbreviationFunctionAdd);
        m_pLineEditAcronym->setObjectName(QStringLiteral("m_pLineEditAcronym"));

        horizontalLayout_3->addWidget(m_pLineEditAcronym);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(AbbreviationFunctionAdd);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        m_pTextEditDefinition = new QTextEdit(AbbreviationFunctionAdd);
        m_pTextEditDefinition->setObjectName(QStringLiteral("m_pTextEditDefinition"));

        verticalLayout->addWidget(m_pTextEditDefinition);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        m_btnSave = new DSGUI::DSPushButton(AbbreviationFunctionAdd);
        m_btnSave->setObjectName(QStringLiteral("m_btnSave"));

        horizontalLayout->addWidget(m_btnSave);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        m_btnCancel = new DSGUI::DSPushButton(AbbreviationFunctionAdd);
        m_btnCancel->setObjectName(QStringLiteral("m_btnCancel"));

        horizontalLayout->addWidget(m_btnCancel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(AbbreviationFunctionAdd);

        QMetaObject::connectSlotsByName(AbbreviationFunctionAdd);
    } // setupUi

    void retranslateUi(QWidget *AbbreviationFunctionAdd)
    {
        AbbreviationFunctionAdd->setWindowTitle(QApplication::translate("AbbreviationFunctionAdd", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("AbbreviationFunctionAdd", "Acronym:", Q_NULLPTR));
        label_2->setText(QApplication::translate("AbbreviationFunctionAdd", "Definition:", Q_NULLPTR));
        m_btnSave->setText(QApplication::translate("AbbreviationFunctionAdd", "Save", Q_NULLPTR));
        m_btnCancel->setText(QApplication::translate("AbbreviationFunctionAdd", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AbbreviationFunctionAdd: public Ui_AbbreviationFunctionAdd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABBREVIATIONFUNCTIONADD_H

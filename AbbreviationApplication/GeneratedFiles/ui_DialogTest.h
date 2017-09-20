/********************************************************************************
** Form generated from reading UI file 'DialogTest.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGTEST_H
#define UI_DIALOGTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogTest
{
public:
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;

    void setupUi(QWidget *DialogTest)
    {
        if (DialogTest->objectName().isEmpty())
            DialogTest->setObjectName(QStringLiteral("DialogTest"));
        DialogTest->resize(609, 394);
        radioButton = new QRadioButton(DialogTest);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(60, 30, 95, 20));
        radioButton_2 = new QRadioButton(DialogTest);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(210, 30, 95, 20));

        retranslateUi(DialogTest);

        QMetaObject::connectSlotsByName(DialogTest);
    } // setupUi

    void retranslateUi(QWidget *DialogTest)
    {
        DialogTest->setWindowTitle(QApplication::translate("DialogTest", "DialogTest", Q_NULLPTR));
        radioButton->setText(QApplication::translate("DialogTest", "RadioButton", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("DialogTest", "RadioButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogTest: public Ui_DialogTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGTEST_H

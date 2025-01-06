/********************************************************************************
** Form generated from reading UI file 'settingbutton.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGBUTTON_H
#define UI_SETTINGBUTTON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingButton
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *SettingButton)
    {
        if (SettingButton->objectName().isEmpty())
            SettingButton->setObjectName(QString::fromUtf8("SettingButton"));
        SettingButton->resize(351, 508);
        pushButton = new QPushButton(SettingButton);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 110, 89, 25));
        pushButton_2 = new QPushButton(SettingButton);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(80, 180, 89, 25));
        pushButton_3 = new QPushButton(SettingButton);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(90, 270, 89, 25));

        retranslateUi(SettingButton);

        QMetaObject::connectSlotsByName(SettingButton);
    } // setupUi

    void retranslateUi(QWidget *SettingButton)
    {
        SettingButton->setWindowTitle(QApplication::translate("SettingButton", "Form", nullptr));
        pushButton->setText(QApplication::translate("SettingButton", "PushButton", nullptr));
        pushButton_2->setText(QApplication::translate("SettingButton", "PushButton", nullptr));
        pushButton_3->setText(QApplication::translate("SettingButton", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingButton: public Ui_SettingButton {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGBUTTON_H

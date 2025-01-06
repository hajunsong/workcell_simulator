/********************************************************************************
** Form generated from reading UI file 'settinglayout.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGLAYOUT_H
#define UI_SETTINGLAYOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <qclicklabel.h>

QT_BEGIN_NAMESPACE

class Ui_SettingLayout
{
public:
    QGridLayout *gridLayout;
    QClickLabel *label_5;
    QClickLabel *label_8;
    QClickLabel *label_4;
    QClickLabel *label_7;
    QClickLabel *label_2;
    QClickLabel *label_6;
    QClickLabel *label_3;
    QClickLabel *label_1;
    QClickLabel *label_9;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *SettingLayout)
    {
        if (SettingLayout->objectName().isEmpty())
            SettingLayout->setObjectName(QString::fromUtf8("SettingLayout"));
        SettingLayout->resize(865, 755);
        gridLayout = new QGridLayout(SettingLayout);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_5 = new QClickLabel(SettingLayout);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font;
        font.setPointSize(40);
        label_5->setFont(font);
        label_5->setFrameShape(QFrame::Box);
        label_5->setFrameShadow(QFrame::Sunken);
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 1, 1, 1, 1);

        label_8 = new QClickLabel(SettingLayout);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);
        label_8->setFrameShape(QFrame::Box);
        label_8->setFrameShadow(QFrame::Sunken);
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 2, 1, 1, 1);

        label_4 = new QClickLabel(SettingLayout);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);
        label_4->setFrameShape(QFrame::Box);
        label_4->setFrameShadow(QFrame::Sunken);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        label_7 = new QClickLabel(SettingLayout);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);
        label_7->setFrameShape(QFrame::Box);
        label_7->setFrameShadow(QFrame::Sunken);
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 2, 0, 1, 1);

        label_2 = new QClickLabel(SettingLayout);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setFrameShape(QFrame::Box);
        label_2->setFrameShadow(QFrame::Sunken);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_6 = new QClickLabel(SettingLayout);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);
        label_6->setFrameShape(QFrame::Box);
        label_6->setFrameShadow(QFrame::Sunken);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 1, 2, 1, 1);

        label_3 = new QClickLabel(SettingLayout);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);
        label_3->setFrameShape(QFrame::Box);
        label_3->setFrameShadow(QFrame::Sunken);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        label_1 = new QClickLabel(SettingLayout);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setFont(font);
        label_1->setFrameShape(QFrame::Box);
        label_1->setFrameShadow(QFrame::Sunken);
        label_1->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_1, 0, 0, 1, 1);

        label_9 = new QClickLabel(SettingLayout);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);
        label_9->setFrameShape(QFrame::Box);
        label_9->setFrameShadow(QFrame::Sunken);
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_9, 2, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 1);


        retranslateUi(SettingLayout);

        QMetaObject::connectSlotsByName(SettingLayout);
    } // setupUi

    void retranslateUi(QWidget *SettingLayout)
    {
        SettingLayout->setWindowTitle(QApplication::translate("SettingLayout", "Form", nullptr));
        label_5->setText(QApplication::translate("SettingLayout", "5", nullptr));
        label_8->setText(QApplication::translate("SettingLayout", "8", nullptr));
        label_4->setText(QApplication::translate("SettingLayout", "4", nullptr));
        label_7->setText(QApplication::translate("SettingLayout", "7", nullptr));
        label_2->setText(QApplication::translate("SettingLayout", "2", nullptr));
        label_6->setText(QApplication::translate("SettingLayout", "6", nullptr));
        label_3->setText(QApplication::translate("SettingLayout", "3", nullptr));
        label_1->setText(QApplication::translate("SettingLayout", "1", nullptr));
        label_9->setText(QApplication::translate("SettingLayout", "9", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingLayout: public Ui_SettingLayout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGLAYOUT_H

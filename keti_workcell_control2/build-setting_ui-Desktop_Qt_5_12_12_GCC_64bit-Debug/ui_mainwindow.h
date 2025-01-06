/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <qclicklabel.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *gbLayout;
    QGridLayout *gridLayout_2;
    QWidget *widget_layout;
    QGridLayout *gridLayout_4;
    QClickLabel *label_1;
    QClickLabel *label_2;
    QClickLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QClickLabel *label_4;
    QClickLabel *label_5;
    QClickLabel *label_6;
    QClickLabel *label_7;
    QClickLabel *label_8;
    QClickLabel *label_9;
    QSpacerItem *verticalSpacer;
    QGroupBox *gbAdjust;
    QGridLayout *gridLayout_3;
    QLineEdit *txtCellNum;
    QPushButton *btnCCW;
    QLabel *label_11;
    QLabel *label_10;
    QLabel *label;
    QPushButton *btnCW;
    QComboBox *cbCellType;
    QPushButton *btnSave;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1018, 776);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gbLayout = new QGroupBox(centralwidget);
        gbLayout->setObjectName(QString::fromUtf8("gbLayout"));
        gbLayout->setMinimumSize(QSize(0, 0));
        gbLayout->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_2 = new QGridLayout(gbLayout);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget_layout = new QWidget(gbLayout);
        widget_layout->setObjectName(QString::fromUtf8("widget_layout"));
        widget_layout->setMinimumSize(QSize(670, 670));
        widget_layout->setMaximumSize(QSize(670, 670));
        gridLayout_4 = new QGridLayout(widget_layout);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_1 = new QClickLabel(widget_layout);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        QFont font1;
        font1.setPointSize(40);
        font1.setBold(true);
        font1.setWeight(75);
        label_1->setFont(font1);
        label_1->setFrameShape(QFrame::Box);
        label_1->setFrameShadow(QFrame::Sunken);
        label_1->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_1, 0, 0, 1, 1);

        label_2 = new QClickLabel(widget_layout);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);
        label_2->setFrameShape(QFrame::Box);
        label_2->setFrameShadow(QFrame::Sunken);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_2, 0, 1, 1, 1);

        label_3 = new QClickLabel(widget_layout);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);
        label_3->setFrameShape(QFrame::Box);
        label_3->setFrameShadow(QFrame::Sunken);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_3, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 0, 3, 1, 1);

        label_4 = new QClickLabel(widget_layout);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);
        label_4->setFrameShape(QFrame::Box);
        label_4->setFrameShadow(QFrame::Sunken);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_4, 1, 0, 1, 1);

        label_5 = new QClickLabel(widget_layout);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);
        label_5->setFrameShape(QFrame::Box);
        label_5->setFrameShadow(QFrame::Sunken);
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_5, 1, 1, 1, 1);

        label_6 = new QClickLabel(widget_layout);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);
        label_6->setFrameShape(QFrame::Box);
        label_6->setFrameShadow(QFrame::Sunken);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_6, 1, 2, 1, 1);

        label_7 = new QClickLabel(widget_layout);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);
        label_7->setFrameShape(QFrame::Box);
        label_7->setFrameShadow(QFrame::Sunken);
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_7, 2, 0, 1, 1);

        label_8 = new QClickLabel(widget_layout);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font1);
        label_8->setFrameShape(QFrame::Box);
        label_8->setFrameShadow(QFrame::Sunken);
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_8, 2, 1, 1, 1);

        label_9 = new QClickLabel(widget_layout);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font1);
        label_9->setFrameShape(QFrame::Box);
        label_9->setFrameShadow(QFrame::Sunken);
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_9, 2, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_4->addItem(verticalSpacer, 3, 0, 1, 1);


        gridLayout_2->addWidget(widget_layout, 0, 0, 1, 1);


        gridLayout->addWidget(gbLayout, 0, 0, 2, 1);

        gbAdjust = new QGroupBox(centralwidget);
        gbAdjust->setObjectName(QString::fromUtf8("gbAdjust"));
        gbAdjust->setMinimumSize(QSize(300, 0));
        gbAdjust->setMaximumSize(QSize(300, 16777215));
        gridLayout_3 = new QGridLayout(gbAdjust);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        txtCellNum = new QLineEdit(gbAdjust);
        txtCellNum->setObjectName(QString::fromUtf8("txtCellNum"));

        gridLayout_3->addWidget(txtCellNum, 0, 1, 1, 2);

        btnCCW = new QPushButton(gbAdjust);
        btnCCW->setObjectName(QString::fromUtf8("btnCCW"));

        gridLayout_3->addWidget(btnCCW, 2, 1, 1, 1);

        label_11 = new QLabel(gbAdjust);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_3->addWidget(label_11, 2, 0, 1, 1);

        label_10 = new QLabel(gbAdjust);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_3->addWidget(label_10, 1, 0, 1, 1);

        label = new QLabel(gbAdjust);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        btnCW = new QPushButton(gbAdjust);
        btnCW->setObjectName(QString::fromUtf8("btnCW"));

        gridLayout_3->addWidget(btnCW, 2, 2, 1, 1);

        cbCellType = new QComboBox(gbAdjust);
        cbCellType->setObjectName(QString::fromUtf8("cbCellType"));

        gridLayout_3->addWidget(cbCellType, 1, 1, 1, 2);

        btnSave = new QPushButton(gbAdjust);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        gridLayout_3->addWidget(btnSave, 3, 0, 1, 3);


        gridLayout->addWidget(gbAdjust, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 543, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1018, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        gbLayout->setTitle(QApplication::translate("MainWindow", "Layout", nullptr));
        label_1->setText(QApplication::translate("MainWindow", "1", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "2", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "3", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "4", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "5", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "6", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "7", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "8", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "9", nullptr));
        gbAdjust->setTitle(QApplication::translate("MainWindow", "Adjust", nullptr));
        btnCCW->setText(QApplication::translate("MainWindow", "CCW", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "Cell Pose : ", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "Cell Type : ", nullptr));
        label->setText(QApplication::translate("MainWindow", "Cell Num : ", nullptr));
        btnCW->setText(QApplication::translate("MainWindow", "CW", nullptr));
        btnSave->setText(QApplication::translate("MainWindow", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

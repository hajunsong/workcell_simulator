#pragma once

#include <QMainWindow>
#include <QKeyEvent>
#include <QtDebug>

#include <ros/ros.h>

#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(ros::NodeHandle nh, QWidget *parent=nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ros::NodeHandle nh;

    void setting();
    void loading();

public slots:

    // key event
    void keyPressEvent(QKeyEvent *event);
};
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSlider>
#include <QLineEdit>
#include <QTimer>

#include <ros/ros.h>

#include <iostream>
#include <vector>

#include "robotcontrol.h"
#include "rvizclass.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(int argc, char** argv, QWidget *parent=nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    RobotControl *robotControl;
    RvizClass *rvizClass;

    std::vector<QSlider*> hs;
    std::vector<QLineEdit*> txt;

    QTimer *timer;

public slots:
    // button event
    void btnStartClicked();

    // slider event
    void valueChanged(int arg);
    
    // timer event
    void update();
};

#endif // MAINWINDOW_H
#pragma once

#include <QMainWindow>
#include <QKeyEvent>
#include <QCloseEvent>
#include <QTimer>

#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <tf/transform_broadcaster.h>

#include <iostream>

#include "robotcontrol.h"
#include "rvizclass.h"
#include "settingclass.h"

enum cellType{NONE=0, ROBOT, ARF, TOOL, VISION, AXIS2};

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

    RobotControl *robotControl;
    RvizClass *rvizClass;
	SettingClass *settingClass;

	tf::TransformBroadcaster *broadcaster;

	section cell[9];

    QTimer *timer;

    void setting();
    void loading();

public slots:
    // key event
    void keyPressEvent(QKeyEvent *event);

    // close event
    void closeEvent(QCloseEvent *event);

    // custom event
    void settingClose();

    // timer event
    void update();

    // button event
    void btnSettingClicked();
    void btnLoadingClicked();
};

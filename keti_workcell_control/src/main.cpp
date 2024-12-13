// #include "robot_control.h"
#include <QApplication>

#include "mainwindow.h"

int main(int argc, char** argv){
    // ros::init(argc, argv, "robot_control_node");
    // ros::NodeHandle nh;

    // RobotControl robotControl(nh);
    // robotControl.start();

    // ros::waitForShutdown();

    QApplication a(argc, argv);
    MainWindow w(argc, argv);
    w.show();

    return a.exec();
}
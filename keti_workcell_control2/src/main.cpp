#include <QApplication>
#include "mainwindow.h"
#include <signal.h>

void my_handler(sig_atomic_t s){
    // printf("Caught signal %d\n", s);
    exit(1);
}

int main(int argc, char** argv){
    signal(SIGINT, my_handler);
    ros::init(argc, argv, "robot_control_node2", ros::init_options::NoSigintHandler);
    ros::NodeHandle nh;

    QApplication a(argc, argv);
	MainWindow w(nh);
	// w.move(1920*2 + 1280, 100);
	w.show();

    return a.exec();
}

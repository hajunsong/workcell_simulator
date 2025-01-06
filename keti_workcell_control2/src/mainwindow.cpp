#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(ros::NodeHandle _nh, QWidget* parent) : nh(_nh), QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    settingClass = new SettingClass();

    connect(settingClass, SIGNAL(close()), this, SLOT(settingClose()));


}

MainWindow::~MainWindow(){
    delete ui;
    delete settingClass;
}

void MainWindow::setting(){
    settingClass->show();
}

void MainWindow::loading(){

}

void MainWindow::keyPressEvent(QKeyEvent *event){
    std::cout << (int)event->key() << std::endl;
    
    if(event->key() == Qt::Key_F5){
        setting();
    }
    else if(event->key() == Qt::Key_F6){
        loading();
    }
}

void MainWindow::closeEvent(QCloseEvent *event){
    std::cout << "main window close" << std::endl;

    nh.shutdown();
    ros::shutdown();

    delete ui;
    delete settingClass;

    event->accept();
}

void MainWindow::settingClose(){
    std::cout << "setting window close" << std::endl;

    loading();
}

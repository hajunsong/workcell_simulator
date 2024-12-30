#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(ros::NodeHandle _nh, QWidget* parent) : nh(_nh), QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::setting(){
    
}

void MainWindow::loading(){

}

void MainWindow::keyPressEvent(QKeyEvent *event){
    std::cout << (int)event->key() << std::endl;
    if(event->key() == Qt::Key_F5){
        
    }
    else if(event->key() == Qt::Key_F6){

    }
}
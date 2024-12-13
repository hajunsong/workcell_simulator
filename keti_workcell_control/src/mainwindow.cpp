#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(int argc, char** argv, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btnStart, SIGNAL(clicked()), this, SLOT(btnStartClicked()));

    ros::init(argc, argv, "robot_control_node");
    ros::NodeHandle nh;

    robotControl = new RobotControl(nh);

    rvizClass = new RvizClass();
    rvizClass->initRvizRobotModel(ui->vlRobotModel);

    txt.push_back(ui->txtm1q1);
    txt.push_back(ui->txtm1q2);
    txt.push_back(ui->txtm1q3);
    txt.push_back(ui->txtm1q4);
    txt.push_back(ui->txtm1q5);
    txt.push_back(ui->txtm1q6);

    txt.push_back(ui->txtm2s3);
    txt.push_back(ui->txtm2s4);
    txt.push_back(ui->txtm2s5);
    txt.push_back(ui->txtm2s6);
    txt.push_back(ui->txtm2s7);
    txt.push_back(ui->txtm2s8);

    txt.push_back(ui->txtm3s1);
    txt.push_back(ui->txtm3s2);
    txt.push_back(ui->txtm3d_q1);
    txt.push_back(ui->txtm3d_q2);
    txt.push_back(ui->txtm3d_q3);
    txt.push_back(ui->txtm3d_q4);

    hs.push_back(ui->hsm1q1);
    hs.push_back(ui->hsm1q2);
    hs.push_back(ui->hsm1q3);
    hs.push_back(ui->hsm1q4);
    hs.push_back(ui->hsm1q5);
    hs.push_back(ui->hsm1q6);

    hs.push_back(ui->hsm2s3);
    hs.push_back(ui->hsm2s4);
    hs.push_back(ui->hsm2s5);
    hs.push_back(ui->hsm2s6);
    hs.push_back(ui->hsm2s7);
    hs.push_back(ui->hsm2s8);

    hs.push_back(ui->hsm3s1);
    hs.push_back(ui->hsm3s2);
    hs.push_back(ui->hsm3d_q1);
    hs.push_back(ui->hsm3d_q2);
    hs.push_back(ui->hsm3d_q3);
    hs.push_back(ui->hsm3d_q4);

    for(int i = 0; i < txt.size(); i++){
        hs[i]->setValue(0);
        txt[i]->setText(QString::number(hs[i]->value()));
        connect(hs[i], SIGNAL(valueChanged(int)), this, SLOT(valueChanged(int)));
    }

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->setInterval(10);
    timer->start();
}

MainWindow::~MainWindow(){
    delete robotControl;
}

void MainWindow::btnStartClicked(){
    robotControl->start();
}

void MainWindow::valueChanged(int arg){
    QString name = sender()->objectName();
    for(int i = 0; i < hs.size(); i++){
        if(name.compare(hs[i]->objectName()) == 0){
            txt[i]->setText(QString::number(hs[i]->value()));
        }
    }
}

void MainWindow::update(){
    for(int i = 0; i < txt.size(); i++){
        txt[i]->setText(QString::number(hs[i]->value()));
    }
    std::vector<double> temp;
    for(int i = 0; i < 6; i++){
        temp.push_back(hs[i]->value());
    }
    robotControl->setValue1(temp);
    temp.clear();

    for(int i = 0; i < 6; i++){
        temp.push_back(hs[i + 6]->value());
    }
    robotControl->setValue2(temp);
    temp.clear();

    for(int i = 0; i < 6; i++){
        temp.push_back(hs[i + 12]->value());
    }
    robotControl->setValue3(temp);
    temp.clear();
}
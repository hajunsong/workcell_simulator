#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(int _argc, char** _argv, std::string _name, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	argc = _argc;
	argv = _argv;
	name = _name;

//	ros::init(argc, argv, name);

	robotControl = new RobotControl();

	rvizClass = new RvizClass(ui->vlRobotModel);

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

	ui->hsm1q1->setRange(-3140, 3140);
	ui->hsm1q2->setRange(-3140, 3140);
	ui->hsm1q3->setRange(-3140, 3140);
	ui->hsm1q4->setRange(-3140, 3140);
	ui->hsm1q5->setRange(-3140, 3140);
	ui->hsm1q6->setRange(-3140, 3140);

	ui->hsm2s3->setRange(45, 445);
	ui->hsm2s4->setRange(55, 355);
	ui->hsm2s5->setRange(0, 40);
	ui->hsm2s6->setRange(0, 40);
	ui->hsm2s7->setRange(0, 40);
	ui->hsm2s8->setRange(0, 40);

	ui->hsm3s1->setRange(50, 450);
	ui->hsm3s2->setRange(50, 450);
	ui->hsm3d_q1->setRange(-3140, 3140);
	ui->hsm3d_q2->setRange(-3140, 3140);
	ui->hsm3d_q3->setRange(-206, 0);
	ui->hsm3d_q4->setRange(-3140, 3140);

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
	timer->setInterval(100);

	connect(ui->btnShutdown, SIGNAL(clicked()), this, SLOT(btnShutdownClicked()));
	connect(ui->btnResume, SIGNAL(clicked()), this, SLOT(btnResumeClicked()));

	connect(ui->btnM1On, SIGNAL(clicked()), this, SLOT(btnM1OnClicked()));
	connect(ui->btnM1Off, SIGNAL(clicked()), this, SLOT(btnM1OffClicked()));

	init();
}

MainWindow::~MainWindow(){
    delete robotControl;
	delete rvizClass;
}

void MainWindow::init(){
	ros::init(argc, argv, name);
	ros::NodeHandle nh(name);
	ros::start();
	if(ros::isStarted()){
		robotControl->init(nh);
		rvizClass->initRvizRobotModel();
		timer->start();
	}
}

void MainWindow::stop(){
	timer->stop();
	rvizClass->stop();
	robotControl->stop();
	ros::shutdown();
	ros::waitForShutdown();
	ROS_INFO("ros shutdown complete");
}

void MainWindow::btnShutdownClicked(){
	stop();
}

void MainWindow::btnResumeClicked(){
	init();
}

void MainWindow::btnM1OnClicked(){
	rvizClass->enableModule1();

	stop();

	init();
}

void MainWindow::btnM1OffClicked(){
	rvizClass->disableModule1();

	stop();

	init();
}


void MainWindow::valueChanged(int arg){
//    QString name = sender()->objectName();
//    for(int i = 0; i < hs.size(); i++){
//        if(name.compare(hs[i]->objectName()) == 0){
//			txt[i]->setText(QString::number(static_cast<double>(hs[i]->value())*0.001));
//        }
//    }
}

void MainWindow::update(){
//    for(int i = 0; i < txt.size(); i++){
//		txt[i]->setText(QString::number(static_cast<double>(hs[i]->value())*0.001));
//    }
    std::vector<double> temp;
    for(int i = 0; i < 6; i++){
		temp.push_back(static_cast<double>(hs[i]->value())*0.001);
    }
	robotControl->setValue1(temp);
	robotControl->getJointUR(temp);
	for(int i = 0; i < 6; i++){
		txt[i]->setText(QString::number(temp[i]));
	}
	char msg_char[255];
	sprintf(msg_char, "[INFO] [%d.%d] [UR] joint position : %.3f, %.3f, %.3f, %.3f, %.3f, %.3f", ros::Time::now().sec, ros::Time::now().nsec, temp[0], temp[1], temp[2], temp[3], temp[4], temp[5]);
	ui->txtMessage->append(msg_char);
	temp.clear();

    for(int i = 0; i < 6; i++){
		temp.push_back(static_cast<double>(hs[i + 6]->value())*0.001);
    }
	robotControl->setValue2(temp);
	robotControl->getJointARF(temp);
	for(int i = 0; i < 6; i++){
		txt[i + 6]->setText(QString::number(temp[i]));
	}
	sprintf(msg_char, "[INFO] [%d.%d] [ARF] joint position : %.3f, %.3f, %.3f, %.3f, %.3f, %.3f", ros::Time::now().sec, ros::Time::now().nsec, temp[0], temp[1], temp[2], temp[3], temp[4], temp[5]);
	ui->txtMessage->append(msg_char);
	temp.clear();

    for(int i = 0; i < 6; i++){
		temp.push_back(static_cast<double>(hs[i + 12]->value())*0.001);
    }
	robotControl->setValue3(temp);
	robotControl->getJointDENSO(temp);
	for(int i = 0; i < 6; i++){
		txt[i + 12]->setText(QString::number(temp[i]));
	}
	sprintf(msg_char, "[INFO] [%d.%d] [DENSO] joint position : %.3f, %.3f, %.3f, %.3f, %.3f, %.3f", ros::Time::now().sec, ros::Time::now().nsec, temp[0], temp[1], temp[2], temp[3], temp[4], temp[5]);
	ui->txtMessage->append(msg_char);
	temp.clear();

	ros::spinOnce();
}

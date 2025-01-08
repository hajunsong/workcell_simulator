#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(ros::NodeHandle _nh, QWidget* parent) : nh(_nh), QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

	settingClass = new SettingClass();

	connect(settingClass, SIGNAL(windowClose()), this, SLOT(settingClose()));

	connect(ui->btnSetting, SIGNAL(clicked()), this, SLOT(btnSettingClicked()));
	connect(ui->btnLoading, SIGNAL(clicked()), this, SLOT(btnLoadingClicked()));

	robotControl = new RobotControl();
	robotControl->init(nh);

	rvizClass = new RvizClass(ui->vlRobotModel);
	rvizClass->initRvizRobotModel();

	broadcaster = new tf::TransformBroadcaster();

	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(update()));
	timer->setInterval(100);

	robotControl->start();
	timer->start();

	settingClose();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::setting(){
	settingClass->show();
}

void MainWindow::loading(){
	for(int i = 0; i < 9; i++){
		double qw, qx, qy, qz;
		double px, py, pz;
		double ang = cell[i].angle*M_PI/180.0;
		double m00 = cos(ang);
		double m01 = -sin(ang);
		double m10 = sin(ang);
		double m11 = cos(ang);
		double m22 = 1;
		double  tr = m00 + m11 + m22;
		if (tr > 0) { 
			double  S = sqrt(tr+1.0) * 2; // S=4*qw 
			qw = 0.25 * S;
			qx = (0 - 0) / S;
			qy = (0 - 0) / S; 
			qz = (m10 - m01) / S; 
		} 
		else if ((m00 > m11)&(m00 > m22)) { 
			double  S = sqrt(1.0 + m00 - m11 - m22) * 2; // S=4*qx 
			qw = (0 - 0) / S;
			qx = 0.25 * S;
			qy = (m01 + m10) / S; 
			qz = (0 + 0) / S; 
		} 
		else if (m11 > m22) { 
			double  S = sqrt(1.0 + m11 - m00 - m22) * 2; // S=4*qy
			qw = (0 - 0) / S;
			qx = (m01 + m10) / S; 
			qy = 0.25 * S;
			qz = (0 + 0) / S; 
		} 
		else { 
			double  S = sqrt(1.0 + m22 - m00 - m11) * 2; // S=4*qz
			qw = (m10 - m01) / S;
			qx = (0 + 0) / S;
			qy = (0 + 0) / S;
			qz = 0.25 * S;
		}

		px = 0.8 - (0.8*(i/3));
		py = 0.8 - (0.8*(i%3));
		pz = 0;

		// ROS_INFO("sec : %d", i);
		// ROS_INFO("ang : %f", ang);
		// ROS_INFO("ori : %f, %f, %f, %f", qx, qy, qz, qw);
		// ROS_INFO("pos : %f, %f, %f\n", px, py, pz);

		switch(cell[i].id){
			case ROBOT:
			{
				broadcaster->sendTransform(
					tf::StampedTransform(
						tf::Transform(tf::Quaternion(qx, qy, qz, qw), tf::Vector3(px, py, pz)),
						ros::Time::now(),"world", "base_UR"));
				break;
			}
			case ARF:
			{
				broadcaster->sendTransform(
					tf::StampedTransform(
						tf::Transform(tf::Quaternion(qx, qy, qz, qw), tf::Vector3(px, py, pz)),
						ros::Time::now(),"world", "base_ARF"));
				break;
			}
			case TOOL:
			{
				broadcaster->sendTransform(
					tf::StampedTransform(
						tf::Transform(tf::Quaternion(qx, qy, qz, qw), tf::Vector3(px, py, pz)),
						ros::Time::now(),"world", "base_ETC"));
				break;
			}
			case VISION:
			{
				broadcaster->sendTransform(
					tf::StampedTransform(
						tf::Transform(tf::Quaternion(qx, qy, qz, qw), tf::Vector3(px, py, pz)),
						ros::Time::now(),"world", "base_VISION"));
				break;
			}
			case AXIS2:
			{
				broadcaster->sendTransform(
					tf::StampedTransform(
						tf::Transform(tf::Quaternion(qx, qy, qz, qw), tf::Vector3(px, py, pz)),
						ros::Time::now(),"world", "base_DENSO"));
				break;
			}
			default:
			{
				break;
			}
		}
	}
}

void MainWindow::keyPressEvent(QKeyEvent *event){
	std::cout << event->key() << std::endl;
    
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

void MainWindow::btnSettingClicked(){
	setting();
}

void MainWindow::btnLoadingClicked(){
	loading();
}

void MainWindow::settingClose(){
	std::cout << "setting window close" << std::endl;

	settingClass->getLayoutInfor(cell);

	loading();
}

void MainWindow::update(){
	std::vector<double> temp;
    for(int i = 0; i < 6; i++){
		// temp.push_back(static_cast<double>(hs[i]->value())*0.001);
		temp.push_back(0);
    }
	robotControl->setValue1(temp);
	robotControl->getJointUR(temp);
	// for(int i = 0; i < 6; i++){
	// 	txt[i]->setText(QString::number(temp[i]));
	// }
	char msg_char[255];
	sprintf(msg_char, "[INFO] [%d.%d] [UR] joint position : %.3f, %.3f, %.3f, %.3f, %.3f, %.3f",
			ros::Time::now().sec, ros::Time::now().nsec, temp[0], temp[1], temp[2], temp[3], temp[4], temp[5]);
	// ui->txtMessage->append(msg_char);
	temp.clear();

    for(int i = 0; i < 6; i++){
		// temp.push_back(static_cast<double>(hs[i + 6]->value())*0.001);
		temp.push_back(0);
    }
	robotControl->setValue2(temp);
	robotControl->getJointARF(temp);
	// for(int i = 0; i < 6; i++){
	// 	txt[i + 6]->setText(QString::number(temp[i]));
	// }
	sprintf(msg_char, "[INFO] [%d.%d] [ARF] joint position : %.3f, %.3f, %.3f, %.3f, %.3f, %.3f",
			ros::Time::now().sec, ros::Time::now().nsec, temp[0], temp[1], temp[2], temp[3], temp[4], temp[5]);
	// ui->txtMessage->append(msg_char);
	temp.clear();

    for(int i = 0; i < 6; i++){
		// temp.push_back(static_cast<double>(hs[i + 12]->value())*0.001);
		temp.push_back(0);
    }
	robotControl->setValue3(temp);
	robotControl->getJointDENSO(temp);
	// for(int i = 0; i < 6; i++){
	// 	txt[i + 12]->setText(QString::number(temp[i]));
	// }
	sprintf(msg_char, "[INFO] [%d.%d] [DENSO] joint position : %.3f, %.3f, %.3f, %.3f, %.3f, %.3f",
			ros::Time::now().sec, ros::Time::now().nsec, temp[0], temp[1], temp[2], temp[3], temp[4], temp[5]);
	// ui->txtMessage->append(msg_char);
	temp.clear();

	ros::spinOnce();
}

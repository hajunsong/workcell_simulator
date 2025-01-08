#include "settingclass.h"
#include "ui_settingclass.h"

SettingClass::SettingClass(QWidget *parent) : QWidget(parent), ui(new Ui::SettingClass)
{
	ui->setupUi(this);

	QPixmap bkgnd(":/images/back.png");
	bkgnd = bkgnd.scaled(ui->widget_layout->size(), Qt::IgnoreAspectRatio);
	QPalette palette;
	palette.setBrush(QPalette::Window, QBrush(bkgnd));
	ui->widget_layout->setAutoFillBackground(true);
	ui->widget_layout->setPalette(palette);

	label.push_back(ui->label_1);
	label.push_back(ui->label_2);
	label.push_back(ui->label_3);
	label.push_back(ui->label_4);
	label.push_back(ui->label_5);
	label.push_back(ui->label_6);
	label.push_back(ui->label_7);
	label.push_back(ui->label_8);
	label.push_back(ui->label_9);

	for(uint i = 0; i < 9; i++){
		connect(label[i], SIGNAL(mousePressed()), this, SLOT(labelClicked()));
	}
	for(uint i = 0; i < 9; i++){
		label[i]->setStyleSheet("QLabel { background-color : transparent; color : black; border : 2px solid white}");

		label[i]->setFixedSize(206, 206);
	}

	selectedCell = 0;

//	connect(ui->cbCellType, SIGNAL(currentIndexChanged(int)), this, SLOT(currentIndexChanged(int)));
	connect(ui->cbCellType, SIGNAL(activated(int)), this, SLOT(typeActivated(int)));
	cellName.push_back("");
	cellName.push_back("ROBOT");
	cellName.push_back("ARF");
	cellName.push_back("TOOL");
	cellName.push_back("VISION");
	cellName.push_back("AXIS2");
	fileName = cellName;

	ui->cbCellType->addItems(cellName);

	connect(ui->cbCellPose, SIGNAL(activated(int)), this, SLOT(poseActivated(int)));

	// connect(ui->btnCCW, SIGNAL(clicked()), this, SLOT(btnCCWClicked()));
	// connect(ui->btnCW, SIGNAL(clicked()), this, SLOT(btnCWClicked()));
	connect(ui->btnSave, SIGNAL(clicked()), this, SLOT(btnSaveClicked()));


	for(int i = 0; i < 9; i++){
//		std::cout << "type : " << cell[i].type << std::endl;
//		std::cout << "id : " << cell[i].id << std::endl;
//		std::cout << "angle : " << cell[i].angle << std::endl;
		memset(cell[i].type, 0, 16);
		cell[i].id = 0;
		cell[i].angle = 0;
	}
	update();
}

SettingClass::~SettingClass()
{
	delete ui;
}


void SettingClass::closeEvent(QCloseEvent *event){
	std::cout << "setting window close" << std::endl;
	emit windowClose();
	event->accept();
}

void SettingClass::labelClicked(){
//	qDebug() << sender()->objectName();
//	qDebug() << sender()->objectName().split("_")[1].toUInt();

	QString name = sender()->objectName();
	uint num = name.split("_")[1].toUInt();

	for(uint i = 0; i < 9; i++){
		if (i == num - 1){
			label[i]->setStyleSheet("QLabel { background-color : black; color : white;}");
		}
		else{
			label[i]->setStyleSheet("QLabel { background-color : transparent; color : black; border : 2px solid white}");
		}
	}

	if(num > 0){
		selectedCell = num - 1;
		ui->txtCellNum->setText(QString::number(selectedCell + 1));

		ui->cbCellType->setCurrentIndex(cell[selectedCell].id);

		ui->cbCellPose->setCurrentText(QString::number(cell[selectedCell].angle));

	}
}

void SettingClass::currentIndexChanged(int index){
//	std::cout << "current index : " << index << std::endl;

	if(index > 0){
//		qDebug() << label[selectedCell]->geometry().width();
//		qDebug() << label[selectedCell]->geometry().height();

		QImage image;
		QPixmap pixmap;

		if(image.load(QString(":/images/" + fileName[index].toLower() + ".png"))){
			pixmap = QPixmap::fromImage(image);
			pixmap = pixmap.scaled(label[selectedCell]->geometry().width() - 4, label[selectedCell]->geometry().height() - 4);
		}
		label[selectedCell]->setPixmap(pixmap);
		label[selectedCell]->setAlignment(Qt::AlignmentFlag::AlignCenter);

		angle = 0;
	}
	else if(index == 0){
		label[selectedCell]->clear();
		label[selectedCell]->setText(QString::number((selectedCell + 1)));
	}

	cell[selectedCell].id = index;
	memcpy(cell[selectedCell].type, fileName[index].toStdString().c_str(), 10);
}

void SettingClass::typeActivated(int index){
	currentIndexChanged(index);
}

void SettingClass::poseActivated(int index){
	QImage image;
	QPixmap pixmap;

	if(image.load(QString(":/images/" + fileName[cell[selectedCell].id].toLower() + ".png"))){
		pixmap = QPixmap::fromImage(image);
		pixmap = pixmap.scaled(label[selectedCell]->geometry().width() - 4, label[selectedCell]->geometry().height() - 4);
	}
	label[selectedCell]->setPixmap(pixmap);
	label[selectedCell]->setAlignment(Qt::AlignmentFlag::AlignCenter);

	int ang = ui->cbCellPose->currentText().toInt();
	cell[selectedCell].angle = ang;
	rotateImage(ang);
}

void SettingClass::rotateImage(int ang){
	double angle = ang*M_PI/180.0;
	QTransform trans(cos(angle), -sin(angle), 0, sin(angle), cos(angle), 0, 0, 0, 1);
	label[selectedCell]->setPixmap(label[selectedCell]->pixmap()->transformed(trans));
	label[selectedCell]->setAlignment(Qt::AlignmentFlag::AlignCenter);
}

void SettingClass::getLayoutInfor(section *arg){
	update();
	memcpy(arg, cell, sizeof(section)*9);
}

void SettingClass::btnSaveClicked(){
	xml_document doc;
	xml_node dec = doc.append_child(node_declaration);
	dec.append_attribute("version") = "1.0";
	dec.append_attribute("encoding") = "UTF-8";

	xml_node cells = doc.append_child("cell");
	for(int i = 0; i < 9; i++){
		xml_node section = cells.append_child("section");
		section.append_attribute("num").set_value(std::to_string(i+1).c_str());
		section.append_child("type").append_child(node_pcdata).set_value(cell[i].type);
		section.append_child("id").append_child(node_pcdata).set_value(std::to_string(cell[i].id).c_str());
		section.append_child("angle").append_child(node_pcdata).set_value(std::to_string(cell[i].angle).c_str());
	}

	std::string path = ros::package::getPath("keti_workcell_control2");
	path.append("/layout.xml");
	doc.save_file(path.c_str());
}

void SettingClass::update(){
	QString pwd("");
	char *PWD;
	PWD = getenv("PWD");
	pwd.append(PWD);
	std::cout << pwd.toStdString() << std::endl;

	std::string path = ros::package::getPath("keti_workcell_control2");
	path.append("/layout.xml");

	xml_document doc;
	xml_parse_result result = doc.load_file(path.c_str());

	if(result.status == 0){
		int indx = 0;
		for(xml_node section : doc.child("cell").children("section")){
			indx = section.attribute("num").as_int() - 1;
			memcpy(cell[indx].type, section.child_value("type"), 16);
			cell[indx].id = atoi(section.child_value("id"));
			cell[indx].angle = atoi(section.child_value("angle"));
		}
	}
	else{
		std::cout << "xml load error : " << result.description() << std::endl;
	}

	for(uint i = 0; i < 9; i++){
		if(cell[i].id > 0){
			selectedCell = i;
			currentIndexChanged(cell[i].id);
			rotateImage(cell[i].angle);
		}
	}
}

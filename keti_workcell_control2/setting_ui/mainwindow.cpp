#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
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
	}

	selectedCell = 0;

	connect(ui->cbCellType, SIGNAL(currentIndexChanged(int)), this, SLOT(currentIndexChanged(int)));
	cellName.push_back("");
	cellName.push_back("ROBOT");
	cellName.push_back("ARF");
	cellName.push_back("TOOL");
	cellName.push_back("VISION");
	cellName.push_back("AXIS2");
	ui->cbCellType->addItems(cellName);

	fileName = cellName;

	connect(ui->btnCCW, SIGNAL(clicked()), this, SLOT(btnCCWClicked()));
	connect(ui->btnCW, SIGNAL(clicked()), this, SLOT(btnCWClicked()));
	connect(ui->btnSave, SIGNAL(clicked()), this, SLOT(btnSaveClicked()));

	update();
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::labelClicked(){
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
	}
}

void MainWindow::currentIndexChanged(int index){
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
}

void MainWindow::btnCWClicked(){
	label[selectedCell]->setPixmap(label[selectedCell]->pixmap()->transformed(QTransform().rotate(-90)));
	label[selectedCell]->setAlignment(Qt::AlignmentFlag::AlignCenter);

	angle -= 90;
	if(angle == -360) angle = 0;
}

void MainWindow::btnCCWClicked(){
	label[selectedCell]->setPixmap(label[selectedCell]->pixmap()->transformed(QTransform().rotate(90)));
	label[selectedCell]->setAlignment(Qt::AlignmentFlag::AlignCenter);

	angle += 90;
	if(angle == 360) angle = 0;
}

void MainWindow::btnSaveClicked(){
	xml_document doc;

	xml_node dec = doc.append_child(node_declaration);
	dec.append_attribute("version") = "1.0";
	dec.append_attribute("encoding") = "UTF-8";

//	xml_node  = doc.append_child("cell");

//	xml_node cell = .append_child("cell");

	doc.save_file("layout.xml");
}

void MainWindow::update(){
//	xml_document doc;
//	xml_parse_result result = doc.load_file("config/layout.xml");

//	if(result.status > 0){

//	}
}

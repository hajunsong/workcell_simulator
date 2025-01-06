#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtDebug>

#include <iostream>
#include <vector>

#include "qclicklabel.h"
#include "pugixml.hpp"
using namespace pugi;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private:
	Ui::MainWindow *ui;

	std::vector<QClickLabel*> label;
	QStringList cellName;
	QStringList fileName;

	uint selectedCell;
	int angle;

	void update();

public slots:
	// click label event
	void labelClicked();

	// combo box event
	void currentIndexChanged(int index);

	// button event
	void btnCWClicked();
	void btnCCWClicked();
	void btnSaveClicked();
};
#endif // MAINWINDOW_H

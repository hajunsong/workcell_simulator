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

typedef struct Section{
	char type[16];
	int id;
	int angle;
}section;

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

	section cell[9];

	void update();
	void rotateImage(int ang);

public slots:
	// click label event
	void labelClicked();

	// combo box event
	void currentIndexChanged(int index);
	void activated(int arg);

	// button event
	void btnCWClicked();
	void btnCCWClicked();
	void btnSaveClicked();
};
#endif // MAINWINDOW_H

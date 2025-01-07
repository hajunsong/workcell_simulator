#pragma once

#include <QWidget>
#include <QCloseEvent>

#include <iostream>
#include <vector>

#include "qclicklabel.h"
#include "pugixml.hpp"
using namespace pugi;

QT_BEGIN_NAMESPACE
namespace Ui { class SettingClass; }
QT_END_NAMESPACE

typedef struct Section{
	char type[16];
	int id;
	int angle;
}section;

class SettingClass : public QWidget
{
	Q_OBJECT

public:
	SettingClass(QWidget *parent = nullptr);
	~SettingClass();

private:
	Ui::SettingClass *ui;

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

	// close event
	void closeEvent(QCloseEvent *event);

signals:
	void windowClose();
};

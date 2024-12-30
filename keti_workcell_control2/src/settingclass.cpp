#include "settingclass.h"
#include "ui_settingclass.h"

SettingClass::SettingClass(QWidget *parent) : QWidget(parent){
    ui->setupUi(this);
}

SettingClass::~SettingClass(){
    delete ui;
}

void SettingClass::closeEvent(QCloseEvent *event){
    delete ui;
    emit close();
    event->accept();
}
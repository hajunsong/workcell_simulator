#pragma once

#include <QWidget>
#include <QCloseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class SettingClass; }
QT_END_NAMESPACE

class SettingClass : public QWidget
{
    Q_OBJECT

public:
    SettingClass(QWidget *parent = nullptr);
    ~SettingClass();

private:
    Ui::SettingClass *ui;

public slots:
    // close event
    void closeEvent(QCloseEvent *event);

signals:
    void close();
};
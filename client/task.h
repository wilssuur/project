#ifndef TASK_H
#define TASK_H

#include <QDialog>
//#include "ui_task.h"
//#include "mainwindow.h"
#include <QMessageBox>
#include <QWidget>
#include <QLineEdit>
#include "statistics.h"
#include <QPushButton>
#include "funcforclient.h"

namespace Ui {
class task;
}

class task : public QDialog
{
    Q_OBJECT

public:
    explicit task(QWidget *parent = nullptr);
    ~task();

    void set_login(QString log);
private slots:
    void on_leavaccountButton_clicked();

    void on_VariantButton_clicked();

    void on_statisticsButton_clicked();


    void on_checkansButton_clicked();

    void on_againButton_clicked();
    void on_message_from_server_task(QString msg);

private:
    Ui::task *ui;
    statistics *stat;
    QString login;
signals:
    void is_hide();
};

//void setLabel(const QString& x);

#endif // TASK_H


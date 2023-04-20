#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "registrationwindow.h"
#include "task.h"
#include <QMessageBox>
#include <task.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    taskwindow = new task;
    connect(taskwindow, &task::is_hide, this, &MainWindow::show);
    //connect(SingletonClient::getInstance(), &SingletonClient::auth, taskwindow, &task::slot_show);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_registrationButton_clicked()
{
    this->close();
    registrationwindow  = new RegistrationWindow;
    registrationwindow->show();
    connect(registrationwindow, &RegistrationWindow::is_hide, this, &MainWindow::show);

}


void MainWindow::on_EnterButton_clicked()
{
    QString login = ui->lineEditlogin->text();
    QString password = ui->lineEditpassword->text();
    if (login == "lilia_koptikova" and password == "2102lilia"){
        QMessageBox::information(this, "Успешно", "Вы прошли авторизацию");
        this->close();
        taskwindow->show();
    }
    else{
        QMessageBox::warning(this, "Неуспешно", "Неверный логин или пароль");

    }

}


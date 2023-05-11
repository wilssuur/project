#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    taskwindow = new task;
    connect(taskwindow, &task::is_hide, this, &MainWindow::show);
    connect(SingletonClient::getInstance(), &SingletonClient::msg_from_server_auth, this, &MainWindow::on_message_from_server_auth);
    registrationwindow  = new RegistrationWindow;

    connect(registrationwindow, &RegistrationWindow::is_hide, this, &MainWindow::show);
   //taskwindow, &task::slot_show);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_registrationButton_clicked()
{
    this->close();
   // registrationwindow  = new RegistrationWindow;
    registrationwindow->show();
   // connect(registrationwindow, &RegistrationWindow::is_hide, this, &MainWindow::show);
    //connect(registrationwindow, &RegistrationWindow::is_reg, this, &MainWindow::slot_auth);
}

void MainWindow::slot_auth(QString msg)
{
    SingletonClient::getInstance()->send_msg_to_server(msg);
}

void MainWindow::on_EnterButton_clicked()
{
    QString login = ui->lineEditlogin->text();
    QString password = ui->lineEditpassword->text();

    SingletonClient::getInstance()->send_msg_to_server("Auth "+login+" "+password);

}

void MainWindow::on_message_from_server_auth(QString msg)
{
    if (msg.left(5) == "auth+"){
        //std::string login = msg.substr(msg.find(" ")+1,-1);
        QMessageBox::information(this, "Успешно", "Вы прошли авторизацию");
        ui->lineEditlogin->setText("");
        ui->lineEditpassword->setText("");
        this->close();
        taskwindow->set_login(msg.mid(6));
        taskwindow->show();
    }
    else if (msg.left(5) == "auth-"){
        QMessageBox::warning(this, "Неуспешно", "Неверный логин или пароль");

    }

}

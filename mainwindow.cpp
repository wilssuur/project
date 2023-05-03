#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    taskwindow = new task;
    connect(taskwindow, &task::is_hide, this, &MainWindow::show);
    connect(SingletonClient::getInstance(), &SingletonClient::msg_from_server, this, &MainWindow::on_message_from_server);
            //taskwindow, &task::slot_show);
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
    //connect(registrationwindow, &RegistrationWindow::is_hide, this, &MainWindow::show);
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

void MainWindow::on_message_from_server(QString msg)
{
    if (msg.left(5) == "auth+"){
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

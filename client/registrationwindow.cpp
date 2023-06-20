#include "registrationwindow.h"
#include "ui_registrationwindow.h"
#include "singletonclient.h"
#include "task.h"


RegistrationWindow::RegistrationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistrationWindow)
{
    ui->setupUi(this);
    //taskwindow = new task;
    //connect(taskwindow, &task::is_hide, this, &MainWindow::show);
    connect(SingletonClient::getInstance(), &SingletonClient::msg_from_server_reg, this, &RegistrationWindow::on_message_from_server_reg);
}

RegistrationWindow::~RegistrationWindow()
{
    delete ui;
}

void RegistrationWindow::on_pushButtoncheckregistration_clicked()
{
    QString email = ui->lineEditemail->text();
    QString surname = ui->lineEditsurname->text();
    QString name = ui->lineEditname->text();
    QString patronymic = ui->lineEditpatronymic->text();
    QString loginr = ui->lineEditloginr->text();
    QString group = ui->lineEditgroup->text();
    QString password1 = ui->lineEditpasswordr1->text();
    QString password2 = ui->lineEditpasswordr2->text();
    if(email !=""  && group !="" && surname !="" && name !="" && patronymic !="" && loginr !="" && password1 !="" && password2 !=""){
        if (password1 != password2){
            QMessageBox::warning(this,"Несовпадение","Пароли должны совпадать!");
        }
        else{
           // QMessageBox::information(this,"OK","Вы зарегистрировались!");
            SingletonClient::getInstance()->send_msg_to_server("Reg "+surname+" "+name + " " + patronymic + " "+
                                                             loginr+ " " +password1+ " "+ email + " " + group );
            hide();

        }
    }
    else{
        QMessageBox::warning(this,"Не все данные","Сначала заполните все поля!");
        //emit is_reg("Auth "+loginr+" "+password1);
    }
}


void RegistrationWindow::on_backButton_clicked()
{
    this->close();
    emit is_hide();
}

void RegistrationWindow::on_message_from_server_reg(QString msg)
{
    if (msg.left(4) == "reg-"){
        QMessageBox::information(this,"OK","error login");
        show();
        //QString login = ui->lineEditloginr->text();
        //QString password = ui->lineEditpasswordr1->text();
        //emit is_reg("Auth "+login+" "+password);
        //SingletonClient::getInstance()->send_msg_to_server("Auth "+login+" "+password);
        //this->on_backButton_clicked();
    }
    else {
        //QMessageBox::warning(this, "Неуспешно", "Ошибка");

    }

}

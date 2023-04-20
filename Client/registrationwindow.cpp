#include "registrationwindow.h"
#include "ui_registrationwindow.h"
#include <QMessageBox>
#include <QString>
#include <task.h>
#include "mainwindow.h"

RegistrationWindow::RegistrationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistrationWindow)
{
    ui->setupUi(this);
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
            QMessageBox::information(this,"OK","Вы зарегистрировались!");
            hide();
            task taskwindow;
            taskwindow.setModal(true);
            taskwindow.exec();

        }
    }
    else{
        QMessageBox::warning(this,"Не все данные","Сначала заполните все поля!");

    }
}


void RegistrationWindow::on_backButton_clicked()
{
    this->close();
    emit is_hide();
}


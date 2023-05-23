#include "task.h"
#include "ui_task.h"
#include "singletonclient.h"

task::task(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::task)
{
    ui->setupUi(this);
    //ui->checkansButton->hide();
    //ui->answerEdit->hide();
    connect(SingletonClient::getInstance(), &SingletonClient::msg_from_server_task, this, &task::on_message_from_server_task);
}

task::~task()
{
    delete ui;
}

void task::on_leavaccountButton_clicked()
{
    this->close();
    emit is_hide();

}


void task::on_VariantButton_clicked()
{
    int tasknumber =0;
    if (ui->radioButton->isChecked())
    {
        tasknumber = 1;
    }
    else if (ui->radioButton_2->isChecked()){
        tasknumber=2;
    }
    else if (ui->radioButton_3->isChecked()){
        tasknumber=3;
    }
    else{
        QMessageBox::warning(this,"Ошибка", "Выберите номер задачи!");
        return;
    }

    ui->answerEdit->show();
    QString variant = get_variant(tasknumber);
    //ui->labeltask->setText("Условие задачи "+get_task(tasknumber));
    ui->labelvariant->setText(variant);
    ui->labelanswer->setText("Ответ:");
    ui->checkansButton->show();
}



void task::set_login(QString log){
    login = log;
}


void task::on_checkansButton_clicked()
{
    QString tasknumber;
    if (ui->radioButton->isChecked())
    {
        tasknumber = "1";
    }
    else if (ui->radioButton_2->isChecked()){
        tasknumber = "2";
    }
    else if (ui->radioButton_3->isChecked()){
        tasknumber = "3";
    }
    if (ui->answerEdit->text() != ""){
        QString variant = ui->labelvariant->text();
        QString answer = ui->answerEdit->text();
        SingletonClient::getInstance()->send_msg_to_server("Check" + tasknumber + " " + answer + " " + variant);
        ui->labelresult->setText("проверка");
    }
    else {
        QMessageBox::warning(this,"Ошибка", "Сначала введите ответ");

    }
}

void task::on_message_from_server_task(QString msg)
{
    //логин
    msg = msg.trimmed();
    QStringList str_list = (QString(msg)).split("+");
    std::string login = str_list[1].toStdString();
    show();
    ui->labellogint->setText(QString::fromStdString(login));
}


void task::on_againButton_clicked()
{
    ui->answerEdit->setText("");
    ui->labeltask->setText("");
    ui->labelresult->setText("");
    if (ui->radioButton->isChecked()){
        ui->radioButton->setChecked(false);
    }
    else if (ui->radioButton_2->isChecked()){
        ui->radioButton_2->setChecked(false);
    }
    else {
        ui->radioButton_3->setChecked(false);
    }

}


void task::on_statisticsButton_clicked()
{
    QString loginn = ui->labellogint->text();
    SingletonClient::getInstance()->send_msg_to_server("Stat "+ loginn);
    statistics stat;
    stat.setModal(true);
    stat.exec();

}



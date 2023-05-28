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

    QString task = "";
    if (ui->radioButton->isChecked()){
        task = get_variant1();
    }
    else if (ui->radioButton_2->isChecked()){
        task = get_variant2();
    }
    else if (ui->radioButton_3->isChecked()){
        task = get_variant1();
    }
    else{
        QMessageBox::warning(this,"Ошибка", "Выберите номер задачи!");
        return;
    }
    ui->answerEdit->show();

    QStringList str_list = QString(task).split("+");

    std::string t = str_list[0].toStdString();
    std::string e = str_list[1].toStdString();
    ui->labelcount->setText(QString::fromStdString(t));
    int x = QString::fromStdString(t).toInt();
    QString tops = "";
    for (int i = 1; i <= x; i++){
        QString s = QString::number(i);
        tops = tops + s + ", ";
    }
    //((std::string)tops).erase(std::prev(t.end()));
    e.erase(std::prev(e.end()));

    ui->labeltops->setText(tops);
    ui->labeledges->setText(QString::fromStdString(e));

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

        QString count_tops = ui->labelcount->text();
        QString edges = ui->labeledges->text();
        QString answer = ui->answerEdit->text();
        QString loginn = ui->labellogint->text();
        QString task = count_tops + "+" + edges + "";
        SingletonClient::getInstance()->send_msg_to_server("Check" + tasknumber + " " + task + " " + answer + " " + loginn);
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



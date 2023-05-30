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
    connect(SingletonClient::getInstance(), &SingletonClient::msg_from_server_answer, this, &task::on_message_from_server_answer);
}

task::~task()
{
    delete ui;
}

void task::on_leavaccountButton_clicked()
{
    ui->answerEdit->setText("");
    ui->labeltask->setText("");
    ui->labelresult->setText("");
    ui->labeltask->setText("");
    ui->labeltops->setText("");
    ui->labeledges->setText("");
    ui->labele->setText("");
    ui->labelcount->setText("");
    this->close();
    emit is_hide();
}


void task::on_VariantButton_clicked()
{
    QString task = "";
    if (ui->radioButton->isChecked()){
        task = get_variant1();
        ui->labeltask->setText("Задача 1.");
    }
    else if (ui->radioButton_2->isChecked()){
        task = get_variant2();
        ui->labeltask->setText("Задача 2. Найти кратчайший путь между первой и последней \r\n вершинами в нагруженном связном ориентированном графе.");
    }
    else if (ui->radioButton_3->isChecked()){
        task = get_variant1();
        ui->labeltask->setText("Задача 3.");
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
    QString tops = "V = {";
    for (int i = 1; i <= x; i++){
        QString s = QString::number(i);
        tops = tops + s + ", ";
    }
    //((std::string)tops).erase(std::prev(t.end()));
    e.erase(std::prev(e.end()));
    tops.erase(std::prev(tops.end()));
    tops.erase(std::prev(tops.end()));
    tops = tops  + "}";

    ui->labeltops->setText(tops);
    ui->labeledges->setText(QString::fromStdString(e));
    ui->labele->setText("E = ");

    ui->labelanswer->setText("Ответ:");
    ui->checkansButton->show();
}

void task::on_message_from_server_answer(QString msg){
    msg = msg.trimmed();
    QStringList str_list = (QString(msg)).split(" ");
    std::string answer = str_list[1].toStdString();
    if (answer == "-1" )
        ui->labelresult->setText(QString::fromStdString("Неверно."));
    else
        ui->labelresult->setText(QString::fromStdString("Верно! Молодец!"));

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
    ui->labeltask->setText("");
    ui->labeltops->setText("");
    ui->labeledges->setText("");
    ui->labele->setText("");
    ui->labelcount->setText("");
    ui->radioButton->setChecked(false);
    ui->radioButton_2->setChecked(false);
    ui->radioButton_3->setChecked(false);
    /*
    if (ui->radioButton->isChecked()){
        ui->radioButton->setChecked(false);
    }
    else if (ui->radioButton_2->isChecked()){
        ui->radioButton_2->setChecked(false);
    }
    else {
        ui->radioButton_3->setChecked(false);
    }*/

}


void task::on_statisticsButton_clicked()
{
    QString loginn = ui->labellogint->text();
    SingletonClient::getInstance()->send_msg_to_server("Stat "+ loginn);
    statistics stat;
    stat.setModal(true);
    stat.exec();

}



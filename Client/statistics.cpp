#include "statistics.h"
#include "ui_statistics.h"
#include "singletonclient.h"

statistics::statistics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistics)
{
    ui->setupUi(this);
    connect(SingletonClient::getInstance(), &SingletonClient::msg_from_server_stat, this, &statistics::on_message_from_server_stat);
}

statistics::~statistics()
{
    delete ui;
}

void statistics::on_message_from_server_stat(QString msg)
{

    msg = msg.trimmed();
    QStringList str_list = (QString(msg)).split("+");
    //std::string str = str_list[0].toStdString();
    std::string task1 = str_list[1].toStdString();
    std::string task2 = str_list[2].toStdString();
    std::string task3 = str_list[3].toStdString();
    if (msg.left(4) == "stat"){
        show();
        ui->labeltask1->setText(QString::fromStdString(task1));
        ui->labeltask2->setText(QString::fromStdString(task2));
        ui->labeltask3->setText(QString::fromStdString(task3));
        //ui->login->setText(QString::fromStdString(task3));
        //this->on_backButton_clicked();
    }
    else {
        //QMessageBox::warning(this, "Неуспешно", "Ошибка");

    }
}

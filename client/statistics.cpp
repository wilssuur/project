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
    if (msg.left(5) == "stat+"){
        ui->labelfio->clear();
        ui->labelfio->setText(msg);

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

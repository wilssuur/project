#include "task.h"
#include "ui_task.h"

task::task(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::task)
{
    ui->setupUi(this);
    //ui->checkansButton->hide();
    //ui->answerEdit->hide();
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



void task::on_statisticsButton_clicked()
{
    statistics stat;
    stat.setModal(true);
    stat.exec();
}

void task::set_login(QString log){
    login = log;
}

void task::on_checkansButton_clicked()
{
    if (ui->answerEdit->text() != ""){
        ui->labelresult->setText("Проверяем))");
    }
    else {
        QMessageBox::warning(this,"Ошибка", "Сначала введите ответ");

    }
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


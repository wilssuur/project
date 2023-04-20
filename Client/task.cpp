#include "task.h"
#include "ui_task.h"
#include <mainwindow.h>
#include <QMessageBox>
#include <QWidget>
#include <QLineEdit>
#include <statistics.h>
#include <QPushButton>

task::task(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::task)
{
    ui->setupUi(this);
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
    if (ui->radioButton->isChecked())
    {
        QLineEdit *ans = new QLineEdit(this);
        ans->setGeometry(365,270,250,30);
        ans->show();
        ui->labeltask->setText("Условие задачи 1");
        ui->labelanswer->setText("Ответ:");
        QPushButton *checkans = new QPushButton(this);
        checkans->setGeometry(365,310,110,40);
        checkans->setText("Проверить ответ");
        checkans->show();

    }
    else if (ui->radioButton_2->isChecked()){
        QLineEdit *ans = new QLineEdit(this);
        ans->setGeometry(365,270,250,30);
        ans->show();
        ui->labeltask->setText("Условие задачи 2");
        ui->labelanswer->setText("Ответ:");
        QPushButton *checkans = new QPushButton(this);
        checkans->setGeometry(365,310,110,40);
        checkans->setText("Проверить ответ");
        checkans->show();

    }
    else if (ui->radioButton_3->isChecked()){
        QLineEdit *ans = new QLineEdit(this);
        ans->setGeometry(365,270,250,30);
        ans->show();
        ui->labeltask->setText("Условие задачи 3");
        ui->labelanswer->setText("Ответ:");
        QPushButton *checkans = new QPushButton(this);
        checkans->setGeometry(365,310,110,40);
        checkans->setText("Проверить ответ");
        checkans->show();

    }
    else{
        QMessageBox::warning(this,"Ошибка", "Выберите номер задачи!");
    }
}


void task::on_statisticsButton_clicked()
{
    statistics stat;
    stat.setModal(true);
    stat.exec();
}

void task::slot_show(QString log){
    login = log;
    show();
}

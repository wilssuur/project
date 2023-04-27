#include "statistics.h"
#include "ui_statistics.h"

statistics::statistics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistics)
{
    ui->setupUi(this);
}

statistics::~statistics()
{
    delete ui;
}

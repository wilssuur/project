#include "dialogregistration.h"
#include "ui_dialogregistration.h"

DialogRegistration::DialogRegistration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogRegistration)
{
    ui->setupUi(this);
}

DialogRegistration::~DialogRegistration()
{
    delete ui;
}

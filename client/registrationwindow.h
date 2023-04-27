#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include <QString>
//#include "task.h"
//#include "mainwindow.h"

namespace Ui {
class RegistrationWindow;
}

class RegistrationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegistrationWindow(QWidget *parent = nullptr);
    ~RegistrationWindow();

private slots:
    void on_pushButtoncheckregistration_clicked();

    void on_backButton_clicked();

private:
    Ui::RegistrationWindow *ui;
signals:
    void is_hide();
    void is_reg(QString);
    void on_message_from_server_reg(QString msg);
};

#endif // REGISTRATIONWINDOW_H

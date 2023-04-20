#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include <QDialog>

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

};

#endif // REGISTRATIONWINDOW_H

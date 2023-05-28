/**
 * @file registrationwindow.h
 * @brief Contains registration functions for registration window
*/
#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include <QString>

namespace Ui {
class RegistrationWindow;
}

class RegistrationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegistrationWindow(QWidget *parent = nullptr); /**< Constructor for RegistrationWindow class. */
    ~RegistrationWindow(); /**< Destructor for RegistrationWindow class. */

private slots:
    void on_pushButtoncheckregistration_clicked(); /**< Slot for check registration button. */
    void on_backButton_clicked(); /**< Slot for back button. */
    void on_message_from_server_reg(QString msg); /**< Slot for message from server. */

private:
    Ui::RegistrationWindow *ui; /**< Pointer to the UI of the RegistrationWindow. */

signals:
    void is_hide(); /**< Signal to hide RegistrationWindow. */
    void is_reg(QString); /**< Signal for registration request. */

};

#endif // REGISTRATIONWINDOW_H

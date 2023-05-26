/**
 * @file mainwindow.h
 * @brief The MainWindow class header file.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "registrationwindow.h"
#include "task.h"
#include <QMainWindow>
#include <QMessageBox>
#include "singletonclient.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief The MainWindow class represents the main window of the application.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a MainWindow object.
     * @param parent The parent widget.
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destroys the MainWindow object.
     */
    ~MainWindow();

private slots:
    /**
     * @brief Handles the registration button click event.
     */
    void on_registrationButton_clicked();

    /**
     * @brief Handles the enter button click event.
     */
    void on_EnterButton_clicked();

    /**
     * @brief Handles the message from server authentication signal.
     * @param msg The message from the server.
     */
    void on_message_from_server_auth(QString msg);

    /**
     * @brief Handles the authentication signal.
     * @param msg The authentication message.
     */
    void slot_auth(QString msg);

private:
    Ui::MainWindow *ui; /**< The user interface of the main window. */
    RegistrationWindow *registrationwindow; /**< The registration window. */
    task *taskwindow; /**< The task window. */

};

#endif // MAINWINDOW_H

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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
/*signals:
    void mainwindow(QString);*/
private slots:
    void on_registrationButton_clicked();

    void on_EnterButton_clicked();

    void on_message_from_server_auth(QString msg);
    void slot_auth(QString msg);

    //new
 //   void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    RegistrationWindow *registrationwindow;
    task *taskwindow;

    //new
//signals:
 //   void mySignalread(const QString &text);
};
#endif // MAINWINDOW_H
/*
private slots: //взял этот кусок, чтобы Вы понимали, где вставлять описание сигнала
void on_pushButton_clicked();

signals:
void mySignal(const QString &text); //название сигнала потом сами пропишите*/


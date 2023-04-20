#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <registrationwindow.h>
#include <task.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void mainwindow();
private slots:
    void on_registrationButton_clicked();

    void on_EnterButton_clicked();

private:
    Ui::MainWindow *ui;
    RegistrationWindow *registrationwindow;
    task *taskwindow;
};
#endif // MAINWINDOW_H

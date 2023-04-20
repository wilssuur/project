#ifndef TASK_H
#define TASK_H
#include <statistics.h>
#include <QDialog>

namespace Ui {
class task;
}

class task : public QDialog
{
    Q_OBJECT

public:
    explicit task(QWidget *parent = nullptr);
    ~task();
private slots:
    void on_leavaccountButton_clicked();

    void on_VariantButton_clicked();

    void on_statisticsButton_clicked();

    void slot_show(QString log);

private:
    Ui::task *ui;
    statistics *stat;
    QString login;
signals:
    void is_hide();
};

#endif // TASK_H

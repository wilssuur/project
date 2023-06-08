#ifndef STATISTICS_H
#define STATISTICS_H

#include <QDialog>

namespace Ui {
class statistics;
}

class statistics : public QDialog
{
    Q_OBJECT

public:
    explicit statistics(QWidget *parent = nullptr);
    ~statistics();

private slots:
    void on_message_from_server_stat(QString msg);
private:
    Ui::statistics *ui;
};

#endif // STATISTICS_H

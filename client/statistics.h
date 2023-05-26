/**
 * @file statistics.h
 * @brief Contains functions for statistics and connection between server and client
*/
#ifndef STATISTICS_H
#define STATISTICS_H

#include <QDialog>

namespace Ui {
class statistics;
}

/**
 * @brief The statistics class for displaying statistics information.
 */
class statistics : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for the statistics class.
     * @param parent The parent object of the statistics class.
     */
    explicit statistics(QWidget *parent = nullptr);
    /**
     * @brief Destructor for the statistics class.
     */
    ~statistics();

private slots:
    /**
     * @brief Slot for receiving messages from the server for statistics.
     * @param msg The message received from the server.
     */
    void on_message_from_server_stat(QString msg);
private:
    Ui::statistics *ui;
};

#endif // STATISTICS_H

/**
 * @file task.h
 * @brief Contains functions that generate tasks and connections with statistics
*/
#ifndef TASK_H
#define TASK_H

#include <QDialog>
#include <QMessageBox>
#include <QWidget>
#include <QLineEdit>
#include "statistics.h"
#include <QPushButton>
#include "funcforclient.h"

namespace Ui {
class task;
}

/**
 * @brief Класс для работы с заданиями
 *
 */
class task : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса
     *
     * @param parent Указатель на родительский виджет
     */
    explicit task(QWidget *parent = nullptr);

    /**
     * @brief Деструктор класса
     *
     */
    ~task();

    /**
     * @brief Установка логина пользователя
     *
     * @param log Логин пользователя
     */
    void set_login(QString log);

private slots:
    /**
     * @brief Обработчик нажатия кнопки "Выйти из аккаунта"
     *
     */
    void on_leavaccountButton_clicked();

    /**
     * @brief Обработчик нажатия кнопки "Выбрать вариант"
     *
     */
    void on_VariantButton_clicked();

    /**
     * @brief Обработчик нажатия кнопки "Статистика"
     *
     */
    void on_statisticsButton_clicked();

    /**
     * @brief Обработчик нажатия кнопки "Проверить ответ"
     *
     */
    void on_checkansButton_clicked();

    /**
     * @brief Обработчик нажатия кнопки "Начать заново"
     *
     */
    void on_againButton_clicked();

    /**
     * @brief Обработчик получения сообщения от сервера
     *
     * @param msg Сообщение от сервера
     */
    void on_message_from_server_task(QString msg);

private:
    Ui::task *ui;
    statistics *stat;
    QString login;

signals:
    /**
     * @brief Сигнал для скрытия окна задания
     *
     */
    void is_hide();
};

#endif // TASK_H

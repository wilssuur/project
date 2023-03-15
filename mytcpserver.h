#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include <QtNetwork>
#include <QByteArray> //чтобы по битово передавать
#include <QDebug> //чтобы выводить в консоль сообщения

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);
    ~MyTcpServer();
public slots:
    void slotNewConnection();
    void slotClientDisconnected();

    void slotServerRead();
    //void slotReadClient();
private:
    QTcpServer * mTcpServer; //сам сервер
    QTcpSocket * mTcpSocket; //QTcpSocket отвечает за подключение(клиентов)
    int server_status;
};
#endif // MYTCPSERVER_H


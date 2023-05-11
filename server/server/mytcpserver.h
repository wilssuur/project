#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <QMap>

///
////// \brief The MyTcpServer class
///
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
    QTcpServer * mTcpServer;
    //QTcpSocket * mTcpSocket; //QTcpSocket отвечает за подключение(клиентов)
    QMap<int, QTcpSocket*> SocketClients;
    int server_status;
};
#endif // MYTCPSERVER_H


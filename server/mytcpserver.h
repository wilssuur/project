/**
 * @file MyTcpServer.h
 * @brief Header file for MyTcpServer class
 */
#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <QMap>

/**
 * @class MyTcpServer
 * @brief TCP server class for handling client connections and requests
 */
class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Constructor for MyTcpServer
     * @param parent Parent object, default is nullptr
     */
    explicit MyTcpServer(QObject *parent = nullptr);
    /**
     * @brief Destructor for MyTcpServer
     */
    ~MyTcpServer();

public slots:
    /**
     * @brief Slot for handling new client connections
     */
    void slotNewConnection();
    /**
     * @brief Slot for handling client disconnections
     */
    void slotClientDisconnected();
    /**
     * @brief Slot for handling incoming requests from clients
     */
    void slotServerRead();
private:
    QTcpServer * mTcpServer; /**< Pointer to QTcpServer instance */
    QMap<int, QTcpSocket*> SocketClients; /**< Map of client sockets */
    int server_status; /**< Status of the server */
};
#endif // MYTCPSERVER_H

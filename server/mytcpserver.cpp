#include "mytcpserver.h"
#include "funcForServer.h"
#include <QDebug>
#include <QCoreApplication>
#include <QString>

MyTcpServer::~MyTcpServer()
{
    //mTcpSocket->close();
    foreach (int key, SocketClients.keys())
    {
        SocketClients.value(key)->close();
        SocketClients.remove(key);
    }
    mTcpServer->close();
    server_status=0;
}
MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started";
    } else {
        server_status=1;
        qDebug() << "server is started";
    }
}

void MyTcpServer::slotNewConnection(){
    if(server_status==1){
        QTcpSocket *curr_mTcpSocket;
        curr_mTcpSocket = mTcpServer->nextPendingConnection();
        SocketClients[curr_mTcpSocket->socketDescriptor()] = curr_mTcpSocket;
        curr_mTcpSocket->write("Hello, World!!! I am server!\r\n");
        connect(curr_mTcpSocket, &QTcpSocket::readyRead,
                this,&MyTcpServer::slotServerRead);
        connect(curr_mTcpSocket,&QTcpSocket::disconnected,
                this,&MyTcpServer::slotClientDisconnected);
        qDebug() << "client connected" << curr_mTcpSocket->socketDescriptor();
    }
}

void MyTcpServer::slotServerRead(){
    QTcpSocket *curr_mTcpSocket = (QTcpSocket*)sender();
    QByteArray array;
    std::string mystr;
    while(curr_mTcpSocket->bytesAvailable()>0)
    {
        array = curr_mTcpSocket->readAll();
        mystr = array.trimmed().toStdString();
    }
    qDebug()<<"Recieve:"<<QString::fromStdString(mystr);
    if (mystr == "stop") {
        curr_mTcpSocket->write("Goodbye!");
        slotClientDisconnected();
    }
    else {
        QByteArray res = parsing(array);
        qDebug()<<"Send"<<res;
        curr_mTcpSocket->write(res);
    }
}
void MyTcpServer::slotClientDisconnected(){
    //QTcpSocket *curr_mTcpSocket = mTcpSocket[mTcpServer->socketDescriptor()];
    QTcpSocket *curr_mTcpSocket = (QTcpSocket*)sender();
    curr_mTcpSocket->close();
    SocketClients.remove(curr_mTcpSocket->socketDescriptor());

}

#include "mytcpserver.h"
#include "funcForServer.h"
#include <QDebug>
#include <QCoreApplication>
#include <QString>

MyTcpServer::~MyTcpServer()
{
    //mTcpSocket->close();
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
        mTcpSocket = mTcpServer->nextPendingConnection();
        mTcpSocket->write("Hello, World!!! I am server!\r\n");
        connect(mTcpSocket, &QTcpSocket::readyRead,
                this,&MyTcpServer::slotServerRead);
        connect(mTcpSocket,&QTcpSocket::disconnected,
                this,&MyTcpServer::slotClientDisconnected);
    }
}

void MyTcpServer::slotServerRead(){
    QByteArray array;
    std::string mystr;
    while(mTcpSocket->bytesAvailable()>0)
    {
        array = mTcpSocket->readAll();
        mystr = array.trimmed().toStdString();
    }
    if (mystr == "stop") {
        mTcpSocket->write("Goodbye!");
        slotClientDisconnected();
    }
    else {
        mTcpSocket->write(parsing(array));
    }
}

void MyTcpServer::slotClientDisconnected(){
    mTcpSocket->close();
}

#include "singletonClient.h"

SingletonClient::SingletonClient(QObject *parent) : QObject(parent){
    mTcpSocket = new QTcpSocket(this);
    mTcpSocket -> connectToHost("127.0.0.1",33333);
    connect(mTcpSocket, &QTcpSocket::readyRead,
            this, &SingletonClient::slotServerRead);

}
SingletonClient* SingletonClient::getInstance(){
    if (!p_instance)
    {
        p_instance = new SingletonClient();
        destroyer.initialize(p_instance);
    }
    return p_instance;
}

void SingletonClient::send_msg_to_server(QString query){
    qDebug()<<"Send "<< query;
    mTcpSocket->write(query.toUtf8());
}

void SingletonClient::slotServerRead(){

    QString msg = "";
    while(mTcpSocket->bytesAvailable()>0)
    {
        msg.append(mTcpSocket->readAll());
    }
    qDebug()<<"Recieve: "<<msg;

    emit msg_from_server(msg);
}

SingletonClient::~SingletonClient(){
    mTcpSocket->close();
};



SingletonClient* SingletonClient::p_instance;
SingletonDestroyer SingletonClient::destroyer;


#include "singletonClient.h"

SingletonClient::SingletonClient(QObject *parent) : QObject(parent){
    mTcpSocket = new QTcpSocket(this);
    mTcpSocket -> connectToHost("192.168.2.105", 33333);
    //mTcpSocket -> connectToHost("172.20.10.2", 33333);
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
    query.append("\r\n");
    qDebug()<<"Send "<< query;
    mTcpSocket->write(query.toUtf8());
    slotServerRead();
}

void SingletonClient::slotServerRead(){

    QString msg = "";
    while(mTcpSocket->bytesAvailable()>0)
    {
        msg.append(mTcpSocket->readAll());
    }
    qDebug()<<"Recieve: "<<msg;

    if(msg.left(3) == "reg")
        emit msg_from_server_reg(msg);
    if(msg.left(4) == "auth"){
        emit msg_from_server_auth(msg);
        emit msg_from_server_task(msg);}
    if(msg.left(4) == "stat")
        emit msg_from_server_stat(msg);
    if(msg.left(5) == "check")
        emit msg_from_server_answer(msg);
   // if(msg.left(4) == "task")
     //   emit msg_from_server_task(msg);

}

SingletonClient::~SingletonClient(){
    mTcpSocket->close();
};



SingletonClient* SingletonClient::p_instance;
SingletonDestroyer SingletonClient::destroyer;


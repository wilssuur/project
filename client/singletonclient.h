#ifndef SINGLETONCLIENT_H
#define SINGLETONCLIENT_H
#include<QDebug>
#include<QObject>
#include<QtNetwork>
#include<QTcpSocket>
#include<QByteArray>
#include<QString>

class SingletonClient;

class SingletonDestroyer
{
private:
    SingletonClient * p_instance;
public:
    ~SingletonDestroyer() { delete p_instance; }
    void initialize(SingletonClient * p){p_instance = p;};
};


class SingletonClient : public QObject
{
    Q_OBJECT
private:
    static SingletonClient * p_instance;
    static SingletonDestroyer destroyer;
    QTcpSocket * mTcpSocket;
protected:
    explicit SingletonClient(QObject *parent = nullptr);
    SingletonClient(const SingletonClient& ) = delete;
    SingletonClient& operator = (SingletonClient &) = delete;
    ~SingletonClient();
    friend class SingletonDestroyer;
public:
    static SingletonClient* getInstance();
    void send_msg_to_server(QString query);
signals:
    void msg_from_server_auth(QString msg);
    void msg_from_server_reg(QString msg);
    void msg_from_server_stat(QString msg);
    void msg_from_server_task(QString msg);
    void msg_from_server_answer(QString msg);
private slots:
    void slotServerRead();

};


#endif // SINGLETONCLIENT_H

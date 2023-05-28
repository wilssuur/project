/**
 * @file singletonclient.h
 * @brief Contains the SingletonClient class for managing the client-side connection to the server.
 */

#ifndef SINGLETONCLIENT_H
#define SINGLETONCLIENT_H

#include<QDebug>
#include<QObject>
#include<QtNetwork>
#include<QTcpSocket>
#include<QByteArray>
#include<QString>

/**
 * @brief The SingletonDestroyer class for destroying the SingletonClient instance.
 */

class SingletonClient;

class SingletonDestroyer
{
private:
    SingletonClient * p_instance;
public:
    ~SingletonDestroyer() { delete p_instance; }
    void initialize(SingletonClient * p){p_instance = p;};
};

/**
 * @brief The SingletonClient class for managing the client-side connection to the server.
 */
class SingletonClient : public QObject
{
    Q_OBJECT
private:
    static SingletonClient * p_instance; /**< The instance of the SingletonClient. */
    static SingletonDestroyer destroyer; /**< The destroyer for the SingletonClient instance. */
    QTcpSocket * mTcpSocket; /**< The TCP socket for the client-side connection to the server. */
protected:
    explicit SingletonClient(QObject *parent = nullptr); /**< Constructor for the SingletonClient class. */
    SingletonClient(const SingletonClient& ) = delete; /**< Copy constructor for the SingletonClient class. */
    SingletonClient& operator = (SingletonClient &) = delete; /**< Assignment operator for the SingletonClient class. */
    ~SingletonClient(); /**< Destructor for the SingletonClient class. */
    friend class SingletonDestroyer; /**< Friend class for the SingletonDestroyer class. */
public:
    static SingletonClient* getInstance(); /**< Function to get the instance of the SingletonClient. */
    void send_msg_to_server(QString query); /**< Function to send a message to the server. */
signals:
    void msg_from_server_auth(QString msg); /**< Signal for message from server for authentication. */
    void msg_from_server_reg(QString msg); /**< Signal for message from server for registration. */
    void msg_from_server_stat(QString msg); /**< Signal for message from server for status. */
    void msg_from_server_task(QString msg); /**< Signal for message from server for task. */
private slots:
    void slotServerRead(); /**< Slot for reading messages from the server. */

};

#endif // SINGLETONCLIENT_H

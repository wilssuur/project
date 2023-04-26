#include <QCoreApplication>
#include "singletonclient.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    SingletonClient::getInstance();
    SingletonClient::getInstance()->send_msg_to_server("1234");


    return a.exec();
}

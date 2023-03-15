#include <QCoreApplication>
#include "mytcpserver.h"



int main(int argc, char *argv[])
//argc - количество параметров, argv - значение параметров
{
    QCoreApplication a(argc, argv);
    MyTcpServer server;

    return a.exec();
    //запускаем приложение посредством метода exec
}


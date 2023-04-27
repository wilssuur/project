#ifndef FUNCFORSERVER_H
#define FUNCFORSERVER_H
#include <QByteArray>
#include <string>
#include "DateBase.h"

QByteArray parsing(QByteArray str);

QByteArray auth(std::string login,std::string pass);
QByteArray reg(std::string sname, std::string name, std::string lname, std::string log, std::string pas, std::string email, std::string group);
QByteArray showstat(std::string login);
QByteArray task1(QString var);
QByteArray task2(QString var);
QByteArray task3(QString var);
QByteArray check(std::string tasknum, std::string resserver, std::string resclient);
QByteArray exit();


#endif // FUNCFORSERVER_H

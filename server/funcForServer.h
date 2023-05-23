#ifndef FUNCFORSERVER_H
#define FUNCFORSERVER_H
#include <QByteArray>
#include <string>
#include "DateBase.h"

QByteArray parsing(QByteArray str);

QByteArray auth(std::string login,std::string pass);
QByteArray reg(std::string sname, std::string name, std::string lname, std::string log, std::string pas, std::string email, std::string group);
QByteArray showstat(std::string login);
QByteArray task1(std::string answer);
QByteArray task2(std::string answer);
QByteArray task3(std::string answer);
QByteArray check(std::string task, std::string variant, std::string answer);
QByteArray exit();


#endif // FUNCFORSERVER_H

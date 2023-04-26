#ifndef FUNCFORSERVER_H
#define FUNCFORSERVER_H
#include <QByteArray>
#include <string>
#include "DateBase.h"

QByteArray parsing(QByteArray str);

QByteArray auth(std::string login,std::string pass);
QByteArray reg(std::string sname, std::string name, std::string lname, std::string log, std::string pas, std::string email, std::string group);
QByteArray showstat();
QByteArray task1();
QByteArray task2();
QByteArray task3();
QByteArray check(std::string task, std::string variant, std::string answer);
QByteArray exit();

#endif // FUNCFORSERVER_H

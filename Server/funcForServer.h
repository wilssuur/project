#ifndef FUNCFORSERVER_H
#define FUNCFORSERVER_H
#include <QByteArray>
#include <string>

QByteArray parsing(QByteArray str);

QByteArray auth(std::string login,std::string pass);
QByteArray reg(std::string sname, std::string name, std::string lname, std::string log, std::string pas);
QByteArray showstud(std::string user);
QByteArray showteach(std::string user);
QByteArray task();
QByteArray exit();

#endif // FUNCFORSERVER_H

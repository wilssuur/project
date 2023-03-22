#include "funcForServer.h"
#include <Qstring>
#include <QDebug>

QByteArray parsing(QByteArray str)
{
    std::string mystr = str.trimmed().toStdString().substr(0,str.toStdString().find(" "));

    if (mystr == "Auth") {
        mystr = str.toStdString().substr(str.toStdString().find(" ")+1, -1);

        std::string log = mystr.substr(0,mystr.find(" "));
        std::string pas = mystr.substr(mystr.find(" ")+1,-1);

        return auth(log,pas);
    }


    else if (mystr == "Reg") {
        mystr = str.toStdString().substr(str.toStdString().find(" ")+1, -1);

        std::string surname = mystr.substr(0,mystr.find(" "));
        std::string without_surname = mystr.substr(mystr.find(" ")+1,-1);

        std::string name = without_surname.substr(0, without_surname.find(" "));
        std::string without_name = without_surname.substr(without_surname.find(" ")+1,-1);

        std::string lastname = without_name.substr(0, without_name.find(" "));
        std::string without_lastname = without_name.substr(without_name.find(" ")+1,-1);

        std::string login = without_lastname.substr(0, without_lastname.find(" "));
        std::string without_login = without_lastname.substr(without_lastname.find(" ")+1,-1);

        std::string password = without_login.substr(0, without_login.find(" "));
        std::string without_password = without_login.substr(without_login.find(" ")+1,-1);

        return reg(surname, name, lastname, login, password);
    }

    else if (mystr == "ShowStat") {
        mystr = str.trimmed().toStdString().substr(str.toStdString().find(" ")+1, -1);
        std::string user = mystr;
        if (user == "student")
            return showstud(user);
        else if (user == "teacher")
            return showteach(user);
    }

    else if (mystr == "Tasks") {
        return task();
    }

    else if (mystr == "Exit") {
        return exit();
    }
}

QByteArray auth(std::string login,std::string pass)
{
    return QString::fromStdString((std::string)"Login: "+(login) + ", " + (std::string)"Password: " + pass).toUtf8();
}

QByteArray reg(std::string sname, std::string name, std::string lname, std::string log, std::string pas)
{
    return QString::fromStdString((std::string)"FIO: "+ (sname) + " " + (name) + " " + (lname) + (std::string)", Login: " + (log) + (std::string)", Password: " + (pas)).toUtf8();
}

QByteArray showstud(std::string user)
{
    return QString::fromStdString((std::string)"Statistics: for " + user + "\r\n").toUtf8();
}

QByteArray showteach(std::string user)
{
    return QString::fromStdString((std::string)"Statistics: for " + user + "\r\n").toUtf8();
}

QByteArray task()
{
    return QString::fromStdString((std::string)"Tasks to svole" + "\r\n").toUtf8();
}

QByteArray exit()
{
    return QString::fromStdString((std::string)"Goodbye!" + "\r\n").toUtf8();
}



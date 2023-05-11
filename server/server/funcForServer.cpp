#include "funcForServer.h"
#include <QString>
#include <QDebug>

QByteArray parsing(QByteArray str)
{
    std::string mystr = str.trimmed().toStdString().substr(0,str.toStdString().find(" "));

    if (mystr == "Auth") {
        mystr = str.toStdString().substr(str.toStdString().find(" ")+1, -1);

        QStringList str_list = (QString(str)).split(" ");
        std::string log = str_list[1].toStdString();
        std::string pas = str_list[2].toStdString();
        /*
        std::string log = mystr.substr(0,mystr.find(" "));
        std::string pas = mystr.substr(mystr.find(" ")+1,-1); */


        return auth(log,pas);
    }


    else if (mystr == "Reg") {
        mystr = str.toStdString().substr(str.toStdString().find(" ")+1, -1);
        QStringList str_list = (QString(str)).split(" ");

        std::string surname = str_list[1].toStdString();
        std::string name = str_list[2].toStdString();
        std::string lastname = str_list[3].toStdString();
        std::string login = str_list[4].toStdString();
        std::string password = str_list[5].toStdString();
        std::string email = str_list[6].toStdString();
        std::string group = str_list[7].toStdString();

        return reg(surname, name, lastname, login, password, email, group);
    }

    else if (mystr == "ShowStat") {
        mystr = str.trimmed().toStdString().substr(str.toStdString().find(" ")+1, -1);
        return showstat();
    }



    else if (mystr == "Tasks"){
        mystr = str.trimmed().toStdString().substr(str.toStdString().find(" ")+1, -1);
        std::string task = mystr;
        if (task == "1")
            return task1();
        else if (task == "2")
            return task2();
        else if (task == "3")
            return task3();
    }

    else if (mystr == "Check") {
        mystr = str.toStdString().substr(str.toStdString().find(" ")+1, -1);

        QStringList str_list = (QString(str)).split(" ");
        std::string task = str_list[1].toStdString();
        std::string variant = str_list[2].toStdString();
        std::string answer = str_list[3].toStdString();

        return check(task, variant, answer);
    }

    else if (mystr == "Exit") {
        return exit();
    }
    return "";
}

QByteArray auth(std::string login, std::string pass)
{
    //return QString::fromStdString((std::string)"Login: "+(login) + ", " + (std::string)"Password: " + pass).toUtf8();
    QString res = SingletonDataBase::getInstance()->queryToDB(QString::fromStdString("SELECT * FROM users  where user_login = \"" + login + "\""));

    qDebug()<<res;
    if (res!="")
        return QString::fromStdString((std::string)"auth+"+(login) + (std::string)"\r\n").toUtf8();
    else
        return "auth-\r\n";
}

QByteArray reg(std::string sname, std::string name, std::string lname, std::string log, std::string pas, std::string email, std::string group)
{
    //return QString::fromStdString((std::string)"FIO: "+ (sname) + " " + (name) + " " + (lname) + (std::string)", Login: " + (log) + (std::string)", Password: " + (pas)).toUtf8();
    std::string note_id = (SingletonDataBase::getInstance()->queryToDB(QString::fromStdString("SELECT note_id+1 FROM users ORDER BY note_id DESC LIMIT 1;"))).toStdString();
    note_id = note_id.substr(1,note_id.length()-2);
    SingletonDataBase::getInstance()->queryToDB(QString::fromStdString(
        "INSERT INTO "
        "users(note_id,user_socket,user_login,user_password,user_email,user_surname,user_name,user_patronymic,user_group,task_1,task_2,task_3)"
        "VALUES"
        "("+note_id+",0,'"+log+"','"+pas+"','"+email+"','"+sname+"','"+name+"','"+lname+"','"+group+"',0,0,0);"
                                                                       ));

    QString res = SingletonDataBase::getInstance()->queryToDB(QString::fromStdString("SELECT * FROM users where user_login = '"+log+"';"));
     qDebug()<<"Registration completed"<<res;

     QString res_auth = QString::fromUtf8(auth(log,pas));
    if(res_auth.left(5)=="auth+")
        return res_auth.toUtf8();

    return QString::fromStdString((std::string)"reg-"+(log) + (std::string)"\r\n").toUtf8();


}

QByteArray showstat()
{
    //return QString::fromStdString((std::string)"Statistics: for " + user + "\r\n").toUtf8();
    QString res = SingletonDataBase::getInstance()->queryToDB(QString::fromStdString("SELECT * FROM users"));
    if (res!="")
        return (QString("show " +res+" \r\n")).toUtf8();
    else
        return "-\r\n";
}

QByteArray task1()
{
    //return QString::fromStdString((std::string)"Statistics: for\r\n").toUtf8();
    //QString res = SingletonDataBase::getInstance()->queryToDB(QString::fromStdString("SELECT * FROM users"));
    QString res = "Задача 1. \r\n Построить цикл.";
    return (QString("task1 " + res +" \r\n")).toUtf8();

}

QByteArray task2()
{
    //return QString::fromStdString((std::string)"Statistics: for\r\n").toUtf8();
    QString res = "Задача 1. \r\n Поиск маршрута.";
    return (QString("task2 " + res +" \r\n")).toUtf8();
}


QByteArray task3()
{
    //return QString::fromStdString((std::string)"Statistics: for\r\n").toUtf8();
    QString res = "Задача 1. \r\n Построить цикл.";
    return (QString("task3 " + res +" \r\n")).toUtf8();
}


QByteArray check(std::string task, std::string variant, std::string answer)
{
    //check task# random_varian answer_from_user
    //if correct update stat in database +1, else -1
    //check+1 / check+0
    //return QString::fromStdString((std::string)"Tasks to svole" + "\r\n").toUtf8();

    QString res = SingletonDataBase::getInstance()->queryToDB(QString::fromStdString("SELECT task_result FROM users"));
    if (res!="")
        return "check+1\r\n";
    else
        return "check-1\r\n";
}


QByteArray exit()
{
    //return QString::fromStdString((std::string)"Goodbye!" + "\r\n").toUtf8();
    return "exit\r\n";

}

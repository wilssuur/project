#include "funcForServer.h"
#include <QString>
#include <QDebug>

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


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

    else if (mystr == "Stat") {
        mystr = str.trimmed().toStdString().substr(str.toStdString().find(" ")+1, -1);
        std::string login = mystr;


        return showstat(login);
    }


    else if (mystr == "Check1") {
        mystr = str.toStdString().substr(str.toStdString().find(" ")+1, -1);

        QStringList str_list = (QString(str)).split(" ");
        QString log = str_list.back();
        str_list.pop_back();
        QByteArray res = QByteArray::number(2*int(task1(str_list[1],str_list[2]))-1);
        qDebug() << log << "   " << log.toStdString();
        qDebug() << "UPDATE users SET task_1 = task_1 + ("+res.toStdString()+") WHERE user_login = '"+log.toStdString()+"'";
        SingletonDataBase::getInstance()->queryToDB(QString::fromStdString("UPDATE users SET task_1 = task_1 + ("+res.toStdString()+") WHERE user_login = '"+log.toStdString()+"'"));

        return "check " + res;
    }

    else if (mystr == "Check2") {
        mystr = str.toStdString().substr(str.toStdString().find(" ")+1, -1);

        QStringList str_list = (QString(str)).split(" ");
        QString log = str_list.back();
        str_list.pop_back();
        QByteArray res = QByteArray::number(2*int(task2(str_list[1],str_list[2]))-1);
        //qDebug() << log << "   " << log.toStdString();
        qDebug() << str_list[0] << " " << str_list[1];
        qDebug() << "UPDATE users SET task_1 = task_1 + ("+res.toStdString()+") WHERE user_login = '"+log.toStdString()+"'";
        SingletonDataBase::getInstance()->queryToDB(QString::fromStdString("UPDATE users SET task_1 = task_1 + ("+res.toStdString()+") WHERE user_login = '"+log.toStdString()+"'"));

        return "check " + res;
    }

    else if (mystr == "Check3") {
        mystr = str.toStdString().substr(str.toStdString().find(" ")+1, -1);

        QStringList str_list = (QString(str)).split(" ");
        QString log = str_list.back();
        str_list.pop_back();
        QByteArray res = QByteArray::number(2*int(task3(str_list[1],str_list[2]))-1);
        qDebug() << log << "   " << log.toStdString();
        qDebug() << "UPDATE users SET task_1 = task_1 + ("+res.toStdString()+") WHERE user_login = '"+log.toStdString()+"'";
        SingletonDataBase::getInstance()->queryToDB(QString::fromStdString("UPDATE users SET task_1 = task_1 + ("+res.toStdString()+") WHERE user_login = '"+log.toStdString()+"'"));

        return "check " + res;
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
    QString name = SingletonDataBase::getInstance()->queryToDB(QString::fromStdString("SELECT user_name FROM users  where user_login = \"" + login + "\""));
    QString surname = SingletonDataBase::getInstance()->queryToDB(QString::fromStdString("SELECT user_surname FROM users  where user_login = \"" + login + "\""));
    qDebug()<<res;
    //std::string result = (std::string)"auth+" + (login) + (std::string)"+" + (std::string)(name);

    if (res!="")
        //return QString::fromStdString(result).toUtf8();
        return QString::fromStdString((std::string)"auth+" + (login) + (std::string)"\r\n").toUtf8();
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

QByteArray showstat(std::string login)
{
    //return QString::fromStdString((std::string)"Statistics: for " + user + "\r\n").toUtf8();
    QString task1 = SingletonDataBase::getInstance()->queryToDB(QString::fromStdString("SELECT task_1 FROM users where user_login = '"+login+"';"));
    QString task2 = SingletonDataBase::getInstance()->queryToDB(QString::fromStdString("SELECT task_2 FROM users where user_login = '"+login+"';"));
    QString task3 = SingletonDataBase::getInstance()->queryToDB(QString::fromStdString("SELECT task_3 FROM users where user_login = '"+login+"';"));
    task1 = task1.trimmed();
    task2 = task2.trimmed();
    task3 = task3.trimmed();
    qDebug() << task1;
    if (task1 != "" and task2 != "" and task3 != "")
        return (QString("stat+" + task1 + "+" + task2 + "+" + task3 + "\r\n")).toUtf8();
    else
        return "stat-\r\n";
}



bool task1(QString task, QString user_answer)
{
    qDebug() << " task " << task << "answer" << user_answer;
    QStringList str_list = (QString(task)).split("+");
    std::string size = str_list[0].toStdString(); // количество вершин (одно число)
    std::string edges = str_list[1].toStdString(); // список ребер в формате (1,2),(1,4) - без пробелов

    return false;
}


bool task3(QString task, QString user_answer)
{
    qDebug() << " task " << task << "answer" << user_answer;
    QStringList str_list = (QString(task)).split("+");
    std::string size = str_list[0].toStdString(); // количество вершин (одно число)
    std::string edges = str_list[1].toStdString(); // список ребер в формате (1,2),(1,4) - без пробелов

    return true;
}



QByteArray exit()
{

    //return QString::fromStdString((std::string)"Goodbye!" + "\r\n").toUtf8();
    return "exit\r\n";

}


bool task2(QString task, QString user_answer)
{
    qDebug() << " task " << task << "answer" << user_answer;
    QStringList str_list = (QString(task)).split("+");
    std::string size = str_list[0].toStdString();
    std::string edges = str_list[1].toStdString();

    /*std::string qwe = str_list[1].toStdString();
    qDebug() << qwe;
    QStringList str_list2 = (QString::fromStdString(qwe)).split(").");
    qDebug() << str_list2[0];
    std::string edges = str_list[0].toStdString();


    QStringList one_edge = (QString::fromStdString(edges)).split("),(");

    qDebug() << "++++" << one_edge[0].toStdString() << " " << one_edge[1].toStdString();*/

    /*int size = tops.toInt();
    int matrix[size][size];
    for (int i = 0; i <= size; i ++){
        for (int j = 0; i <= size; j ++)
        matrix[i][j] = 0;
    }*/
    return true;
}

    /*QString server_answer;
    if (server_answer == user_answer)
        return true;
    else return false;*/


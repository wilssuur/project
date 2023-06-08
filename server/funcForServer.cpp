#include "funcForServer.h"
#include <QString>
#include <QDebug>
#include <iostream>

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <cassert>


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
        QByteArray res = QByteArray::number(2*int(task_1(str_list[1],str_list[2]))-1);
        //qDebug() << log << "   " << log.toStdString();
        qDebug() << QString::fromStdString("UPDATE users SET task_1 = task_1 + ("+res.toStdString()+") WHERE user_login = '"+log.toStdString()+"'");
        SingletonDataBase::getInstance()->queryToDB(QString::fromStdString("UPDATE users SET task_1 = task_1 + ("+res.toStdString()+") WHERE user_login = '"+log.toStdString()+"'"));

        return "check " + res;
    }

    else if (mystr == "Check2") {
        mystr = str.toStdString().substr(str.toStdString().find(" ")+1, -1);

        QStringList str_list = (QString(str)).split(" ");
        QString log = str_list.back();
        str_list.pop_back();
        QStringList task = (str_list[1]).split("+");

        std::string t = task[0].toStdString();
        std::string e = task[1].toStdString();

        int answer = task_2(QString::fromStdString(t), QString::fromStdString(e));
        int a = (str_list[2]).toInt();
        QByteArray res;
        if (answer == a) {
            res = QByteArray::number(2*int(true)-1);
        }
        else {
            res = QByteArray::number(2*int(false)-1);
        }
        //qDebug() << log << "   " << log.toStdString();
        qDebug() << str_list[0] << " " << str_list[1];
        qDebug() << QString::fromStdString("UPDATE users SET task_2 = task_2 + ("+res.toStdString()+") WHERE user_login = '"+log.toStdString()+"'");
        SingletonDataBase::getInstance()->queryToDB(QString::fromStdString("UPDATE users SET task_2 = task_2 + ("+res.toStdString()+") WHERE user_login = '"+log.toStdString()+"'"));
        //TestTask2();
        return "check " + res;
    }

    else if (mystr == "Check3") {
        mystr = str.toStdString().substr(str.toStdString().find(" ")+1, -1);

        QStringList str_list = (QString(str)).split(" ");
        QString log = str_list.back();
        str_list.pop_back();
        QStringList task = (str_list[1]).split("+");

        std::string t = task[0].toStdString();
        std::string e = task[1].toStdString();

        QString answer = task_3(QString::fromStdString(t), QString::fromStdString(e));
        QString a = str_list[2];
        QStringList ar = a.split(";");
        QString var;
        QByteArray res = QByteArray::number(2*int(false)-1);;
        foreach(var,ar){
            if (var == answer)
                res = QByteArray::number(2*int(true)-1);
        }
        qDebug() << str_list[0] << " " << str_list[1];
        qDebug() << QString::fromStdString("UPDATE users SET task_3 = task_3 + ("+res.toStdString()+") WHERE user_login = '"+log.toStdString()+"'");
        SingletonDataBase::getInstance()->queryToDB(QString::fromStdString("UPDATE users SET task_3 = task_3 + ("+res.toStdString()+") WHERE user_login = '"+log.toStdString()+"'"));
        //TestTask3;
        a = task_3("5", "(1,3),(1,5),(2,4),(2,5),(3,5),(4,5)");
        ar = a.split(";");
        QString vary;
        foreach(vary,ar){
            if (var == QString::fromStdString("1,5,4,2,5,3,1"))
                qDebug() << "TestTask1+" ;
        }

        a = task_3( "5","(1,2),(1,3),(2,3),(3,5),(3,4),(4,5)");
        ar = a.split(";");
        vary;
        foreach(vary,ar){
            if (var == QString::fromStdString("1,5,4,2,5,3,1"))
                qDebug() << "TestTask2+" ;
        }
        a = task_3( "5","(1,2),(1,3),(2,3),(3,5),(3,4),(4,5)");
        ar = a.split(";");
         vary;
        foreach(vary,ar){
            if (var == QString::fromStdString("1,3,5,4,3,2,1"))
                qDebug() << "TestTask3+" ;
        }
        a = task_3("7","(1,3),(1,4),(1,5),(1,7),(2,3),(2,6),(4,5),(6,7)");
        ar = a.split(";");
         vary;
        foreach(vary,ar){
            if (var == QString::fromStdString("1,5,4,1,7,6,2,3,1"))
                qDebug() << "TestTask4+" ;

        }
        a = task_3("8","(1,2),(1,4),(1,6),(1,8),(2,3),(2,5),(2,7),(3,4),(3,6),(3,8),(4,5),(4,7),(5,6),(5,8),(6,7),(7,8)");
        ar = a.split(";");
         vary;
        foreach(vary,ar){
            if (var == QString::fromStdString("1,8,7,6,5,4,7,2,5,8,3,6,1,4,3,2,1"))
                qDebug() << "TestTask5+" ;


        }
        return "check " + res;
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
        "("+note_id+",0,'"+log+"','"+pas+"','"+email+"','"+sname+"','"+name+"','"+lname+"','"+group+"',0,0,0);"));

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



bool task_1(QString task, QString user_answer)
{
    qDebug() << " task " << task << "answer" << user_answer;
    QStringList str_list = (QString(task)).split("+");
    std::string size = str_list[0].toStdString(); // количество вершин (одно число)
    std::string edges = str_list[1].toStdString(); // список ребер в формате (1,2),(1,4) - без пробелов

    return false;
}


QString task_3(QString tops, QString edges){
    QString  server_result;
    edges.resize(edges.size()-1);
    QStringList one_edge = (edges.remove(0,1).split("),("));
    int k = one_edge.size();
    //qDebug() << "one_edge"<< k;
    qDebug() << one_edge;
    int size = tops.toInt();
    int s = size + 1;
    QStringList vertexesedges;
    QStringList vertexes;
    for (int i = 1; i<s; i++){
        vertexes.append(QString::number(i));
    }
    qDebug() << vertexes << "vertexes";
    int topdeg[tops.toInt()];
    qDebug() << tops.toInt();

    for (int i = 0; i <= size; i++){
        topdeg[i] = 0;
    }

    qDebug() << size << "end";
    for (int i = 0; i < k; i ++){
        qDebug() << "works";
        QStringList list = (QString(one_edge[i])).split(",");
        //qDebug() << list;
        std::string edge1 = list[0].toStdString();
        std::string edge2 = list[1].toStdString();
        int e1  = QString::fromStdString(edge1).toInt();
        int e2 = QString::fromStdString(edge2).toInt();
        qDebug() << e1 << " " << e2 <<".";
        topdeg[e1-1] ++;
        topdeg[e2-1] ++;
        QString doublee;
        doublee.append(list[1]);
        doublee.append(",");
        doublee.append(list[0]);
        one_edge.append(doublee);
        vertexesedges.append(list[0]);
        vertexesedges.append(list[1]);
    }
    qDebug() << one_edge;
    int fl = 0;
    for (int i = 0; i < size; i++){
        qDebug() << topdeg[i];
        if (topdeg[i] % 2 == 0)
            continue;
        else
                fl = 1;
    }
   /*
    int counter = 0;
    for (int i = 0; i < size; i++){
        qDebug() << topdeg[i];
        if (topdeg[i] % 2 == 0)
            continue;
        else{
            if (counter > 1)
                fl = 1;
            else
                counter++;

        }
    }
    */
    qDebug() << "vert degs end";

    qDebug() << vertexesedges << "list of vertexes in edges";
    if (fl == 1){
        server_result = "-1";
        qDebug() << "not euler";
        return server_result;
    }
    qDebug() << "euler";

    qDebug() << "start";
    std::stack<int> stek;
    int w;
    int v=1;
    bool found_edge;
    /*
    if (counter !=0){
        for (int i = 0; i < size; i++){
            if (topdeg[i]%2==1){
                v = i+1;
                break;
            }

        }
    }
    */
    QString u;
    qDebug() << v << "first vertex";
    stek.push(v);
    while (stek.empty() == false){
        w = stek.top();
        qDebug() << w << "top vert";
        found_edge = false;
        //if ((vertexes.empty() == false)&& (one_edge.empty()==false)){
            foreach (u, vertexes){
                //qDebug() << "in foreach";
                QString elemE;
                elemE.append(QString::number(w));
                elemE.append(",");
                elemE.append(u);
                QString elemE2;
                elemE2.append(u);
                elemE2.append(",");
                elemE2.append(QString::number(w));
                //qDebug() << qPrintable(elemE);
                if ((one_edge.indexOf(elemE) != -1) or (one_edge.indexOf(elemE2) != -1)) {
                    //qDebug() << "in if";
                    if (one_edge.indexOf(elemE) != -1)
                        stek.push(u.toInt());
                    else
                        stek.push(w);
                    int index_vert = one_edge.indexOf(elemE);
                    //qDebug() << index_vert << "index of pair";
                    //if (index_vert != -1)
                        one_edge.removeAt(index_vert);
                    //if (vertexesedges.indexOf(u)!=-1)
                        vertexesedges.removeOne(u);
                    //if (vertexesedges.indexOf(QString::number(w))!=-1)
                        vertexesedges.removeOne(QString::number(w));
                    index_vert = one_edge.indexOf(elemE2);
                    //qDebug() << index_vert << "index of double pair";
                    //if (index_vert != -1)
                        one_edge.removeAt(index_vert);
                    qDebug() << one_edge;
                    found_edge = true;
                    break;
                }
            }
        //}
        if (found_edge == false){
            stek.pop();
            if (vertexesedges.indexOf(QString::number(w)) != -1){
                server_result.append(QString::number(w));
                server_result.append(",");
                int vertindex = vertexes.indexOf(QString::number(w));
                qDebug()<<vertexes.size();
                if (vertexes.size()!=1){
                    vertexes.removeAt(vertindex);
                    qDebug() << vertexes << "vertexes";
                    qDebug() << w;
                    qDebug() << "ans";
                }
                else{
                    qDebug() << w;
                    qDebug() << "ans last";
                    qDebug() << qUtf8Printable(server_result);
                    server_result.resize(server_result.size()-2);
                    qDebug() << qUtf8Printable(server_result);
                    //return server_result;
                }
            }
            else{
                qDebug() << w;
                qDebug() << "ans last";
                server_result.append(QString::number(w));
                server_result.append(",");
                continue;
            }
        }
    }
    server_result.resize(server_result.size()-1);
    qDebug() << qUtf8Printable(server_result);
    return server_result;
}




int task_2(QString tops, QString edges)
{
    /*qDebug() << " task " << task;
    QStringList str_list = (task).split("+");
    std::string tops = str_list[0].toStdString();
    std::string edges = str_list[1].toStdString();*/

    edges.resize(edges.size()-1);

    QStringList one_edge = ((edges.remove(0, 1))).split("),(");
    int k = one_edge.size();
    qDebug() << "one_edge"<< k;


    int size = tops.toInt();
    int s = size + 1;
    int matrix[size+1][size+1];
    for (int i = 0; i <= s; i ++){
        for (int j = 0; j <= s; j ++){
            matrix[i][j] = 0;
            matrix[j][i] = 0;
        }
    }

    qDebug() << size << "end";
    for (int i = 0; i < k; i ++){
        QStringList list = (QString(one_edge[i])).split(",");
        std::string edge1 = list[0].toStdString();
        std::string edge2 = list[1].toStdString();
        std::string weight = list[2].toStdString();
        int e1  = QString::fromStdString(edge1).toInt();
        int e2 = QString::fromStdString(edge2).toInt();
        int w = QString::fromStdString(weight).toInt();
        qDebug() << e1 << " " << e2 <<".";
        matrix[e1][e2] = w;
        matrix[e2][e1] = w;
    }
    for (int i = 0; i <= s; i++)
    {
        for (int j = 0; j < s; j++)
            qDebug() << matrix[i][j];
        qDebug() << " ";
    }
    int d[size+1]; // минимальное расстояние
    int v[size+1]; // посещенные вершины
    int begin_index = 1;
    int temp, minindex, min;
    //Инициализация вершин и расстояний
    for (int i = 0; i < s; i++)
    {
        d[i] = 10000;
        v[i] = 1;
    }
    d[begin_index] = 0;
    do {
        minindex = 10000;
        min = 10000;

        for (int i = 0; i < s; i++)
        { // Если вершину ещё не обошли и вес меньше min
            if ((v[i] == 1) and (d[i] < min))
            {
                min = d[i];
                minindex = i;
            }
        }

        if (minindex != 10000)
        {
            for (int i = 1; i < s; i++)
            {
                if (matrix[minindex][i] > 0)
                {
                    temp = min + matrix[minindex][i];
                    if (temp < d[i])
                    {
                        qDebug() << temp << " " << d[i];
                        d[i] = temp;
                    }
                }
            }
            v[minindex] = 0;
        }
    } while (minindex < 10000);

    qDebug() << d[s-1] << "result";
    int server_result = d[s-1];

    return server_result;
}

void TestTask2() {

    //assert(task_2("3", "(1,2,6),(2,3,2)") == 8);
    //assert(task_2("4", "(1,3,7),(1,2,3),(2,3,1),(2,4,9),(3,4,2)") == 6);
    //assert(task_2("4", "(1,3,1),(1,4,9),(2,3,1),(2,4,1),(3,4,8)") == 3);
    //assert(task_2("5", "(1,2,1),(1,3,9),(1,5,1),(2,3,1),(2,4,8),(2,5,1),(3,4,8),(4,5,5)") == 1);
    assert(task_2("5", "(1,4,2),(2,3,7),(2,4,9),(3,5,11),(4,5,5)") == 29);
    qDebug() << "TestTask2 OK";

}

void TestTask1() {

    assert(task_1("", "") == 0);
    qDebug() << "TestTask1 OK";

}

void TestTask3() {

    assert(task_3("5", "(1,3),(1,5),(2,4),(2,5),(3,5),(4,5)") == "1,3,5,2,4,5,1");
    qDebug() << "TestTask3 OK";

}

//TestTask2();
//qDebug() << task_3("6","(1,2),(1,5),(2,5),(2,3),(2,6),(3,6),(3,5),(3,4),(4,6),(5,6)");


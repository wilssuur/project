//Улучшенная реализация
#ifndef Singlton
#define Singlton
#include <QVariant> // 96 строка
#include <QDebug> // вывод в консоль
#include <QSqlDatabase> // для работы с бд
#include <QSqlQuery> // работа с запросами в бд
#include <QSqlError> // прописаны ошибки, которые могут возниикнуть при работе с бд
#include <QSqlRecord> // для работы с одной записью

class SingletonDataBase;

class SingletonDataBaseDestroyer
{
private:
    SingletonDataBase * p_instance;
public:
    ~SingletonDataBaseDestroyer() { delete p_instance; qDebug()<<"~SingletonDataBaseDestroyer"; }
    void initialize(SingletonDataBase * p){p_instance = p;};
};


class SingletonDataBase
{
private:
    static SingletonDataBase * p_instance;
    static SingletonDataBaseDestroyer destroyer;
    QSqlDatabase db =
        QSqlDatabase::addDatabase("QSQLITE");
protected:
    SingletonDataBase(){
        qDebug()<<"SingletonDataBase()\n";
        db.setDatabaseName("D:/MathLog/ClientSingleton/project/sqliteuser.db");
        //db.setDatabaseName("sqliteuser.db");

        if(!db.open())
            qDebug()<<db.lastError().text();
        else qDebug()<<"DB is open\n";
    }
    SingletonDataBase(const SingletonDataBase& ) = delete;
    SingletonDataBase& operator = (SingletonDataBase &) = delete;
    virtual ~SingletonDataBase()
    {
        db.close();
    }
    friend class SingletonDataBaseDestroyer;
public:
    static SingletonDataBase* getInstance(){
        if (!p_instance)
        {
            p_instance = new SingletonDataBase();
            destroyer.initialize(p_instance);
        }
        return p_instance;
    }

    QString queryToDB(QString mystrquery)
    {
        QSqlQuery query(db);

        //queryToDB.exec();
        query.exec(mystrquery);
        QSqlRecord rec = query.record();

        const int noteid = rec.indexOf("note_id");
        const int userid = rec.indexOf("user_id");
        const int login = rec.indexOf("user_login");
        const int password = rec.indexOf("user_password");
        const int email = rec.indexOf("user_email");
        const int surname = rec.indexOf("user_surname");
        const int name = rec.indexOf("user_name");
        const int patronymic = rec.indexOf("user_patronymic");
        const int group = rec.indexOf("user_group");
        const int taskid = rec.indexOf("task_id");
        const int taskres = rec.indexOf("task_result");

        QString res = "";
        while(query.next())
        {
            res.append(query.value(noteid).toString());
            res.append("\t").append(query.value(userid).toString());
            res.append("\t").append(query.value(userid).toString());
            res.append("\t").append(query.value(login).toString());
            res.append("\t").append(query.value(password).toString());
            res.append("\t").append(query.value(email).toString());
            res.append("\t").append(query.value(surname).toString());
            res.append("\t").append(query.value(name).toString());
            res.append("\t").append(query.value(patronymic).toString());
            res.append("\t").append(query.value(group).toString());
            res.append("\t").append(query.value(taskid).toString());
            res.append("\t").append(query.value(taskres).toString());
            res.append("\n");
        }
        //qDebug()<<res;
        return res;
    }

};


#endif

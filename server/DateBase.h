/**
 * @file SingletonDataBase.h
 * @brief Header file for SingletonDataBase class
 */
#ifndef Singlton
#define Singlton

#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

class SingletonDataBase;
/**
 * @class SingletonDataBaseDestroyer
 * @brief Helper class for destroying SingletonDataBase instance
 */
class SingletonDataBaseDestroyer
{
private:
    SingletonDataBase * p_instance; /**< Pointer to SingletonDataBase instance */
public:
    /**
     * @brief Destructor for SingletonDataBaseDestroyer
     */
    ~SingletonDataBaseDestroyer() {
        delete p_instance;
        qDebug() << "~SingletonDataBaseDestroyer";
    }
    /**
     * @brief Initializes the SingletonDataBase instance
     * @param p Pointer to SingletonDataBase instance
     */
    void initialize(SingletonDataBase * p) { p_instance = p; };
};

/**
 * @class SingletonDataBase
 * @brief Singleton class for database operations
 */
class SingletonDataBase
{
private:
    static SingletonDataBase * p_instance; /**< Pointer to SingletonDataBase instance */
    static SingletonDataBaseDestroyer destroyer; /**< Helper class for destroying SingletonDataBase instance */
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); /**< QSqlDatabase instance for database operations */
protected:
    /**
     * @brief Constructor for SingletonDataBase
     */
    SingletonDataBase() {
        qDebug() << "SingletonDataBase()\n";
        db.setDatabaseName("../server/sqliteuser.db"); // Set database name
        //db.setDatabaseName("sqliteuser.db");

        if(!db.open())
            qDebug() << db.lastError().text();
        else qDebug() << "DB is open\n";
    }
    SingletonDataBase(const SingletonDataBase& ) = delete; /**< Copy constructor for SingletonDataBase */
    SingletonDataBase& operator = (SingletonDataBase &) = delete; /**< Assignment operator for SingletonDataBase */
    /**
     * @brief Destructor for SingletonDataBase
     */
    virtual ~SingletonDataBase() {
        db.close();
    }
    friend class SingletonDataBaseDestroyer; /**< Friend class for SingletonDataBaseDestroyer */
public:
    /**
     * @brief Returns the SingletonDataBase instance
     * @return Pointer to SingletonDataBase instance
     */
    static SingletonDataBase* getInstance() {
        if (!p_instance) {
            p_instance = new SingletonDataBase();
            destroyer.initialize(p_instance);
        }
        return p_instance;
    }

    /**
     * @brief Executes a query on the database
     * @param mystrquery Query to be executed
     * @return Result of the query as a string
     */
    QString queryToDB(QString mystrquery) {
        QSqlQuery query(db);

        query.exec(mystrquery);
        QSqlRecord rec = query.record();
        QString res = "";
        int numofcols = rec.count();
        while(query.next()) {
            for(int i=0;i<numofcols;i++)
                res.append("\t").append(query.value(i).toString());

            res.append("\n");
        }
        return res;
    }
};
#endif

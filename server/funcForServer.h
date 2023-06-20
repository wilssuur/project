/**
 * @file FuncForServer.h
 * @brief Header file containing function declarations for server operations
 */
#ifndef FUNCFORSERVER_H
#define FUNCFORSERVER_H

#include <QByteArray>
#include <stack>
#include <string>
#include "DateBase.h" /**< Header file for database operations */

/**
 * @brief Parses the input string and returns the result as a QByteArray
 * @param str Input string to be parsed
 * @return Result of parsing as a QByteArray
 */
QByteArray parsing(QByteArray str);

/**
 * @brief Authenticates the user with the given login and password
 * @param login User login
 * @param pass User password
 * @return Result of authentication as a QByteArray
 */
QByteArray auth(std::string login, std::string pass);

/**
 * @brief Registers the user with the given details
 * @param sname User surname
 * @param name User name
 * @param lname User last name
 * @param log User login
 * @param pas User password
 * @param email User email
 * @param group User group
 * @return Result of registration as a QByteArray
 */
QByteArray reg(std::string sname, std::string name, std::string lname, std::string log, std::string pas, std::string email, std::string group);

/**
 * @brief Returns the statistics for the user with the given login
 * @param login User login
 * @return Statistics for the user as a QByteArray
 */
QByteArray showstat(std::string login);

/**
 * @brief Checks the answer for task 1 and returns the result as a QByteArray
 * @param answer User answer
 * @param variant Variant for task 1
 * @return Result of checking the answer as a QByteArray
 */

QString task_1(QString tops, QString edges);

/**
 * @brief Checks the answer for task 2 and returns the result as a QByteArray
 * @param answer User answer
 * @return Result of checking the answer as a QByteArray
 */
int task_2(QString tops, QString edges);

/**
 * @brief Checks the answer for task 3 and returns the result as a QByteArray
 * @param answer User answer
 * @return Result of checking the answer as a QByteArray
 */
QString task_3(QString tops, QString edges);

/**
 * @brief Checks the user's answer for a task and returns the result as a QByteArray
 * @param task Task number
 * @param variant Task variant
 * @param answer User answer
 * @return Result of checking the answer as a QByteArray
 */
QByteArray check(std::string task, std::string variant, std::string answer);

void TestTask1();
void TestTask2();
void TestTask3();

#endif // FUNCFORSERVER_H

/**
 * @file funcforclient.h
 * @brief Contains functions for the client application.
 */

#ifndef FUNCFORCLIENT_H
#define FUNCFORCLIENT_H

#include <QString>
#include <QByteArray>

/**
 * @brief Returns the variant for a given task number.
 *
 * This function takes in a task number and returns the corresponding variant as a QString.
 *
 * @param tasknumber The task number for which to get the variant.
 * @return The variant for the given task number as a QString.
 */
QString get_variant(int tasknumber);

#endif // FUNCFORCLIENT_H

//
// Created by Rahman  Yilmaz on 11/10/2022.
//

#ifndef PROJET_QT_BD_H
#define PROJET_QT_BD_H

#include <QObject>
#include <QtSql>
#include "../Contact/StdListContact.h"

class BD : public QObject
{
Q_OBJECT

public:
    explicit BD(QObject *parent = nullptr);

    static void addContactOnBD(StdListContact *lstContact);

    static StdListContact getData();

    static void addContactOnBD(const StdContact &contact);

    static void supContact(const StdContact &contact);

    static bool modifyContact(const StdContact &contact);

private:
    QSqlDatabase db;

    void addModif(long idContact, const std::string& modif);
};


#endif //PROJET_QT_BD_H

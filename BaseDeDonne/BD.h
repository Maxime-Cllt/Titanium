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

    static StdListContact getContactData();


    static void addContactOnBD(const StdContact &contact);

    static void supContact(const StdContact &contact);

    static bool modifyContact(const StdContact &contact);

    void addModif(uint64_t idContact, const std::string &modif);

    static void addInteraction(uint64_t idContact, const Interaction &);

    static void modifyInteraction(const Interaction &);

    static void supInteraction(const Interaction &);

private:
    static ListInteraction getListInteractionData(const uint64_t &idContact);

private:
    QSqlDatabase db;
};


#endif //PROJET_QT_BD_H

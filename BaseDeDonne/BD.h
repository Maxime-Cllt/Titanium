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

    static void addContactOnBD(StdListContact *);

    static void addFullContactAttributesOnBD(const StdListContact &);

    static StdListContact *getContactData();


    static void addContactOnBD(const StdContact &);

    static void supContact(const StdContact &);

    static bool modifyContact(const StdContact &);

    void addModif(uint64_t, const std::string &);

    static void addInteraction(uint64_t, const Interaction &);

    static void addInteraction(const ListInteraction &);

    static void modifyInteraction(const Interaction &);

    static void supInteraction(const Interaction &);

    static void addTache(uint64_t, const Tache &);

    static void addTache(const ListTache &);

    static void supTache(const Tache &);

private:
    static ListInteraction getListInteractionData(const uint64_t &idContact);

    static ListTache getListTacheData(const uint64_t &idInteraction);

private:
    QSqlDatabase db;
};


#endif //PROJET_QT_BD_H

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

    void addOnBD(StdListContact *lstContact);
    StdListContact getData();

private:
    QSqlDatabase db;

};


#endif //PROJET_QT_BD_H

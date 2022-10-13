//
// Created by Rahman  Yilmaz on 11/10/2022.
//

#include "BD.h"
#include <QFileInfo>
#include <QFile>
#include <QMessageBox>


BD::BD(QObject *parent) : QObject(parent)
{
    QString path("database.db");
    bool exist = QFileInfo::exists(path);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);

    if (!db.open())
    {
        qDebug() << "Erreur; impossible de se connecter à la base de donné.";
        exit(0);
    } else
    {
        qDebug() << "Database: connection ok";
    }

    if (!exist)
    {
        QSqlQuery query;
        query.exec("CREATE TABLE IF NOT EXISTS CONTACTS("
                   "Nom VARCHAR(255) not null,"
                   "Prenom VARCHAR(255) not null,"
                   "Entreprise VARCHAR(255) not null,"
                   "Mail VARCHAR(255) not null,"
                   "Telephone VARCHAR(10) not null,"
                   "Photo TEXT not null,"
                   "DateCreation INT not null"
                   ");");
    }
}

void BD::addOnBD(const StdContact &contact)
{

    QSqlQuery query;
    const QtContact qtContact(TraductionQtStd::StdFicheContacttoQtFicheContact(contact));
    const QString &nom(qtContact.getNom());
    const QString &prenom(qtContact.getPrenom());
    const QString &entreprise(qtContact.getEntreprise());
    const QString &mail(qtContact.getMail());
    const QString &telephone(qtContact.getTelephone());
    const QString &photo(qtContact.getPhoto());
    QString date;
    query.prepare("INSERT INTO CONTACTS (Nom, Prenom, Entreprise, Mail, Telephone, Photo, DateCreation) "
                  "VALUES (:nom, :prenom, :entreprise, :mail, :tel, :photo, :date)");
    date.setNum(contact.getDateCreation());
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":entreprise", entreprise);
    query.bindValue(":mail", mail);
    query.bindValue(":tel", telephone);
    query.bindValue(":photo", photo);
    query.bindValue(":date", date);
    query.exec();
}

void BD::addOnBD(StdListContact *stdListContact)
{
    for (const auto contact: *stdListContact->getLstContact())
        addOnBD(*contact);

}

StdListContact BD::getData()
{
    StdListContact lst;

    QSqlQuery query("SELECT * FROM CONTACTS");

    while (query.next())
    {
        QtContact qtContact;
        qtContact.setNom(query.value(0).toString());
        qtContact.setPrenom(query.value(1).toString());
        qtContact.setEntreprise(query.value(2).toString());
        qtContact.setMail(query.value(3).toString());
        qtContact.setTelephone(query.value(4).toString());
        qtContact.setPhoto(query.value(5).toString());

        StdContact contact(TraductionQtStd::QtFicheContactToStdFicheContact(qtContact));
        contact.setDateCreation(query.value(6).toLongLong());

        lst.addContact(contact);
    }
    return lst;
}

void BD::supContact(const StdContact &contact)
{

    QSqlQuery query;
    QString date;
    date.setNum(contact.getDateCreation());

    query.prepare("DELETE FROM CONTACTS WHERE ? = DateCreation");
    query.addBindValue(date);

    if (query.exec())
    {
        QMessageBox::information(nullptr, "Succes", "Le contact a été suprimé avec succes.");
    } else
    {
        QMessageBox::warning(nullptr, "Erreur", "Une erreur est survenue lors de la supression du contact.");
    }
}

bool BD::modifyContact(const StdContact &contact)
{
    QtContact qtContact(TraductionQtStd::StdFicheContacttoQtFicheContact(contact));

    QSqlQuery query;

    query.prepare("UPDATE CONTACTS SET "
                  "Nom = ? , "
                  "Prenom = ? , "
                  "Entreprise = ? , "
                  "Mail = ? , "
                  "Telephone = ? , "
                  "Photo = ? "
                  "WHERE ? = DateCreation");
    query.addBindValue(qtContact.getNom());
    query.addBindValue(qtContact.getPrenom());
    query.addBindValue(qtContact.getEntreprise());
    query.addBindValue(qtContact.getMail());
    query.addBindValue(qtContact.getTelephone());
    query.addBindValue(qtContact.getPhoto());
    QString dateCreation;
    dateCreation.setNum(qtContact.getDateCreation());
    query.addBindValue(dateCreation);

    if (query.exec())
    {
        int rep = QMessageBox::information(nullptr, "Information", "Le contact à été modifié avec succès.");
        if (rep == QMessageBox::Ok)
        {
            return true;
        }
    }
    return false;
}

//
// Created by Rahman  Yilmaz on 11/10/2022.
//

#include "BD.h"
#include <QFileInfo>
#include <QFile>
#include <QMessageBox>


/**
 * Constructeur de la classe BD pour la base de données de l'application
 * @param parent
 */
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
                   "DateCreation BIGINT not null"
                   ");");

        query.exec("CREATE TABLE IF NOT EXISTS MODIFICATIONS("
                   "IdContact BIGINT not null,"
                   "DateModification BIGINT not null,"
                   "Modification TEXT"
                   ");");

        query.exec("CREATE TABLE IF NOT EXISTS INTERACTIONS("
                   "IdContact BIGINT not null,"
                   "IdInteraction BIGINT not null,"
                   "DateModification BIGINT not null,"
                   "Contenu TEXT"
                   ");");
    }
}

/**
 * Ajoute un contact dans la base de données via un StdContact
 * @param contact
 */
void BD::addContactOnBD(const StdContact &contact)
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

/**
 * Ajoute un contact dans la base de données via une StdListContact
 * @param contact
 */
void BD::addContactOnBD(StdListContact *stdListContact)
{
    for (const auto contact: *stdListContact->getLstContact())
        addContactOnBD(*contact);

}

/**
 * Ajoute une modification d'un contact via son id et la modification
 * @param idContact
 * @param modif
 */
void BD::addModif(uint64_t idContact, const std::string &modif)
{
    QSqlQuery query("INSERT INTO MODIFICATIONS "
                    "(IdContact, DateModification,Modification) "
                    "VALUES (? , ? , ?)");
    query.addBindValue(QString::number(idContact));
    query.addBindValue(QString::fromStdString(modif));
    query.addBindValue("?");
}

/**
 * Retourne la liste des contacts de la table CONTACTS
 * @return lst
 */
StdListContact BD::getContactData()
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

        qtContact.setLstInteraction(getListInteractionData(query.value(6).toLongLong()));

        StdContact contact(TraductionQtStd::QtFicheContactToStdFicheContact(qtContact));
        contact.setDateCreation(query.value(6).toLongLong());

        lst.addContact(contact);
    }
    return lst;
}

/**
 * Supprimer un contact de la base de données
 * @param contact
 */
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

/**
 *  Modifier un contact de la base de données
 * @param contact
 * @return
 */
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

/**
 * Ajouter une interaction d'un contact dans la base de données
 * @param idContact
 * @param interaction
 */
void BD::addInteraction(uint64_t idContact, const Interaction &interaction)
{
    QSqlQuery query(
            "INSERT INTO INTERACTIONS (IdContact ,IdInteraction,DateModification, Contenu) VALUES ( ? , ? , ? , ?)");
    query.addBindValue(QString::number(idContact));
    query.addBindValue(QString::number(interaction.getId()));
    query.addBindValue(QString::number(interaction.getDateModif()));
    query.addBindValue(QString::fromStdString(interaction.getContenu()));
    query.exec();
}

/**
 * Supprimer une interaction d'un contact dans la base de données en fonction de son id
 * @param interaction
 */
void BD::supInteraction(const Interaction &interaction)
{
    QSqlQuery query("DELETE FROM INTERACTIONS WHERE ? = IdInteraction");
    query.addBindValue(QString::number(interaction.getId()));
    query.exec();
}

/**
 * Modifier l'interaction d'un contact dans la base de données
 * @param interaction
 */
void BD::modifyInteraction(const Interaction &interaction)
{
    QSqlQuery query("UPDATE INTERACTIONS SET Contenu = ?, DateModification = ? WHERE ? = IdInteraction");
    query.addBindValue(QString::fromStdString(interaction.getContenu()));
    query.addBindValue(QString::number(interaction.getDateModif()));
    query.addBindValue(QString::number(interaction.getId()));
    query.exec();
}

/**
 * Obtenir la liste des interactions d'un contact via son id
 * @param idContact
 * @return listInteraction
 */
ListInteraction BD::getListInteractionData(const uint64_t &idContact)
{
    QSqlQuery query("SELECT * FROM INTERACTIONS WHERE ? = IdContact");
    query.addBindValue(QString::number(idContact));

    ListInteraction listInteraction(idContact);

    query.exec();

    while (query.next())
    {
        Interaction interaction;

        interaction.setId(query.value(1).toLongLong());
        interaction.setDateModif(query.value(2).toLongLong());
        interaction.setContenu(query.value(3).toString().toStdString());
        listInteraction.addInteraction(interaction);
    }

    return listInteraction;
}

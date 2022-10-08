//
// Created by Rahman  Yilmaz on 22/09/2022.
//

#include "QtFicheContact.h"
#include "StdFicheContact.h"


QtFicheContact::QtFicheContact(const QString &nom, const QString &prenom, const QString &entreprise,
                               const QString &mail, const QString &telephone, const QString &photo,
                               const QDateTime &dateCreation, const QList<QString> &lstModif) : Nom(nom),
                                                                                                Prenom(prenom),
                                                                                                Entreprise(entreprise),
                                                                                                Mail(mail),
                                                                                                Telephone(telephone),
                                                                                                Photo(photo),
                                                                                                DateCreation(
                                                                                                        dateCreation),
                                                                                                lstModif(lstModif) {}

const QString &QtFicheContact::getNom() const
{
    return Nom;
}

void QtFicheContact::setNom(const QString &nom)
{
    Nom = nom;
}

const QString &QtFicheContact::getPrenom() const
{
    return Prenom;
}

void QtFicheContact::setPrenom(const QString &prenom)
{
    Prenom = prenom;
}

const QString &QtFicheContact::getEntreprise() const
{
    return Entreprise;
}

void QtFicheContact::setEntreprise(const QString &entreprise)
{
    Entreprise = entreprise;
}

const QString &QtFicheContact::getMail() const
{
    return Mail;
}

void QtFicheContact::setMail(const QString &mail)
{
    Mail = mail;
}

const QString &QtFicheContact::getTelephone() const
{
    return Telephone;
}

void QtFicheContact::setTelephone(const QString &telephone)
{
    Telephone = telephone;
}

const QString &QtFicheContact::getPhoto() const
{
    return Photo;
}

void QtFicheContact::setPhoto(const QString &photo)
{
    Photo = photo;
}

const QDateTime &QtFicheContact::getDateCreation() const
{
    return DateCreation;
}

void QtFicheContact::setDateCreation(const QDateTime &dateCreation)
{
    DateCreation = dateCreation;
}

QtFicheContact::QtFicheContact() {}

const QList<QString> &QtFicheContact::getLstModif() const
{
    return lstModif;
}

void QtFicheContact::setLstModif(const QList<QString> &lstModif)
{
    QtFicheContact::lstModif = lstModif;
}

StdFicheContact QtFicheContactToStdFicheContact(QtFicheContact &contact)
{
    date::year_month_day d(date::year(contact.getDateCreation().date().year()),
                           date::month(contact.getDateCreation().date().month()),
                           date::day(contact.getDateCreation().date().day()));

    std::list<std::string> lst;
    for (auto s: contact.getLstModif())
    {
        lst.push_back(s.toStdString());
    }

    return StdFicheContact(contact.getNom().toStdString(), contact.getPrenom().toStdString(),
                           contact.getEntreprise().toStdString(), contact.getMail().toStdString(),
                           contact.getTelephone().toStdString(), contact.getPhoto().toStdString(),
                           d, lst);
}

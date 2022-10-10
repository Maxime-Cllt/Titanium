//
// Created by Rahman  Yilmaz on 22/09/2022.
//

#include "QtContact.h"
#include "StdContact.h"


QtContact::QtContact(const QString &nom, const QString &prenom, const QString &entreprise, const QString &mail,
                     const QString &telephone, const QString &photo, const QDateTime &dateCreation,
                     const QList<Interaction *> &lstInteraction) : Nom(nom), Prenom(prenom), Entreprise(entreprise),
                                                                   Mail(mail), Telephone(telephone), Photo(photo),
                                                                   DateCreation(dateCreation),
                                                                   lstInteraction(lstInteraction) {}

const QString &QtContact::getNom() const
{
    return Nom;
}

void QtContact::setNom(const QString &nom)
{
    Nom = nom;
}

const QString &QtContact::getPrenom() const
{
    return Prenom;
}

void QtContact::setPrenom(const QString &prenom)
{
    Prenom = prenom;
}

const QString &QtContact::getEntreprise() const
{
    return Entreprise;
}

void QtContact::setEntreprise(const QString &entreprise)
{
    Entreprise = entreprise;
}

const QString &QtContact::getMail() const
{
    return Mail;
}

void QtContact::setMail(const QString &mail)
{
    Mail = mail;
}

const QString &QtContact::getTelephone() const
{
    return Telephone;
}

void QtContact::setTelephone(const QString &telephone)
{
    Telephone = telephone;
}

const QString &QtContact::getPhoto() const
{
    return Photo;
}

void QtContact::setPhoto(const QString &photo)
{
    Photo = photo;
}

const QDateTime &QtContact::getDateCreation() const
{
    return DateCreation;
}

void QtContact::setDateCreation(const QDateTime &dateCreation)
{
    DateCreation = dateCreation;
}

QtContact::QtContact() {}

const QList<Interaction *> QtContact::getLstInteraction() const
{
    return lstInteraction;
}

void QtContact::setLstInteraction(const QList<Interaction *> &lstInteraction)
{
    QtContact::lstInteraction = lstInteraction;
}

QList<Interaction *> *QtContact::getLstInteraction()
{
    return &lstInteraction;
}


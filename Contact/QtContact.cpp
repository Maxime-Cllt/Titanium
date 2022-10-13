//
// Created by Rahman  Yilmaz on 22/09/2022.
//
/*
*   Classe QtContact: Modelise un contact dans l'application
*
*/

#include "QtContact.h"
#include "StdContact.h"

//Constructeur principal de la classe QtContact
QtContact::QtContact(const QString &nom, const QString &prenom, const QString &entreprise, const QString &mail,
                     const QString &telephone, const QString &photo, const QDateTime &dateCreation,
                     const QList<Interaction *> &lstInteraction) : Nom(nom), Prenom(prenom), Entreprise(entreprise),
                                                                   Mail(mail), Telephone(telephone), Photo(photo),
                                                                   DateCreation(dateCreation),
                                                                   lstInteraction(lstInteraction) {}

//Getter de l'attribut Nom
const QString &QtContact::getNom() const {
    return Nom;
}

//Setter de l'attribut Nom
void QtContact::setNom(const QString &nom) {
    Nom = nom;
}

//Getter de l'attribut Prenom
const QString &QtContact::getPrenom() const {
    return Prenom;
}

//Setter de l'attribut Prenom
void QtContact::setPrenom(const QString &prenom) {
    Prenom = prenom;
}

//Getter de l'attribut Entreprise
const QString &QtContact::getEntreprise() const {
    return Entreprise;
}

//Setter de l'attribut Entreprise
void QtContact::setEntreprise(const QString &entreprise) {
    Entreprise = entreprise;
}

//Getter de l'attribut Mail
const QString &QtContact::getMail() const {
    return Mail;
}

//Setter de l'attribut Mail
void QtContact::setMail(const QString &mail) {
    Mail = mail;
}

//Getter de l'attribut Telephone
const QString &QtContact::getTelephone() const {
    return Telephone;
}

//Setter de l'attribut Telephone
void QtContact::setTelephone(const QString &telephone) {
    Telephone = telephone;
}

//Getter de l'attribut Photo
const QString &QtContact::getPhoto() const {
    return Photo;
}

//Setter de l'attribut Photo
void QtContact::setPhoto(const QString &photo) {
    Photo = photo;
}

//Getter de l'attribut DateCreation
const QDateTime &QtContact::getDateCreation() const {
    return DateCreation;
}

//Setter de l'attribut DateCreation
void QtContact::setDateCreation(const QDateTime &dateCreation) {
    DateCreation = dateCreation;
}

//Constructeur par défaut de la classe QtContact
QtContact::QtContact() {}

//Getter de l'attribut lstInteraction
const QList<Interaction *> QtContact::getLstInteraction() const {
    return lstInteraction;
}

//Setter de l'attribut lstInteraction
void QtContact::setLstInteraction(const QList<Interaction *> &lstInteraction) {
    QtContact::lstInteraction = lstInteraction;
}

//Getter de l'attribut lstInteraction
QList<Interaction *> *QtContact::getLstInteraction() {
    return &lstInteraction;
}


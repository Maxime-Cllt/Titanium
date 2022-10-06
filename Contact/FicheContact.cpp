//
// Created by Rahman  Yilmaz on 22/09/2022.
//

#include "FicheContact.h"

const QString &FicheContact::getNom() const {
    return Nom;
}

void FicheContact::setNom(const QString &nom) {
    Nom = nom;
}

const QString &FicheContact::getPrenom() const {
    return Prenom;
}

void FicheContact::setPrenom(const QString &prenom) {
    Prenom = prenom;
}

const QString &FicheContact::getEntreprise() const {
    return Entreprise;
}

void FicheContact::setEntreprise(const QString &entreprise) {
    Entreprise = entreprise;
}

const QString &FicheContact::getMail() const {
    return Mail;
}

void FicheContact::setMail(const QString &mail) {
    Mail = mail;
}

const QString &FicheContact::getTelephone() const {
    return Telephone;
}

void FicheContact::setTelephone(const QString &telephone) {
    Telephone = telephone;
}

const QString &FicheContact::getPhoto() const {
    return Photo;
}

void FicheContact::setPhoto(const QString &photo) {
    Photo = photo;
}

const QDateTime &FicheContact::getDateCreation() const {
    return DateCreation;
}

void FicheContact::setDateCreation(const QDateTime &dateCreation) {
    DateCreation = dateCreation;
}

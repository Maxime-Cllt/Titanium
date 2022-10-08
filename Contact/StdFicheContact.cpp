//
// Created by Rahman  Yilmaz on 07/10/2022.
//

#include "StdFicheContact.h"
#include "QtFicheContact.h"


StdFicheContact::StdFicheContact(const std::string &nom, const std::string &prenom, const std::string &entreprise,
                                 const std::string &mail, const std::string &telephone, const std::string &photo,
                                 const date::year_month_day &dateCreation, const std::list<std::string> &lstModif)
        : Nom(nom), Prenom(prenom), Entreprise(entreprise), Mail(mail), Telephone(telephone), Photo(photo),
          DateCreation(dateCreation), lstModif(lstModif)
{}

StdFicheContact::StdFicheContact()
{}


const std::string &StdFicheContact::getNom() const
{
    return Nom;
}

void StdFicheContact::setNom(const std::string &nom)
{
    Nom = nom;
}

const std::string &StdFicheContact::getPrenom() const
{
    return Prenom;
}

void StdFicheContact::setPrenom(const std::string &prenom)
{
    Prenom = prenom;
}

const std::string &StdFicheContact::getEntreprise() const
{
    return Entreprise;
}

void StdFicheContact::setEntreprise(const std::string &entreprise)
{
    Entreprise = entreprise;
}

const std::string &StdFicheContact::getMail() const
{
    return Mail;
}

void StdFicheContact::setMail(const std::string &mail)
{
    Mail = mail;
}

const std::string &StdFicheContact::getTelephone() const
{
    return Telephone;
}

void StdFicheContact::setTelephone(const std::string &telephone)
{
    Telephone = telephone;
}

const std::string &StdFicheContact::getPhoto() const
{
    return Photo;
}

void StdFicheContact::setPhoto(const std::string &photo)
{
    Photo = photo;
}

const date::year_month_day &StdFicheContact::getDateCreation() const
{
    return DateCreation;
}

void StdFicheContact::setDateCreation(const date::year_month_day &dateCreation)
{
    DateCreation = dateCreation;
}

const std::list<std::string> &StdFicheContact::getLstModif() const
{
    return lstModif;
}

void StdFicheContact::setLstModif(const std::list<std::string> &lstModif)
{
    StdFicheContact::lstModif = lstModif;
}

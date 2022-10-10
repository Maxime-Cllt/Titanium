//
// Created by Rahman  Yilmaz on 07/10/2022.
//

#include "StdContact.h"
#include "QtContact.h"


StdContact::StdContact(const std::string &nom, const std::string &prenom, const std::string &entreprise,
                       const std::string &mail, const std::string &telephone, const std::string &photo,
                       const time_t &dateCreation, const std::list<Interaction> &lstInteraction) : Nom(
        nom), Prenom(prenom), Entreprise(entreprise), Mail(mail), Telephone(telephone), Photo(photo), DateCreation(
        dateCreation), lstInteraction(lstInteraction)
{}

StdContact::StdContact()
{}


const std::string &StdContact::getNom() const
{
    return Nom;
}

void StdContact::setNom(const std::string &nom)
{
    Nom = nom;
}

const std::string &StdContact::getPrenom() const
{
    return Prenom;
}

void StdContact::setPrenom(const std::string &prenom)
{
    Prenom = prenom;
}

const std::string &StdContact::getEntreprise() const
{
    return Entreprise;
}

void StdContact::setEntreprise(const std::string &entreprise)
{
    Entreprise = entreprise;
}

const std::string &StdContact::getMail() const
{
    return Mail;
}

void StdContact::setMail(const std::string &mail)
{
    Mail = mail;
}

const std::string &StdContact::getTelephone() const
{
    return Telephone;
}

void StdContact::setTelephone(const std::string &telephone)
{
    Telephone = telephone;
}

const std::string &StdContact::getPhoto() const
{
    return Photo;
}

void StdContact::setPhoto(const std::string &photo)
{
    Photo = photo;
}

const time_t &StdContact::getDateCreation() const
{
    return DateCreation;
}

void StdContact::setDateCreation(const time_t &dateCreation)
{
    DateCreation = dateCreation;
}

const std::list<Interaction> &StdContact::getLstInteraction() const
{
    return lstInteraction;
}

void StdContact::setlstInteraction(const std::list<Interaction> &lstInteraction)
{
    StdContact::lstInteraction = lstInteraction;
}

std::ostream &operator<<(std::ostream &os, const StdContact &contact)
{
    os << "Nom : " << contact.getNom() << " Prenom : " << contact.getPrenom() << " Entreprise : "
       << contact.getEntreprise() << " Telephone : " << contact.getTelephone() << " Mail : " << contact.getMail();
    return os;
}



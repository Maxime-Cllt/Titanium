//
// Created by Rahman  Yilmaz on 07/10/2022.
//

#include "StdContact.h"
#include "QtContact.h"

//Constructeur de StdContact
StdContact::StdContact(const std::string &nom, const std::string &prenom, const std::string &entreprise,
                       const std::string &mail, const std::string &telephone, const std::string &photo,
                       const time_t &dateCreation, const std::list<Interaction *> &lstInteraction) : Nom(
        nom), Prenom(prenom), Entreprise(entreprise), Mail(mail), Telephone(telephone), Photo(photo), DateCreation(
        dateCreation), lstInteraction(lstInteraction) {}

//Constructeur de StdContact par defaut
StdContact::StdContact() {}


//Getter de l'attribut Nom
const std::string &StdContact::getNom() const
{
    return Nom;
}
//Setter de l'attribut Nom
void StdContact::setNom(const std::string &nom)
{
    Nom = nom;
}
//Getter de l'attribut Prenom
const std::string &StdContact::getPrenom() const
{
    return Prenom;
}
//Setter de l'attribut Prenom
void StdContact::setPrenom(const std::string &prenom)
{
    Prenom = prenom;
}
//Getter de l'attribut Entreprise
const std::string &StdContact::getEntreprise() const
{
    return Entreprise;
}
//Setter de l'attribut Entreprise
void StdContact::setEntreprise(const std::string &entreprise)
{
    Entreprise = entreprise;
}
//Getter de l'attribut Mail
const std::string &StdContact::getMail() const
{
    return Mail;
}
//Setter de l'attribut Mail
void StdContact::setMail(const std::string &mail)
{
    Mail = mail;
}
//Getter de l'attribut Telephone
const std::string &StdContact::getTelephone() const
{
    return Telephone;
}
//Setter de l'attribut Telephone
void StdContact::setTelephone(const std::string &telephone)
{
    Telephone = telephone;
}
//Getter de l'attribut Photo
const std::string &StdContact::getPhoto() const
{
    return Photo;
}
//Setter de l'attribut photo
void StdContact::setPhoto(const std::string &photo)
{
    Photo = photo;
}
//Getter de l'attribut DateCreation
const time_t &StdContact::getDateCreation() const
{
    return DateCreation;
}
//Setter de l'attribut dateCreation
void StdContact::setDateCreation(const time_t &dateCreation)
{
    DateCreation = dateCreation;
}
//Getter de l'attribut lstInteraction
const std::list<Interaction *> &StdContact::getLstInteraction() const
{
    return lstInteraction;
}
//Setter de l'attribut lstInteraction
void StdContact::setlstInteraction(const std::list<Interaction *> &lstInteraction)
{
    StdContact::lstInteraction = lstInteraction;
}

std::ostream &operator<<(std::ostream &os, const StdContact &contact)
{
    os << "Nom : " << contact.getNom() << " Prenom : " << contact.getPrenom() << " Entreprise : "
       << contact.getEntreprise() << " Telephone : " << contact.getTelephone() << " Mail : " << contact.getMail();
    return os;
}
//Methode pour ajouter une interaction
void StdContact::addInteraction(const Interaction &interaction)
{
    lstInteraction.push_back(new Interaction(interaction));

}
//Destructeur de StdContact
StdContact::~StdContact()
{
    for (auto interaction: lstInteraction)
    {
        delete interaction;
    }

}
//Getter de l'attribut lstInteraction
std::list<Interaction *> *StdContact::getLstInteraction()
{
    return &lstInteraction;
}



//
// Created by Rahman  Yilmaz on 07/10/2022.
//


#include "StdContact.h"
#include "QtContact.h"

/**
 * Constructeur de la classe StdContact
 * @param nom
 * @param prenom
 * @param entreprise
 * @param mail
 * @param telephone
 * @param photo
 * @param dateCreation
 * @param lstInteraction
 */
StdContact::StdContact(const std::string &nom, const std::string &prenom, const std::string &entreprise,
                       const std::string &mail, const std::string &telephone, const std::string &photo,
                       const uint64_t &dateCreation, const ListInteraction &lstInteraction) : Nom(nom), Prenom(prenom),
                                                                                              Entreprise(entreprise),
                                                                                              Mail(mail),
                                                                                              Telephone(telephone),
                                                                                              Photo(photo),
                                                                                              DateCreation(
                                                                                                      dateCreation),
                                                                                              lstInteraction(
                                                                                                      new ListInteraction(
                                                                                                              lstInteraction))
{
}

/**
 * @details getter de Nom
 * @return Nom du Contact
 */
const std::string &StdContact::getNom() const
{
    return Nom;
}

/**
 * @details setter de Nom
 * @param Nom du Contact
 */
void StdContact::setNom(const std::string &nom)
{
    Nom = nom;
}

/**
 * @details getter de Prenom
 * @return Prenom du Contact
 */
const std::string &StdContact::getPrenom() const
{
    return Prenom;
}

/**
 * @details setter de Prenom
 * @param Prenom du Contact
 */
void StdContact::setPrenom(const std::string &prenom)
{
    Prenom = prenom;
}

/**
 * @details getter de Entreprise
 * @return Entreprise du Contact
 */
const std::string &StdContact::getEntreprise() const
{
    return Entreprise;
}

/**
 * @details setter de Entreprise
 * @param entreprise du Contact
 */
void StdContact::setEntreprise(const std::string &entreprise)
{
    Entreprise = entreprise;
}

/**
 * @details getter de Mail
 * @return Mail du Contact
 */
const std::string &StdContact::getMail() const
{
    return Mail;
}

/**
 * @details setter de Mail
 * @param mail du Contact
 */
void StdContact::setMail(const std::string &mail)
{
    Mail = mail;
}

/**
 * @details getter de Telephone
 * @return Telephone du Contact
 */
const std::string &StdContact::getTelephone() const
{
    return Telephone;
}

/**
 * @details setter de Telephone
 * @param telephone du Contact
 */
void StdContact::setTelephone(const std::string &telephone)
{
    Telephone = telephone;
}

/**
 * @details getter de Photo
 * @return Photo du Contact
 */
const std::string &StdContact::getPhoto() const
{
    return Photo;
}

/**
 * @details setter de Photo
 * @param photo du Contact
 */
void StdContact::setPhoto(const std::string &photo)
{
    Photo = photo;
}

/**
 * @details getter de DateCreation
 * @return DateCreation du Contact
 */
const uint64_t &StdContact::getDateCreation() const
{
    return DateCreation;
}

/**
 * @details setter de lstInteraction
 * @param dateCreation du StdContact
 */
void StdContact::setDateCreation(const uint64_t &dateCreation)
{
    DateCreation = dateCreation;
}

/**
 * @details getter de lstInteraction
 * @return le contenu de lstInteraction du contact
 */
const ListInteraction &StdContact::getLstInteraction() const
{
    return *lstInteraction;
}

/**
 * @details setter de lstInteraction
 * @param lstInteraction du Contact
 */
void StdContact::setlstInteraction(const ListInteraction &lstInteraction)
{
    this->lstInteraction = new ListInteraction(lstInteraction);
}

/**
 * @details surcharge de l'operateur << pour faire l'affichage de l'objet StdContact.
 * @param os
 * @param contact
 * @return os
 */
std::ostream &operator<<(std::ostream &os, const StdContact &contact)
{
    os << "Nom : " << contact.getNom() << " Prenom : " << contact.getPrenom() << " Entreprise : "
       << contact.getEntreprise() << " Telephone : " << contact.getTelephone() << " Mail : " << contact.getMail();
    return os;
}

/**
 * @details Ajoute à la liste dse interactions du contact une nouvelle interaction.
 * @param interaction du Contact
 */
void StdContact::addInteraction(const Interaction &interaction)
{
    lstInteraction->addInteraction(interaction);

}

/**
 * @return Destructeur du StdContact
 */
StdContact::~StdContact()
{
    delete lstInteraction;
}

/**
 * @details getter de lstInteraction
 * @return lstInteraction du Contact
 */
ListInteraction *StdContact::getLstInteraction()
{
    return lstInteraction;
}

/**
 * @details constructeur par defaut
 */
StdContact::StdContact() : lstInteraction(new ListInteraction(getDateCreation()))
{
}

/**
 * @details setter de lstInteraction avec un pointeur de ListInteraction en parametre.
 * @param lstInteraction du StdContact
 */
void StdContact::setlstInteraction(ListInteraction *lstInteraction)
{
    setlstInteraction(*lstInteraction);
}

/**
 * @details surcharge operateur < qui compare les dates de creation des 2 StdContact.
 * @param rhs
 * @return
 */
bool StdContact::operator<(const StdContact &rhs) const
{
    return DateCreation < rhs.DateCreation;
}

/**
 * @details surcharge operateur >.
 * @param rhs
 * @return
 */
bool StdContact::operator>(const StdContact &rhs) const
{
    return rhs < *this;
}

/**
 * @details surcharge operateur <=.
 * @param rhs
 * @return
 */
bool StdContact::operator<=(const StdContact &rhs) const
{
    return !(rhs < *this);
}

/**
 * @details surcharge operateur >=.
 * @param rhs
 * @return
 */
bool StdContact::operator>=(const StdContact &rhs) const
{
    return !(*this < rhs);
}

/**
 * @details constructeur par copie.
 * @param contact
 */
StdContact::StdContact(const StdContact &contact)
{
    setNom(contact.getNom());
    setPrenom(contact.getPrenom());
    setEntreprise(contact.getEntreprise());
    setMail(contact.getMail());
    setTelephone(contact.getTelephone());
    setPhoto(contact.getPhoto());
    setDateCreation(contact.getDateCreation());
    setlstInteraction(contact.getLstInteraction());
}


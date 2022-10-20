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
 *
 * @return Nom du StdContact
 */
const std::string &StdContact::getNom() const
{
    return Nom;
}

/**
 *
 * @param Nom du StdContact
 */
void StdContact::setNom(const std::string &nom)
{
    Nom = nom;
}

/**
 *
 * @return Prenom du StdContact
 */
const std::string &StdContact::getPrenom() const
{
    return Prenom;
}

/**
 *
 * @param Prenom du StdContact
 */
void StdContact::setPrenom(const std::string &prenom)
{
    Prenom = prenom;
}

/**
 *
 * @return Entreprise du StdContact
 */
const std::string &StdContact::getEntreprise() const
{
    return Entreprise;
}

/**
 *
 * @param entreprise du StdContact
 */
void StdContact::setEntreprise(const std::string &entreprise)
{
    Entreprise = entreprise;
}

/**
 *
 * @return Mail du StdContact
 */
const std::string &StdContact::getMail() const
{
    return Mail;
}

/**
 *
 * @param mail du StdContact
 */
void StdContact::setMail(const std::string &mail)
{
    Mail = mail;
}

/**
 *
 * @return Telephone du StdContact
 */
const std::string &StdContact::getTelephone() const
{
    return Telephone;
}

/**
 *
 * @param telephone du StdContact
 */
void StdContact::setTelephone(const std::string &telephone)
{
    Telephone = telephone;
}

/**
 *
 * @return Photo du StdContact
 */
const std::string &StdContact::getPhoto() const
{
    return Photo;
}

/**
 *
 * @param photo du StdContact
 */
void StdContact::setPhoto(const std::string &photo)
{
    Photo = photo;
}

/**
 *
 * @return DateCreation du StdContact
 */
const uint64_t &StdContact::getDateCreation() const
{
    return DateCreation;
}

/**
 *
 * @param dateCreation du StdContact
 */
void StdContact::setDateCreation(const uint64_t &dateCreation)
{
    DateCreation = dateCreation;
}

/**
 *
 * @return lstInteraction du StdContact
 */
const ListInteraction &StdContact::getLstInteraction() const
{
    return *lstInteraction;
}

/**
 *
 * @param lstInteraction du StdContact
 */
void StdContact::setlstInteraction(const ListInteraction &lstInteraction)
{
    this->lstInteraction = new ListInteraction(lstInteraction);
}

/**
 *
 * @param os
 * @param contact
 * @return
 */
std::ostream &operator<<(std::ostream &os, const StdContact &contact)
{
    os << "Nom : " << contact.getNom() << " Prenom : " << contact.getPrenom() << " Entreprise : "
       << contact.getEntreprise() << " Telephone : " << contact.getTelephone() << " Mail : " << contact.getMail();
    return os;
}

/**
 *
 * @param interaction du StdContact
 */
void StdContact::addInteraction(const Interaction &interaction)
{
    lstInteraction->addInteraction(new Interaction(interaction));

}

/**
 * @return Destructeur du StdContact
 */
StdContact::~StdContact() {}

/**
 *
 * @return lstInteraction du StdContact
 */
ListInteraction *StdContact::getLstInteraction()
{
    return lstInteraction;
}

/**
 * @param lstInteraction du StdContact
 */
StdContact::StdContact() : lstInteraction(new ListInteraction(getDateCreation()))
{
}

/**
 *
 * @param lstInteraction du StdContact
 */
void StdContact::setlstInteraction(ListInteraction *lstInteraction)
{
    StdContact::lstInteraction = lstInteraction;
}

bool StdContact::operator<(const StdContact &rhs) const
{
    return DateCreation < rhs.DateCreation;
}

bool StdContact::operator>(const StdContact &rhs) const
{
    return rhs < *this;
}

bool StdContact::operator<=(const StdContact &rhs) const
{
    return !(rhs < *this);
}

bool StdContact::operator>=(const StdContact &rhs) const
{
    return !(*this < rhs);
}


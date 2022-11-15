//
// Created by Rahman  Yilmaz on 07/10/2022.
//


#include "StdContact.h"

#include <utility>
#include <chrono>
#include "QtContact.h"

/**
 * @details Constructeur de la classe StdContact.
 * @param nom
 * @param prenom
 * @param entreprise
 * @param mail
 * @param telephone
 * @param photo
 * @param dateCreation
 * @param lstInteraction
 */
StdContact::StdContact(std::string nom, std::string prenom, std::string entreprise,
                       std::string mail, std::string telephone, std::string photo,
                       const uint64_t &dateCreation, const ListInteraction &lstInteraction) : nom(std::move(nom)),
                                                                                              prenom(std::move(prenom)),
                                                                                              entreprise(std::move(
                                                                                                      entreprise)),
                                                                                              mail(std::move(mail)),
                                                                                              telephone(std::move(
                                                                                                      telephone)),
                                                                                              photo(std::move(photo)),
                                                                                              dateCreation(
                                                                                                      dateCreation),
                                                                                              lstInteraction(
                                                                                                      new ListInteraction(
                                                                                                              lstInteraction))
{
}

/**
 * @details Getter de  nom.
 * @return Nom du Contact
 */
const std::string &StdContact::getNom() const
{
    return nom;
}

/**
 * @details Setter de nom.
 * @param Nom du Contact
 */
void StdContact::setNom(const std::string &nom)
{
    StdContact::nom = nom;
}

/**
 * @details Getter de prenom.
 * @return Prénom du Contact
 */
const std::string &StdContact::getPrenom() const
{
    return prenom;
}

/**
 * @details Setter de prénom.
 * @param Prénom du Contact
 */
void StdContact::setPrenom(const std::string &prenom)
{
    StdContact::prenom = prenom;
}

/**
 * @details Getter de l'entreprise.
 * @return Entreprise du Contact
 */
const std::string &StdContact::getEntreprise() const
{
    return entreprise;
}

/**
 * @details Setter de l'entreprise.
 * @param entreprise du Contact
 */
void StdContact::setEntreprise(const std::string &entreprise)
{
    StdContact::entreprise = entreprise;
}

/**
 * @details Getter de mail.
 * @return Mail du Contact
 */
const std::string &StdContact::getMail() const
{
    return mail;
}

/**
 * @details Setter de mail.
 * @param mail du Contact
 */
void StdContact::setMail(const std::string &mail)
{
    StdContact::mail = mail;
}

/**
 * @details Getter de telephone.
 * @return Telephone du Contact
 */
const std::string &StdContact::getTelephone() const
{
    return telephone;
}

/**
 * @details Setter de telephone.
 * @param telephone du Contact
 */
void StdContact::setTelephone(const std::string &telephone)
{
    StdContact::telephone = telephone;
}

/**
 * @details Getter de photo.
 * @return Photo du Contact
 */
const std::string &StdContact::getPhoto() const
{
    return photo;
}

/**
 * @details Setter de photo.
 * @param photo du Contact
 */
void StdContact::setPhoto(const std::string &photo)
{
    StdContact::photo = photo;
}

/**
 * @details Getter de dateCreation.
 * @return DateCreation du Contact
 */
const uint64_t &StdContact::getDateCreation() const
{
    return dateCreation;
}

/**
 * @details Setter de dateCreation.
 * @param dateCreation du StdContact
 */
void StdContact::setDateCreation(const uint64_t &dateCreation)
{
    StdContact::dateCreation = dateCreation;
}

/**
 * @details Setter de la liste des interactions.
 * @param lstInteraction du Contact
 */
void StdContact::setlstInteraction(const ListInteraction &lstInteraction)
{
    StdContact::lstInteraction = new ListInteraction(lstInteraction);
    StdContact::lstInteraction->setidContact(dateCreation);
}

/**
 * @details Getter de la liste des interactions.
 * @return lstInteraction du Contact
 */
ListInteraction *StdContact::getLstInteraction() const
{
    return lstInteraction;
}

/**
 * @details Surcharge de l'operateur << pour faire l'affichage de l'objet StdContact.
 * @param os
 * @param contact
 * @return os
 */
std::ostream &operator<<(std::ostream &os, const StdContact &contact)
{
    os << "Nom: " << contact.getNom() << " Prenom: " << contact.getPrenom() << " Entreprise: "
       << contact.getEntreprise() << " Telephone: " << contact.getTelephone() << " Mail: " << contact.getMail()
       << " DateCreation: " << contact.getDateCreation();
    return os;
}

/**
 * @details Ajoute à la liste des interactions du contact une nouvelle interaction.
 * @param interaction du Contact
 */
void StdContact::addInteraction(const Interaction &interaction)
{
    lstInteraction->addInteraction(interaction);

}

/**
 * @details Destructeur du StdContact.
 */
StdContact::~StdContact()
{
    delete lstInteraction;
}


/**
 * @details Constructeur par défaut
 */
StdContact::StdContact() : lstInteraction(new ListInteraction(getDateCreation()))
{
    dateCreation = std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
}

/**
 * @details Setter de lstInteraction.
 * @param lstInteraction du StdContact
 */
void StdContact::setlstInteraction(ListInteraction *lstInteraction)
{
    StdContact::lstInteraction = lstInteraction;
    lstInteraction->setidContact(dateCreation);
}

/**
 * @details Surcharge opérateur < qui compare les dates de creation des 2 StdContact.
 * @param rhs
 * @return
 */
bool StdContact::operator<(const StdContact &rhs) const
{
    return dateCreation < rhs.dateCreation;
}

/**
 * @details Surcharge opérateur >.
 * @param rhs
 * @return
 */
bool StdContact::operator>(const StdContact &rhs) const
{
    return rhs < *this;
}

/**
 * @details Surcharge opérateur <=.
 * @param rhs
 * @return
 */
bool StdContact::operator<=(const StdContact &rhs) const
{
    return !(rhs < *this);
}

/**
 * @details Surcharge opérateur >=.
 * @param rhs
 * @return
 */
bool StdContact::operator>=(const StdContact &rhs) const
{
    return !(*this < rhs);
}

/**
 * @details Surcharge opérateur ==.
 * @param rhs
 * @return
 */
bool StdContact::operator==(const StdContact &rhs) const
{
    return dateCreation == rhs.dateCreation;
}

/**
 * @details Surcharge opérateur !=.
 * @param rhs
 * @return
 */
bool StdContact::operator!=(const StdContact &rhs) const
{
    return !(rhs == *this);
}


/**
 * @details Constructeur par copie.
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
    setlstInteraction(*contact.getLstInteraction());
}

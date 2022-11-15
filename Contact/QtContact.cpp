//
// Created by Rahman  Yilmaz on 22/09/2022.
//

#include "QtContact.h"

#include <utility>
#include "StdContact.h"


/**
 * @details Constructeur de la classe QtContact
 * @param nom
 * @param prenom
 * @param entreprise
 * @param mail
 * @param telephone
 * @param photo
 * @param dateCreation
 * @param lstInteraction
 */
QtContact::QtContact(QString nom, QString prenom, QString entreprise, QString mail,
                     QString telephone, QString photo, const uint64_t &dateCreation) : nom(std::move(nom)),
                                                                                       prenom(std::move(prenom)),
                                                                                       entreprise(std::move(
                                                                                               entreprise)),
                                                                                       mail(std::move(mail)),
                                                                                       telephone(std::move(
                                                                                               telephone)),
                                                                                       photo(std::move(photo)),
                                                                                       dateCreation(
                                                                                               dateCreation)
{}

/**
* @details Constructeur par defaut de QtContact
*/
QtContact::QtContact()
= default;

/**
 * @details Getter de Nom
 * @return le Nom du contact
 */
const QString &QtContact::getNom() const
{
    return nom;
}

/**
 * @details Setter de Nom
 * @param Nom du contact
 */
void QtContact::setNom(const QString &nom)
{
    QtContact::nom = nom;
}

/**
 * @details Getter de Prenom
 * @return Le Prenom du contact
 */
const QString &QtContact::getPrenom() const
{
    return prenom;
}


/**
 * @details Setter de Prenom
 * @param Prenom du contact
 */
void QtContact::setPrenom(const QString &prenom)
{
    QtContact::prenom = prenom;
}

/**
 * @details Getter de Entreprise
 * @return L'Entreprise du contact
 */
const QString &QtContact::getEntreprise() const
{
    return entreprise;
}

/**
 * @details Setter de Entreprise
 * @param Entreprise du contact
 */
void QtContact::setEntreprise(const QString &entreprise)
{
    QtContact::entreprise = entreprise;
}

/**
 * @details Getter de Mail
 * @return Le Mail du contact
 */
const QString &QtContact::getMail() const
{
    return mail;
}

/**
 * @details Setter de Mail
 * @param Mail du contact
 */
void QtContact::setMail(const QString &mail)
{
    QtContact::mail = mail;
}

/**
 * @details Getter de Telephone
 * @return Le Telephone du contact
 */
const QString &QtContact::getTelephone() const
{
    return telephone;
}

/**
 * @details Setter de Telephone
 * @param Telephone du contact
 */
void QtContact::setTelephone(const QString &telephone)
{
    QtContact::telephone = telephone;
}

/**
 * @details Getter de Photo
 * @return La Photo du contact
 */
const QString &QtContact::getPhoto() const
{
    return photo;
}

/**
 * @details Setter de Photo
 * @param Photo du contact
 */
void QtContact::setPhoto(const QString &photo)
{
    QtContact::photo = photo;
}

/**
 * @details Getter de DateCreation
 * @return DateCreation de creation du contact
 */
uint64_t QtContact::getDateCreation() const
{
    return dateCreation;
}

/**
 * @details Setter de DateCreation
 * @param DateCreation du contact
 */
void QtContact::setDateCreation(uint64_t dateCreation)
{
    QtContact::dateCreation = dateCreation;
}

/**
 * @details Destructeur de la classe QtContact
 */
QtContact::~QtContact()
{
}

/**
 * @details Constructeur de copie.
 * @param qtContact
 */
QtContact::QtContact(const QtContact &qtContact)
{
    setNom(qtContact.getNom());
    setPrenom(qtContact.getPrenom());
    setEntreprise(qtContact.getEntreprise());
    setMail(qtContact.getMail());
    setTelephone(qtContact.getTelephone());
    setPhoto(qtContact.getPhoto());
    setDateCreation(qtContact.getDateCreation());

}


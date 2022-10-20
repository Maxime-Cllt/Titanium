//
// Created by Rahman  Yilmaz on 22/09/2022.
//
/*
*   Classe QtContact: Modelise un contact dans l'application
*
*/

#include "QtContact.h"
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
QtContact::QtContact(const QString &nom, const QString &prenom, const QString &entreprise, const QString &mail,
                     const QString &telephone, const QString &photo, const uint64_t &dateCreation,
                     const ListInteraction &lstInteraction) : Nom(nom), Prenom(prenom), Entreprise(entreprise),
                                                              Mail(mail), Telephone(telephone), Photo(photo),
                                                              DateCreation(dateCreation),
                                                              lstInteraction(new ListInteraction(lstInteraction)) {}

/**
 *
 * @return le Nom du contact
 */
const QString &QtContact::getNom() const
{
    return Nom;
}

/**
 *
 * @param Nom du contact
 */
void QtContact::setNom(const QString &nom)
{
    Nom = nom;
}

/**
 *
 * @return Le Prenom du contact
 */
const QString &QtContact::getPrenom() const
{
    return Prenom;
}

/**
 *
 * @param Prenom du contact
 */
void QtContact::setPrenom(const QString &prenom)
{
    Prenom = prenom;
}

/**
 *
 * @return L'Entreprise du contact
 */
const QString &QtContact::getEntreprise() const
{
    return Entreprise;
}

/**
 *
 * @param Entreprise du contact
 */
void QtContact::setEntreprise(const QString &entreprise)
{
    Entreprise = entreprise;
}

/**
 *
 * @return Le Mail du contact
 */
const QString &QtContact::getMail() const
{
    return Mail;
}

/**
 *
 * @param Mail du contact
 */
void QtContact::setMail(const QString &mail)
{
    Mail = mail;
}

/**
 *
 * @return Le Telephone du contact
 */
const QString &QtContact::getTelephone() const
{
    return Telephone;
}

/**
 *
 * @param Telephone du contact
 */
void QtContact::setTelephone(const QString &telephone)
{
    Telephone = telephone;
}

/**
 *
 * @return La Photo du contact
 */
const QString &QtContact::getPhoto() const
{
    return Photo;
}

/**
 *
 * @param Photo du contact
 */
void QtContact::setPhoto(const QString &photo)
{
    Photo = photo;
}

/**
 * @param Constructeur par defaut d'un Contact
 */
QtContact::QtContact() {}

/**
 *
 * @return La liste d'interaction du contact lstInteraction
 */
const ListInteraction QtContact::getLstInteraction() const
{
    return *lstInteraction;
}

/**
 *
 * @param lstInteraction du contact
 */
void QtContact::setLstInteraction(const ListInteraction &lstInteraction)
{
    QtContact::lstInteraction = new ListInteraction(lstInteraction);
}

/**
 *
 * @return La liste d'interaction du contact lstInteraction
 */
ListInteraction *QtContact::getLstInteraction()
{
    return lstInteraction;
}

/**
 *
 * @return DateCreation de creation du contact
 */
uint64_t QtContact::getDateCreation() const
{
    return DateCreation;
}

/**
 *
 * @param DateCreation du contact
 */
void QtContact::setDateCreation(uint64_t dateCreation)
{
    DateCreation = dateCreation;
}

/**
 * @details Destructeur de la classe QtContact
 */
QtContact::~QtContact()
{
    delete lstInteraction;
}


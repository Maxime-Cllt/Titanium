//
// Created by Rahman  Yilmaz on 22/09/2022.
//


/**
 * Classe QtContact: Modelise un contact dans l'application
 */

#include "QtContact.h"
#include "StdContact.h"


/**
 * Constructeur de la classe QtContact
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
                                                              lstInteraction(new ListInteraction(lstInteraction))
{}

/**
 *
 * @return le nom du contact
 */
const QString &QtContact::getNom() const
{
    return Nom;
}

/**
 *
 * @param nom du contact
 */
void QtContact::setNom(const QString &nom)
{
    Nom = nom;
}

/**
 *
 * @return le prenom du contact
 */
const QString &QtContact::getPrenom() const
{
    return Prenom;
}

/**
 *
 * @param prenom du contact
 */
void QtContact::setPrenom(const QString &prenom)
{
    Prenom = prenom;
}

/**
 *
 * @return entreprise du contact
 */
const QString &QtContact::getEntreprise() const
{
    return Entreprise;
}

/**
 *
 * @param entreprise du contact
 */
void QtContact::setEntreprise(const QString &entreprise)
{
    Entreprise = entreprise;
}

/**
 *
 * @return mail du contact
 */
const QString &QtContact::getMail() const
{
    return Mail;
}

/**
 *
 * @param mail du contact
 */
void QtContact::setMail(const QString &mail)
{
    Mail = mail;
}

//Getter de l'attribut Telephone
const QString &QtContact::getTelephone() const
{
    return Telephone;
}

/**
 *
 * @param telephone du contact
 */
void QtContact::setTelephone(const QString &telephone)
{
    Telephone = telephone;
}

/**
 *
 * @return photo du contact
 */
const QString &QtContact::getPhoto() const
{
    return Photo;
}

/**
 *
 * @param photo du contact
 */
void QtContact::setPhoto(const QString &photo)
{
    Photo = photo;
}

/**
 * @param Constructeur par defaut d'un Contact
 */
QtContact::QtContact()
{}

/**
 *
 * @return lstInteraction la liste d'interaction du contact
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
 * @return lstInteraction la liste d'interaction du contact
 */
ListInteraction *QtContact::getLstInteraction()
{
    return lstInteraction;
}

/**
 *
 * @return date de creation du contact
 */
uint64_t QtContact::getDateCreation() const
{
    return DateCreation;
}

/**
 *
 * @param dateCreation du contact
 */
void QtContact::setDateCreation(uint64_t dateCreation)
{
    DateCreation = dateCreation;
}

/**
 *  Destructeur de la classe QtContact
 */
QtContact::~QtContact()
{
    delete lstInteraction;
}


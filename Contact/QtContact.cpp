//
// Created by Rahman  Yilmaz on 22/09/2022.
//

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
                                                              lstInteraction(new ListInteraction(lstInteraction))
{}

/**
* @details Constructeur par defaut de QtContact
*/
QtContact::QtContact()
{
    lstInteraction = new ListInteraction;
}

/**
 * @details getter de Nom
 * @return le Nom du contact
 */
const QString &QtContact::getNom() const
{
    return Nom;
}

/**
 * @details setter de Nom
 * @param Nom du contact
 */
void QtContact::setNom(const QString &nom)
{
    Nom = nom;
}

/**
 * @details getter de Prenom
 * @return Le Prenom du contact
 */
const QString &QtContact::getPrenom() const
{
    return Prenom;
}


/**
 * @details setter de Prenom
 * @param Prenom du contact
 */
void QtContact::setPrenom(const QString &prenom)
{
    Prenom = prenom;
}

/**
 * @details getter de Entreprise
 * @return L'Entreprise du contact
 */
const QString &QtContact::getEntreprise() const
{
    return Entreprise;
}

/**
 * @details setter de Entreprise
 * @param Entreprise du contact
 */
void QtContact::setEntreprise(const QString &entreprise)
{
    Entreprise = entreprise;
}

/**
 * @details getter de Mail
 * @return Le Mail du contact
 */
const QString &QtContact::getMail() const
{
    return Mail;
}

/**
 * @details setter de Mail
 * @param Mail du contact
 */
void QtContact::setMail(const QString &mail)
{
    Mail = mail;
}

/**
 * @details getter de Telephone
 * @return Le Telephone du contact
 */
const QString &QtContact::getTelephone() const
{
    return Telephone;
}

/**
 * @details setter de Telephone
 * @param Telephone du contact
 */
void QtContact::setTelephone(const QString &telephone)
{
    Telephone = telephone;
}

/**
 * @details getter de Photo
 * @return La Photo du contact
 */
const QString &QtContact::getPhoto() const
{
    return Photo;
}

/**
 * @details setter de Photo
 * @param Photo du contact
 */
void QtContact::setPhoto(const QString &photo)
{
    Photo = photo;
}


/**
 * @details getter de lstInteraction
 * @return Le Contenu du lstInteraction qui ne peut pas etre modifié.
 */
const ListInteraction QtContact::getLstInteraction() const
{
    return *lstInteraction;
}

/**
 * @details setter de lstInteraction
 * @param lstInteraction du contact
 */
void QtContact::setLstInteraction(const ListInteraction &lstInteraction)
{
    QtContact::lstInteraction = new ListInteraction(lstInteraction);
}

/**
 * @details getter de lstInteraction
 * @return lstInteraction.
 */
ListInteraction *QtContact::getLstInteraction()
{
    return lstInteraction;
}

/**
 * @details getter de DateCreation
 * @return DateCreation de creation du contact
 */
uint64_t QtContact::getDateCreation() const
{
    return DateCreation;
}

/**
 * @details setter de DateCreation
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
    setLstInteraction(qtContact.getLstInteraction());

}


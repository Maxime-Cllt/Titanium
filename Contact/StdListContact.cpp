//
// Created by rahman on 09/10/22.
//

#include "StdListContact.h"

/**
 *  @details Constructeur par defaut de la classe StdListContact
 */
StdListContact::StdListContact() = default;

/**
 * Ajouter un StdContact à la liste lstContact
 * @param StdContact
 */
void StdListContact::addContact(const StdContact &contact)
{
    lstContact.push_back(new StdContact(contact));
}

/**
 * Ajouter un QtContact à la liste lstContact
 * @param QtContact
 */
void StdListContact::addContact(const QtContact &contact)
{
    lstContact.push_back(new StdContact(TraductionQtStd::QtFicheContactToStdFicheContact(contact)));
}

/**
 *
 * @return lstContact de la classe StdContact
 */
std::list<StdContact *> *StdListContact::getLstContact()
{
    return &lstContact;
}

/**
 * Ajouter un contact dans la liste lstContact
 * @param contact
 */
void StdListContact::addContact(StdContact *contact)
{
    lstContact.push_front(contact);
}

/**
 * Surcharge de l'operator <<
 * @param os
 * @param lst
 * @return contact
 */
std::ostream &operator<<(std::ostream &os, const StdListContact &lst)
{
    for (const auto &contact: lst.lstContact)
    {
        os << contact << "\n";
    }
    return os;
}

/**
 * Supprimer un contact de la liste lstContact
 * @param StdContact
 */
void StdListContact::supContact(StdContact *contact)
{
    lstContact.remove(contact);
}

/**
 *  @details Destructeur de la classe StdListContact
 */
StdListContact::~StdListContact()
{
    for (auto contact: lstContact)
    {
        delete contact;
    }
}

StdListContact::StdListContact(const StdListContact &lst)
{
    for (auto contact: lst.lstContact)
    {
        addContact(*contact);
    }
}

/**
 * @details Trie la liste des contacts dans l'ordre décroissant en fonction de la date de creation du contact.
 */
void StdListContact::sortDateCreation()
{
    lstContact.sort([](StdContact *contact1,StdContact *contact2){
        return *contact1 > *contact2;
    });
}


/**
 * @details Trie la liste des contacts dans l'ordre croissant en fonction du nom du contact.
 */
void StdListContact::sortNom()
{
    lstContact.sort([](StdContact *contact1,StdContact *contact2){
        return contact1->getNom() < contact2->getNom();
    });
}

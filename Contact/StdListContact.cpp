//
// Created by rahman on 09/10/22.
//

#include "StdListContact.h"

/**
 *  @details Constructeur par defaut de la classe StdListContact
 */
StdListContact::StdListContact()
{
    lstContact = new std::list<StdContact *>();
};

/**
 * @details Ajoute le contact en paramètre à la liste des contacts en recréant un nouveau pointeur
 * qui pointe sur un nouveau StdContact avec les attributs de memes valeur que le contact en paramètre.
 * @param StdContact
 */
void StdListContact::addContact(const StdContact &contact)
{
    lstContact->push_back(new StdContact(contact));
}

/**
 * @details Ajoute le contact en paramètre à la liste des contacts en recréant un nouveau pointeur
 * qui pointe sur un nouveau StdContact avec les attributs de memes valeur que le contact en paramètre.
 * @param contact
 */
void StdListContact::addContact(StdContact *contact)
{
    addContact(*contact);
}

/**
 * @details getter de lstContact
 * @return lstContact de la classe StdContact
 */
std::list<StdContact *> *StdListContact::getLstContact()
{
    return lstContact;
}


/**
 * @details Surcharge de l'operator <<
 * @param os
 * @param lst
 * @return contact
 */
std::ostream &operator<<(std::ostream &os, const StdListContact &lst)
{
    os << "StdListContact" << std::endl << "{" << std::endl;
    int i = 1;
    for (const auto contact: *lst.lstContact)
    {
        os << "\tContact n°" << i << " { " << *contact << " }" << std::endl;
        i++;
    }
    os << "}" << std::endl;
    return os;
}

/**
 * @details retire le StdContact en paramètre de lstContact et le delete juste apres.
 * @param StdContact
 */
void StdListContact::supContact(StdContact *contact)
{
    lstContact->remove(contact);
    delete contact;
}

/**
 *  @details Destructeur de la classe StdListContact
 */
StdListContact::~StdListContact()
{
    for (auto contact: *lstContact)
    {
        delete contact;
    }
}

/**
 * @details Constructeur de copie.
 * @param lst
 */
StdListContact::StdListContact(const StdListContact &lst)
{
    lstContact = new std::list<StdContact *>();
    for (auto contact: *lst.lstContact)
    {
        addContact(*contact);
    }
}

/**
 * @details Trie la liste des contacts dans l'ordre décroissant en fonction de la date de creation du contact.
 */
void StdListContact::sortDateCreation()
{
    lstContact->sort([](StdContact *contact1, StdContact *contact2)
                     {
                         return *contact1 > *contact2;
                     });
}


/**
 * @details Trie la liste des contacts dans l'ordre croissant en fonction du nom du contact.
 */
void StdListContact::sortNom()
{
    lstContact->sort([](StdContact *contact1, StdContact *contact2)
                     {
                         return contact1->getNom() < contact2->getNom();
                     });
}

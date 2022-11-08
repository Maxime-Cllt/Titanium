//
// Created by rahman on 09/10/22.
//

#include <algorithm>
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
 * qui pointe sur un nouveau StdContact avec les attributs de meme valeur que le contact en paramètre.
 * @param StdContact
 * @return True si le contact a été ajouté, false sinon.
 */
void StdListContact::addContact(const StdContact &contact)
{
    lstContact->push_back(new StdContact(contact));
}

/**
 * @details Ajoute le contact en paramètre à la liste des contacts.
 * @param contact
 * @return True si le contact a été ajouté, false sinon.
 */
void StdListContact::addContact(StdContact *contact)
{
    lstContact->push_back(contact);
}

/**
 * @details Getter de lstContact
 * @return lstContact de la classe StdContact
 */
std::list<StdContact *> *StdListContact::getLstContact() const
{
    return lstContact;
}


/**
 * @details Surcharge de l'operator << d'affichage.
 * @param os
 * @param lst
 * @return os
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
 * @details Retire le StdContact en paramètre de la liste des contacts et le delete juste apres.
 * @param StdContact
 */
void StdListContact::supContact(StdContact *contact)
{
    lstContact->remove(contact);
    delete contact;
}

/**
 * @details Retire le StdContact en paramètre de la liste des contacts.
 * @param StdContact
 */
void StdListContact::removeContact(StdContact *contact)
{
    lstContact->remove(contact);
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
 * @details Constructeur par copie.
 * @param lst
 */
StdListContact::StdListContact(const StdListContact &listContact)
{
    lstContact = new std::list<StdContact *>();
    for (auto contact: *listContact.lstContact)
    {
        addContact(*contact);
    }
}

/**
 * @details Retourne la taille de la liste des contacts.
 */
int StdListContact::size()
{
    return lstContact->size();
}

/**
 * @details Setter de lstContact.
 * @param lstContact
 */
void StdListContact::setLstContact(std::list<StdContact *> *lstContact)
{
    StdListContact::lstContact = lstContact;
}

void StdListContact::append(const StdListContact &lst)
{
    lstContact->splice(lstContact->end(), *lst.getLstContact());
}

/**
 * @brief Permet de savoir si un contact est dans la liste.
 * @param contact
 * @return True si le contact est dans la liste false sinon.
 */
bool StdListContact::contains(const StdContact &contact)
{
    for (const auto c: *lstContact)
    {
        if (*c == contact)
        {
            return true;
        }
    }
    return false;
}

/**
 * @details Fonction qui tri la liste en fonction du tri indiquer en parametre.
 * @param sort
 */
void StdListContact::sort(StdListContact::Sort sort)
{
    switch (sort)
    {
        case Sort::Date :
            lstContact->sort([](StdContact *contact1, StdContact *contact2) { return *contact1 > *contact2; });
            break;
        case Sort::Nom :
            lstContact->sort(
                    [](StdContact *contact1, StdContact *contact2) { return contact1->getNom() < contact2->getNom(); });
            break;
    }
}

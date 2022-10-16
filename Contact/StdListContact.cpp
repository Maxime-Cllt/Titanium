//
// Created by rahman on 09/10/22.
//

#include "StdListContact.h"

//Constructeur de StdListContact
StdListContact::StdListContact() = default;

//Fonction pour ajouter un contact
void StdListContact::addContact(const StdContact &contact)
{
    lstContact.push_back(new StdContact(contact));
}

//Fonction pour ajouter un contact
void StdListContact::addContact(const QtContact &contact)
{
    lstContact.push_back(new StdContact(TraductionQtStd::QtFicheContactToStdFicheContact(contact)));
}

//Getter de l'attribut lstContact
std::list<StdContact *> *StdListContact::getLstContact()
{
    return &lstContact;
}

void StdListContact::addContact(StdContact *contact)
{
    lstContact.push_back(contact);

}

std::ostream &operator<<(std::ostream &os, const StdListContact &lst)
{
    for (const auto &contact: lst.lstContact)
    {
        os << contact << "\n";
    }
    return os;
}

//Fonction pour supprimer un contact
void StdListContact::supContact(StdContact *contact)
{
    lstContact.remove(contact);
}

//Destructeur de StdListContact
StdListContact::~StdListContact()
{
    for (auto contact: lstContact)
    {
        delete contact;
    }
}

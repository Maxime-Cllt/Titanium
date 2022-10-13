//
// Created by rahman on 09/10/22.
//

#include "StdListContact.h"

StdListContact::StdListContact() = default;

void StdListContact::addContact(const StdContact &contact)
{
    lstContact.push_back(new StdContact(contact));
}

void StdListContact::addContact(const QtContact &contact)
{
    lstContact.push_back(new StdContact(TraductionQtStd::QtFicheContactToStdFicheContact(contact)));
}

std::list<StdContact *> *StdListContact::getLstContact()
{
    return &lstContact;
}

std::ostream &operator<<(std::ostream &os, const StdListContact &lst)
{
    for (const auto &contact: lst.lstContact)
    {
        os << contact << "\n";
    }
    return os;
}

void StdListContact::supContact(StdContact *contact)
{
    lstContact.remove(contact);

}

StdListContact::~StdListContact()
{

    for(auto contact : lstContact){
        delete contact;
    }

}

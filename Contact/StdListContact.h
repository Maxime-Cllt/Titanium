//
// Created by rahman on 09/10/22.
//


#ifndef UNTITLED2_STDLISTCONTACT_H
#define UNTITLED2_STDLISTCONTACT_H

#include <iostream>
#include <list>
#include "StdContact.h"
#include "QtContact.h"
#include "TraductionQtStd.h"

/**
 *  @details Classe StdListContact qui sert à stocker les objets de type StdContact et à réaliser divers operations.
 */
class StdListContact
{
public:
    explicit StdListContact();

    StdListContact(const StdListContact &);

    ~StdListContact();

    friend std::ostream &operator<<(std::ostream &os, const StdListContact &lst);

    void addContact(const StdContact &contact);

    void addContact(StdContact *contact);

    void supContact(StdContact *contact);

    std::list<StdContact *> *getLstContact();

    void sortDateCreation();

    void sortNom();

private:
    std::list<StdContact *> *lstContact{};


};


#endif //UNTITLED2_STDLISTCONTACT_H

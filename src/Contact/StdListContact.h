//
// Created by rahman on 09/10/22.
//


#ifndef PROJET_QT_STDLISTCONTACT_H
#define PROJET_QT_STDLISTCONTACT_H

#include <iostream>
#include <list>
#include "StdContact.h"

/**
 *  @details Classe StdListContact qui sert à stocker les objets de type StdContact et à réaliser divers operations.
 */
class StdListContact
{
public:
    explicit StdListContact();

    StdListContact(const StdListContact &listContact);

    ~StdListContact();

    enum Sort
    {
        DateCroissant, DateDecroissant, NomCroissant, NomDecroissant
    };


private:
    std::list<StdContact *> *lstContact{};

public:

    friend std::ostream &operator<<(std::ostream &, const StdListContact &);

    void addContact(const StdContact &);

    void addContact(StdContact *);

    void supContact(StdContact *);

    void removeContact(StdContact *);

    void append(const StdListContact &);

    [[nodiscard]] std::list<StdContact *> *getLstContact() const;

    void setLstContact(std::list<StdContact *> *lstContact);

    void sort(Sort sort);

    int size();

    void clear();

    bool contains(const StdContact &);

};


#endif //PROJET_QT_STDLISTCONTACT_H

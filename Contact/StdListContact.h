//
// Created by rahman on 09/10/22.
//


#ifndef PROJET_QT_STDLISTCONTACT_H
#define PROJET_QT_STDLISTCONTACT_H

#include <iostream>
#include <list>
#include "StdContact.h"
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


private:
public:
    void setLstContact(std::list<StdContact *> *lstContact);

private:
    std::list<StdContact *> *lstContact{};
    std::list<std::string> lstLog{};

public:

    friend std::ostream &operator<<(std::ostream &, const StdListContact &);

    void addContact(const StdContact &);

    void addContact(StdContact *);

    void supContact(StdContact *);

    void removeContact(StdContact *);

    void addLog(int, const StdContact &);

    [[nodiscard]] std::list<StdContact *> *getLstContact() const;

    [[nodiscard]] const std::list<std::string> &getLstLog() const;

    void setLstLog(const std::list<std::string> &);

    void reverseDateCreation();

    void sortNom();

    int size();

private:
    static std::string getDateNow();


};


#endif //PROJET_QT_STDLISTCONTACT_H

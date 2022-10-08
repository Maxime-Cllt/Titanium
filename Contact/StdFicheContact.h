//
// Created by Rahman  Yilmaz on 07/10/2022.
//

#ifndef UNTITLED2_STDFICHECONTACT_H
#define UNTITLED2_STDFICHECONTACT_H

#include <iostream>
#include <string>
#include <list>
#include "../date.h"
#include "QtFicheContact.h"


class StdFicheContact
{
public:
    StdFicheContact(const std::string &nom, const std::string &prenom, const std::string &entreprise,
                    const std::string &mail, const std::string &telephone, const std::string &photo,
                    const date::year_month_day &dateCreation, const std::list<std::string> &lstModif);

    explicit StdFicheContact();

private:
    std::string Nom;
    std::string Prenom;
    std::string Entreprise;
    std::string Mail;
    std::string Telephone;
    std::string Photo;
    date::year_month_day DateCreation;
    std::list<std::string> lstModif;

    QtFicheContact toQtFicheContact();
};


#endif //UNTITLED2_STDFICHECONTACT_H

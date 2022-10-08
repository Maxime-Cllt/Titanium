//
// Created by Rahman  Yilmaz on 07/10/2022.
//

#ifndef UNTITLED2_STDFICHECONTACT_H
#define UNTITLED2_STDFICHECONTACT_H

#include <iostream>
#include <string>
#include <list>
#include "../date.h"


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
public:
    const std::string &getNom() const;

    void setNom(const std::string &nom);

    const std::string &getPrenom() const;

    void setPrenom(const std::string &prenom);

    const std::string &getEntreprise() const;

    void setEntreprise(const std::string &entreprise);

    const std::string &getMail() const;

    void setMail(const std::string &mail);

    const std::string &getTelephone() const;

    void setTelephone(const std::string &telephone);

    const std::string &getPhoto() const;

    void setPhoto(const std::string &photo);

    const date::year_month_day &getDateCreation() const;

    void setDateCreation(const date::year_month_day &dateCreation);

    const std::list<std::string> &getLstModif() const;

    void setLstModif(const std::list<std::string> &lstModif);

private:
    std::string Photo;
    date::year_month_day DateCreation;
    std::list<std::string> lstModif;

};


#endif //UNTITLED2_STDFICHECONTACT_H

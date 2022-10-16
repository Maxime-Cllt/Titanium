//
// Created by Rahman  Yilmaz on 07/10/2022.
//

#ifndef UNTITLED2_STDCONTACT_H
#define UNTITLED2_STDCONTACT_H

#include <iostream>
#include <string>
#include <list>
#include "../Interaction/Interaction.h"
#include "../Interaction/ListInteraction.h"


class StdContact
{
public:
    StdContact(const std::string &nom, const std::string &prenom, const std::string &entreprise,
               const std::string &mail, const std::string &telephone, const std::string &photo,
               const uint64_t &dateCreation, const ListInteraction &lstInteraction);

    explicit StdContact();

    ~StdContact();

private:
    std::string Nom;
    std::string Prenom;
    std::string Entreprise;
    std::string Mail;
    std::string Telephone;
    std::string Photo;
    uint64_t DateCreation;
    ListInteraction *lstInteraction;
public:

    friend std::ostream &operator<<(std::ostream &os, const StdContact &contact);

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

    const uint64_t &getDateCreation() const;

    void setDateCreation(const uint64_t &dateCreation);

    const ListInteraction &getLstInteraction() const;

    ListInteraction *getLstInteraction();

    void setlstInteraction(const ListInteraction &lstInteraction);

    void setlstInteraction(ListInteraction *lstInteraction);

    void addInteraction(const Interaction &interaction);

};


#endif //UNTITLED2_STDCONTACT_H

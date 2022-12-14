//
// Created by Rahman  Yilmaz on 07/10/2022.
//

#ifndef PROJET_QT_STDCONTACT_H
#define PROJET_QT_STDCONTACT_H

#include <iostream>
#include <string>
#include <list>
#include "../Interaction/Interaction.h"
#include "../Interaction/ListInteraction.h"

/**
* @details Classe StdContact qui utilise uniquement des objets c/c++, cette classe définit un contact.
*/
class StdContact
{
public:
    StdContact(std::string nom, std::string prenom, std::string entreprise,
               std::string mail, std::string telephone, std::string photo,
               const uint64_t &dateCreation, const ListInteraction &lstInteraction);


    explicit StdContact();

    StdContact(const StdContact &contact);

    ~StdContact();

private:
    std::string nom{};
    std::string prenom{};
    std::string entreprise{};
    std::string mail{};
    std::string telephone{};
    std::string photo{};
    uint64_t dateCreation{};
    ListInteraction *lstInteraction{};
public:
    bool operator<(const StdContact &) const;

    bool operator>(const StdContact &) const;

    bool operator<=(const StdContact &) const;

    bool operator>=(const StdContact &) const;

    bool operator==(const StdContact &) const;

    bool operator!=(const StdContact &) const;

    friend std::ostream &operator<<(std::ostream &, const StdContact &);

    [[nodiscard]] const std::string &getNom() const;

    void setNom(const std::string &);

    [[nodiscard]] const std::string &getPrenom() const;

    void setPrenom(const std::string &);

    [[nodiscard]] const std::string &getEntreprise() const;

    void setEntreprise(const std::string &);

    [[nodiscard]] const std::string &getMail() const;

    void setMail(const std::string &);

    [[nodiscard]] const std::string &getTelephone() const;

    void setTelephone(const std::string &);

    [[nodiscard]] const std::string &getPhoto() const;

    void setPhoto(const std::string &);

    [[nodiscard]] const uint64_t &getDateCreation() const;

    void setDateCreation(const uint64_t &);

    [[nodiscard]] ListInteraction *getLstInteraction() const;

    void setlstInteraction(const ListInteraction &);

    void setlstInteraction(ListInteraction *);

    void addInteraction(const Interaction &);

};


#endif //PROJET_QT_STDCONTACT_H

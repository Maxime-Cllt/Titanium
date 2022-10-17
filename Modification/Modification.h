//
// Created by Rahman  Yilmaz on 14/10/2022.
//

#ifndef PROJET_QT_MODIFICATION_H
#define PROJET_QT_MODIFICATION_H

#include <iostream>
#include <ctime>

class Modification
{
public:
    explicit Modification(const uint64_t &dateCreationContact, std::string contenuModif);

private:
    std::string contenuModif{};
    uint64_t dateCreationContact{};
    uint64_t dateCreation{};

public:

    friend bool operator<(const Modification &lhs, const Modification &rhs);

    friend bool operator>(const Modification &lhs, const Modification &rhs);

    friend bool operator<=(const Modification &lhs, const Modification &rhs);

    friend bool operator>=(const Modification &lhs, const Modification &rhs);

    uint64_t getDateCreation() const;

    void setDateCreation(uint64_t dateCreation);

    const std::string &getContenuModif() const;

    void setContenuModif(const std::string &contenuModif);

    uint64_t getDateCreationContact() const;

    void setDateCreationContact(uint64_t dateCreationContact);
};


#endif //PROJET_QT_MODIFICATION_H

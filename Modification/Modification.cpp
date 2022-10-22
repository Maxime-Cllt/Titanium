//
// Created by Rahman  Yilmaz on 14/10/2022.
//

#include "Modification.h"

#include <chrono>

/**
 * @details Constructeur de la classe Modification
 * @param dateCreationContact
 * @param contenuModif
 */
Modification::Modification(const uint64_t &dateCreationContact, std::string contenuModif) : dateCreationContact(
        dateCreationContact), contenuModif(std::move(contenuModif))
{
    dateCreation = std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();

}

/**
 *
 * @return contenuModif
 */
const std::string &Modification::getContenuModif() const
{
    return contenuModif;
}

/**
 *
 * @param contenuModif
 */
void Modification::setContenuModif(const std::string &contenuModif)
{
    Modification::contenuModif = contenuModif;
}

/**
 *
 * @return dateCreationContact
 */
uint64_t Modification::getDateCreationContact() const
{
    return dateCreationContact;
}

/**
 *
 * @param dateCreationContact
 */
void Modification::setDateCreationContact(uint64_t dateCreationContact)
{
    Modification::dateCreationContact = dateCreationContact;
}

/**
 *
 * @return dateCreation
 */
uint64_t Modification::getDateCreation() const
{
    return dateCreation;
}

/**
 *
 * @param dateCreation
 */
void Modification::setDateCreation(uint64_t dateCreation)
{
    Modification::dateCreation = dateCreation;
}

bool operator<(const Modification &lhs, const Modification &rhs)
{
    return lhs.dateCreation < rhs.dateCreation;
}

bool operator>(const Modification &lhs, const Modification &rhs)
{
    return rhs < lhs;
}

bool operator<=(const Modification &lhs, const Modification &rhs)
{
    return !(rhs < lhs);
}

bool operator>=(const Modification &lhs, const Modification &rhs)
{
    return !(lhs < rhs);
}

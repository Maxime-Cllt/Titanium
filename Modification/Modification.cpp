//
// Created by Rahman  Yilmaz on 14/10/2022.
//

#include "Modification.h"

#include <utility>

Modification::Modification(const std::time_t &dateCreationContact, std::string contenuModif) : dateCreationContact(
        dateCreationContact), contenuModif(std::move(contenuModif))
{


}

const std::string &Modification::getContenuModif() const
{
    return contenuModif;
}

void Modification::setContenuModif(const std::string &contenuModif)
{
    Modification::contenuModif = contenuModif;
}

time_t Modification::getDateCreationContact() const
{
    return dateCreationContact;
}

void Modification::setDateCreationContact(time_t dateCreationContact)
{
    Modification::dateCreationContact = dateCreationContact;
}

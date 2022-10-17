//
// Created by rahman on 09/10/22.
//

#include <chrono>
#include "Interaction.h"

Interaction::Interaction(const std::string &contenu)
{
    Interaction::contenu = contenu;

    id = duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();// recuperation de la date de maintenant
    dateModif = id;
}

const std::string &Interaction::getContenu() const
{
    return contenu;
}

void Interaction::setContenu(const std::string &contenu)
{
    Interaction::contenu = contenu;
}

Interaction::Interaction()
{
    Interaction::contenu = "";
    id = duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();// recuperation de la date de maintenant
    dateModif = id;
}

uint64_t Interaction::getId() const
{
    return id;
}

void Interaction::setId(uint64_t id)
{
    Interaction::id = id;
}

uint64_t Interaction::getDateModif() const
{
    return dateModif;
}

void Interaction::setDateModif(uint64_t dateModif)
{
    Interaction::dateModif = dateModif;
}

bool operator<(const Interaction &lhs, const Interaction &rhs)
{
    return lhs.dateModif < rhs.dateModif;
}

bool operator>(const Interaction &lhs, const Interaction &rhs)
{
    return rhs < lhs;
}

bool operator<=(const Interaction &lhs, const Interaction &rhs)
{
    return !(rhs < lhs);
}

bool operator>=(const Interaction &lhs, const Interaction &rhs)
{
    return !(lhs < rhs);
}

void Interaction::modif()
{
    setDateModif(duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count());
}

//
// Created by rahman on 09/10/22.
//

#include "Interaction.h"

const std::time_t &Interaction::getDate() const
{
    return date;
}

Interaction::Interaction(const std::string &contenu)
{
    this->contenu = contenu;

    date = std::time(nullptr);   // recuperation de la date de maintenant
}

const std::string &Interaction::getContenu() const
{
    return contenu;
}

void Interaction::setContenu(const std::string &contenu)
{
    Interaction::contenu = contenu;
}

void Interaction::setDate(time_t date)
{
    Interaction::date = date;
}

Interaction::Interaction() = default;

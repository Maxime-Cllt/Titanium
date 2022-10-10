//
// Created by rahman on 09/10/22.
//

#include "Interaction.h"

const std::time_t &Interaction::getDate() const
{
    return date;
}

const std::string &Interaction::getNote() const
{
    return note;
}

void Interaction::setNote(const std::string &note)
{
    Interaction::note = note;
}

Interaction::Interaction(const std::string &note)
{
    this->note = note;

    date = std::time(0);   // recuperation de la date de maintenant
}

Interaction::Interaction() = default;

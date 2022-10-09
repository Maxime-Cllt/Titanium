//
// Created by rahman on 09/10/22.
//

#include "Interaction.h"

const date::year_month_day &Interaction::getDate() const
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

    std::time_t t = std::time(0);   // recuperation de la date de maintenant
    std::tm *now = std::localtime(&t);
    date = date::year_month_day(date::year((now->tm_year + 1900)), date::month(now->tm_mon + 1),
                                date::day(now->tm_mday));
}

Interaction::Interaction() = default;

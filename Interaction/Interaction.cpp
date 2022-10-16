//
// Created by rahman on 09/10/22.
//

#include <chrono>
#include "Interaction.h"

Interaction::Interaction(const std::string &contenu)
{
    this->contenu = contenu;

    id = duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();// recuperation de la date de maintenant
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
    this->contenu = "";
    id = duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();// recuperation de la date de maintenant
}

uint64_t Interaction::getId() const
{
    return id;
}

void Interaction::setId(uint64_t id)
{
    Interaction::id = id;
}

//
// Created by rahman on 09/10/22.
//

#include <chrono>
#include <utility>
#include "Interaction.h"


/**
 * @details Constructeur de la classe Interaction
 * @param contenu
 */
Interaction::Interaction(const std::string &contenu)
{
    Interaction::contenu = contenu;

    // recuperation de la date de maintenant en milliseconde
    id = duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
    dateModif = id;
    lstTache = new ListTache();
}

/**
 *
 * @return Contenu de l'interaction
 */
const std::string &Interaction::getContenu() const
{
    return contenu;
}

/**
 *
 * @param contenu
 */
void Interaction::setContenu(const std::string &contenu)
{
    Interaction::contenu = contenu;
}

/**
 * @details Connaitre la date à l'instant
 */
Interaction::Interaction()
{
    Interaction::contenu = "";
    id = duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();// recuperation de la date de maintenant
    dateModif = id;
    lstTache = new ListTache();

}

/**
 *
 * @return id du contact
 */
uint64_t Interaction::getId() const
{
    return id;
}

/**
 *
 * @param id
 */
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


void Interaction::addTache(const Tache &tache)
{
    lstTache->addTache(new Tache(tache));
}

ListTache *Interaction::getLstTache() const
{
    return lstTache;
}

void Interaction::setLstTache(ListTache *lstTache)
{
    setLstTache(*lstTache);
}

void Interaction::setLstTache(const ListTache &lstTache)
{
    this->lstTache = new ListTache(lstTache);
}


Interaction::~Interaction()
{
    delete lstTache;
}

Interaction::Interaction(const Interaction &interaction)
{
    lstTache = new ListTache(*interaction.getLstTache());
    contenu = interaction.getContenu();
    id = interaction.getId();
    dateModif = interaction.getDateModif();

}

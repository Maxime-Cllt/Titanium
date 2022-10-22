//
// Created by rahman on 09/10/22.
//

#include <chrono>
#include "Interaction.h"


/**
 * @details Constructeur de la classe Interaction
 * @param contenu
 */
Interaction::Interaction(const std::string &contenu)
{
    Interaction::contenu = contenu;

    // recuperation de la date de maintenant en microseconde
    id = duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    dateModif = id;
    lstTache = new ListTache;
}

/**
 * @details getter de contenu
 * @return Contenu de l'interaction
 */
const std::string &Interaction::getContenu() const
{
    return contenu;
}

/**
 * @details setter de contenu
 * @param contenu
 */
void Interaction::setContenu(const std::string &contenu)
{
    Interaction::contenu = contenu;
}

/**
 * @details Constructeur par défaut.
 */
Interaction::Interaction()
{
    Interaction::contenu = "";
    id = duration_cast<std::chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();// recuperation de la date de maintenant
    dateModif = id;
    lstTache = new ListTache;

}

/**
 * @details getter de id
 * @return id du contact
 */
uint64_t Interaction::getId() const
{
    return id;
}

/**
 * @details setter de id
 * @param id
 */
void Interaction::setId(uint64_t id)
{
    Interaction::id = id;
}

/**
 * @details getter de dateModif
 * @return dateModif
 */
uint64_t Interaction::getDateModif() const
{
    return dateModif;
}

/**
 * @details setter de DateModif
 * @param dateModif
 */
void Interaction::setDateModif(uint64_t dateModif)
{
    Interaction::dateModif = dateModif;
}

/**
 * @details Modifie la DateModif au temps de maintenant.
 */
void Interaction::modif()
{
    setDateModif(duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
}

/**
 * @details Ajoute une tache à la liste des taches.
 * @param tache
 */
void Interaction::addTache(const Tache &tache)
{
    lstTache->addTache(new Tache(tache));
}

/**
 * @details Getter de lstTache.
 * @return lstTache
 */
ListTache *Interaction::getLstTache() const
{
    return lstTache;
}

/**
 * @details Setter de lstTache.
 * @return lstTache
 */
void Interaction::setLstTache(ListTache *lstTache)
{
    setLstTache(*lstTache);
}

/**
 * @details Setter de lstTache.
 * @return lstTache
 */
void Interaction::setLstTache(const ListTache &lstTache)
{
    Interaction::lstTache = new ListTache(lstTache);
}

/**
 * @details Destructeur.
 */
Interaction::~Interaction()
{
    delete lstTache;
}

/**
 * @details Constructeur par copie.
 * @param interaction
 */
Interaction::Interaction(const Interaction &interaction)
{
    setLstTache(interaction.getLstTache());
    contenu = interaction.getContenu();
    id = interaction.getId();
    dateModif = interaction.getDateModif();

}

/**
 * @details Surcharge de l'operateur < qui compare la dateModif des 2 intéractions.
 * @param rhs
 * @return
 */
bool Interaction::operator<(const Interaction &rhs) const
{
    return dateModif < rhs.dateModif;
}

/**
 * @details Surcharge de l'operateur >.
 * @param rhs
 * @return
 */
bool Interaction::operator>(const Interaction &rhs) const
{
    return rhs < *this;
}

/**
 * @details Surcharge de l'operateur <=.
 * @param rhs
 * @return
 */
bool Interaction::operator<=(const Interaction &rhs) const
{
    return !(rhs < *this);
}

/**
 * @details Surcharge de l'operateur >=.
 * @param rhs
 * @return
 */
bool Interaction::operator>=(const Interaction &rhs) const
{
    return !(*this < rhs);
}

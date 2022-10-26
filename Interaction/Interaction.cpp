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
    dateCreation = std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
    dateModif = dateCreation;
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
    dateCreation = std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();// recuperation de la date de maintenant
    dateModif = dateCreation;
    lstTache = new ListTache;

}

/**
 * @details getter de id
 * @return dateCreation
 */
uint64_t Interaction::getDateCreation() const
{
    return dateCreation;
}

/**
 * @details setter de id
 * @param id
 */
void Interaction::setDateCreation(uint64_t dateCreation)
{
    Interaction::dateCreation = dateCreation;
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
    setDateModif(std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count());
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
    Interaction::lstTache = lstTache;
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
 * @details Constructeur de copie.
 * @param interaction
 */
Interaction::Interaction(const Interaction &interaction)
{
    setLstTache(*interaction.getLstTache());
    contenu = interaction.getContenu();
    dateCreation = interaction.getDateCreation();
    dateModif = interaction.getDateModif();

}

/**
 * @details Surcharge de l'opérateur < qui compare la dateModif des deux interactions.
 * @param rhs
 * @return
 */
bool Interaction::operator<(const Interaction &rhs) const
{
    return dateModif < rhs.dateModif;
}

/**
 * @details Surcharge de l'opérateur >.
 * @param rhs
 * @return
 */
bool Interaction::operator>(const Interaction &rhs) const
{
    return rhs < *this;
}

/**
 * @details Surcharge de l'opérateur <=.
 * @param rhs
 * @return
 */
bool Interaction::operator<=(const Interaction &rhs) const
{
    return !(rhs < *this);
}

/**
 * @details Surcharge de l'opérateur >=.
 * @param rhs
 * @return
 */
bool Interaction::operator>=(const Interaction &rhs) const
{
    return !(*this < rhs);
}

/**
 * @details Surcharge opérateur << pour l'affichage. Affiche le contenu, l'id, la date de modification et la liste des taches.
 * @param os
 * @param interaction
 * @return os
 */
std::ostream &operator<<(std::ostream &os, const Interaction &interaction)
{
    os << "contenu: " << interaction.contenu << " id: " << interaction.dateCreation << " dateModif: " << interaction.dateModif;
    return os;
}

//
// Created by Rahman  Yilmaz on 20/10/2022.
//

#include "Tache.h"

#include <utility>
#include <chrono>

/**
 * @details Constructeur qui place contenu en paramètre à contenu l'attribut de l'objet Tache
 * et initialise la date de la tache à la date de la création de l'objet.
 * @param contenu
 */
Tache::Tache(std::string contenu) : contenu(std::move(contenu))
{
    date = std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
}

/**
 * @details Constructeur par défaut qui initialise la date de la tache à la date de la création de l'objet.
 */
Tache::Tache()
{
    date = std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
};

/**
 * @details Getter de contenu.
 * @return
 */
const std::string &Tache::getcontenu() const
{
    return contenu;
}

/**
 * @details Setter de contenu.
 * @param contenu
 */
void Tache::setcontenu(const std::string &contenu)
{
    Tache::contenu = contenu;
}

/**
 * @details Getter de date.
 * @return date
 */
uint64_t Tache::getdate() const
{
    return date;
}

/**
 * @details Setter de date.
 * @param date
 */
void Tache::setdate(uint64_t date)
{
    Tache::date = date;
}

/**
 * @details Surcharge de l'opérateur d'affichage ostream <<. Affiche le contenu de la tache et la date de la tache.
 * @param os
 * @param tache
 * @return os
 */
std::ostream &operator<<(std::ostream &os, const Tache &tache)
{
    os << "contenu: " << tache.contenu << " date: " << tache.date;
    return os;
}

/**
 * @details Surcharge de l'opérateur <
 * @param rhs
 * @return
 */
bool Tache::operator<(const Tache &rhs) const
{
    return date < rhs.date;
}

/**
 * @details Surcharge de l'opérateur >
 * @param rhs
 * @return
 */
bool Tache::operator>(const Tache &rhs) const
{
    return rhs < *this;
}

/**
 * @details Surcharge de l'opérateur <=
 * @param rhs
 * @return
 */
bool Tache::operator<=(const Tache &rhs) const
{
    return !(rhs < *this);
}

/**
 * @details Surcharge de l'opérateur >=
 * @param rhs
 * @return
 */
bool Tache::operator>=(const Tache &rhs) const
{
    return !(*this < rhs);
}

Tache::Tache(const Tache &tache)
{
    contenu = tache.contenu;
    date = tache.date;
}

//
// Created by Rahman  Yilmaz on 20/10/2022.
//

#include "Tache.h"

#include <utility>
#include <chrono>

/**
 * @details constructeur qui affecte à tag1, contenu les valeurs passer en parametre et
 * initialise la date du tag à la date de la création de l'objet
 * @param contenu
 */
Tache::Tache(std::string contenu) : contenu(std::move(contenu))
{
    dateTag = std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
}

/**
 * @details constructeur par defaut qui initialise la date du tag à la date de la création de l'objet.
 */
Tache::Tache()
{
    dateTag = std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
};

/**
 * @details getter de contenu.
 * @return
 */
const std::string &Tache::getcontenu() const
{
    return contenu;
}

/**
 * @details setter de contenu.
 * @param contenu
 */
void Tache::setcontenu(const std::string &contenu)
{
    Tache::contenu = contenu;
}

/**
 * @details getter de dateTag.
 * @return dateTag
 */
uint64_t Tache::getdateTag() const
{
    return dateTag;
}

/**
 * @details setter de dateTag.
 * @param dateTag
 */
void Tache::setdateTag(uint64_t dateTag)
{
    Tache::dateTag = dateTag;
}

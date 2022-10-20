//
// Created by Rahman  Yilmaz on 20/10/2022.
//

#include "Tache.h"

#include <utility>
#include <chrono>

/**
 * @details constructeur qui affecte à tag1, contenu les valeurs passer en parametre et
 * initialise la date du tag à la date de la création de l'objet
 * @param tag1
 * @param contenu
 */
Tache::Tache(std::string tag1, std::string contenu) : tag1(std::move(tag1)), contenu(std::move(contenu))
{
    dateTag = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
}

/**
 * @details constructeur par defaut qui initialise la date du tag à la date de la création de l'objet.
 */
Tache::Tache()
{
    dateTag = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
};

/**
 * @details getter de tag1.
 * @return tag1
 */
const std::string &Tache::getTag1() const
{
    return tag1;
}

/**
 * @details setter de tag1.
 * @param tag1
 */
void Tache::setTag1(const std::string &tag1)
{
    Tache::tag1 = tag1;
}

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
 * @details getter de tag2.
 * @return tag2
 */
const std::string &Tache::getTag2() const
{
    return tag2;
}

/**
 * @details setter de tag2.
 * @param tag2
 */
void Tache::setTag2(const std::string &tag2)
{
    Tache::tag2 = tag2;
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

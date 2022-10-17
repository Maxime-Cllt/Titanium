//
// Created by Rahman  Yilmaz on 14/10/2022.
//

#include "ModificationMap.h"

/**
 * Constructeur par defaut de la classe ModificationMap
 */
ModificationMap::ModificationMap()
{}

/**
 * Ajouter une modification
 * @param modification
 */
void ModificationMap::addModif(const Modification &modification)
{
    lst.insert_or_assign(time(nullptr), new Modification(modification));
}

/**
 * @details Destructeur de la classe ModificationMap
 */
ModificationMap::~ModificationMap()
{

    for (auto [key, elmt]: lst)
    {
        delete elmt;
    }
}

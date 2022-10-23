//
// Created by Rahman  Yilmaz on 14/10/2022.
//

#include "ListModification.h"

/**
 * @details Constructeur par défaut de la classe ListModification
 */
ListModification::ListModification()
{}

/**
 * @details Ajoute la modification en paramètre à la liste.
 * @param modification
 */
void ListModification::addModif(const Modification &modification)
{
    lst.push_back(new Modification(modification));
}

/**
 * @details Destructeur de la classe ListModification
 */
ListModification::~ListModification()
{

    for (auto elmt: lst)
    {
        delete elmt;
    }
}

/**
 * @details Fonction qui ajoute une nouvelle modification à la liste par un pointeur en paramètre.
 */
void ListModification::addModif(Modification *modification)
{
    addModif(*modification);
}

/**
 * @details Trie décroissant de la liste des Modifications.
 */
void ListModification::sort()
{
    lst.sort([](Modification *mod1, Modification *mod2)
             {
                 return *mod1 > *mod2;
             });
}

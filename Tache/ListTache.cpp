//
// Created by Rahman  Yilmaz on 20/10/2022.
//

#include "ListTache.h"

/**
 * @details constructeur par defaut.
 */
ListTache::ListTache()
= default;

/**
 * @details destructeur qui delete tous les pointers de Tache contenu dans lstTache
 */
ListTache::~ListTache()
{
    for (auto tache: lstTache)
    {
        delete tache;
    }
}

/**
 * @details ajoute la tache en paramètre à la liste des taches.
 * @param tache
 */
void ListTache::addTache(const Tache &tache)
{
    lstTache.push_back(new Tache(tache));
}

/**
 * @details ajoute le pointer tache en paramètre à la liste des taches.
 * @param tache
 */
void ListTache::addTache(Tache *tache)
{
    lstTache.push_back(new Tache(*tache));
}

/**
 * @details getter de la liste des taches.
 * @return la liste des taches
 */
const std::list<Tache *> &ListTache::getLstTache() const
{
    return lstTache;
}

/**
 * @details setter de la lite des taches.
 * @param lstTache
 */
void ListTache::setLstTache(const std::list<Tache *> &lstTache)
{
    ListTache::lstTache = lstTache;
}

/**
 * @details destruteur qui détruit tous les pointeurs de tache contenu dans la liste des taches.
 * @param lst
 */
ListTache::ListTache(const ListTache &lst)
{
    for (auto tache: lst.lstTache)
    {
        addTache(tache);
    }
}
//
// Created by Rahman  Yilmaz on 20/10/2022.
//

#include "ListTache.h"

/**
 * @details constructeur par defaut.
 */
ListTache::ListTache()
{
    lstTache = new std::list<Tache *>();
}

/**
 * @details destructeur qui delete tous les pointers de Tache contenu dans lstTache
 */
ListTache::~ListTache()
{
    for (auto tache: *lstTache)
    {
        delete tache;
    }
    delete lstTache;
}

std::list<Tache *> *ListTache::getLstTache() const
{
    return lstTache;
}

void ListTache::setLstTache(std::list<Tache *> *lstTache)
{
    ListTache::lstTache = lstTache;
}


/**
 * @details ajoute la tache en paramètre à la liste des taches.
 * @param tache
 */
void ListTache::addTache(const Tache &tache)
{
    lstTache->push_back(new Tache(tache));
}

/**
 * @details ajoute le pointer tache en paramètre à la liste des taches.
 * @param tache
 */
void ListTache::addTache(Tache *tache)
{
    lstTache->push_back(new Tache(*tache));
}

/**
 * @details destruteur qui détruit tous les pointeurs de tache contenu dans la liste des taches.
 * @param lst
 */
ListTache::ListTache(const ListTache &lst)
{
    lstTache = new std::list<Tache *>();
    for (auto tache: *lst.lstTache)
    {
        addTache(tache);
    }
}

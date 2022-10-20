//
// Created by Rahman  Yilmaz on 20/10/2022.
//

#include "ListTache.h"

ListTache::ListTache()
= default;

/**
 * @details destructeur qui delete tous les pointers de Tache contenu dans lstTache
 */
ListTache::~ListTache()
{
    for(auto tache : lstTache){
        delete tache;
    }
}

void ListTache::addTache(const Tache &tache)
{
    lstTache.push_back(new Tache(tache));
}

void ListTache::addTache(Tache *tache)
{
    lstTache.push_back(new Tache(*tache));
}

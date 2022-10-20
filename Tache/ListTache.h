//
// Created by Rahman  Yilmaz on 20/10/2022.
//

/************************************************
 *  Classe qui sert a stocker toutes les interactions d'un seul contact.
 ***********************************************/

#ifndef PROJET_QT_LISTTACHE_H
#define PROJET_QT_LISTTACHE_H

#include <iostream>
#include <list>
#include "Tache.h"

class ListTache
{
public:
    explicit ListTache();

    ~ListTache();

private:
    std::list<Tache *> lstTache;

public:
    void addTache(const Tache& tache);
    void addTache(Tache *tache);

};


#endif //PROJET_QT_LISTTACHE_H

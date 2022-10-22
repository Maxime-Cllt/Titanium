//
// Created by Rahman  Yilmaz on 20/10/2022.
//

#ifndef PROJET_QT_LISTTACHE_H
#define PROJET_QT_LISTTACHE_H

#include <iostream>
#include <list>
#include "Tache.h"

/**
 * @details Classe ListTache qui stock les objet de type Tache et réalise des operations sur la liste.
 */
class ListTache
{
public:
    explicit ListTache();

    ~ListTache();

    ListTache(const ListTache &);

private:
    std::list<Tache *> *lstTache;

public:
    std::list<Tache *> *getLstTache() const;

    void setLstTache(std::list<Tache *> *lstTache);

    void addTache(const Tache &);

    void addTache(Tache *);

    void suppTache(Tache *);

    friend std::ostream &operator<<(std::ostream &, const ListTache &);

};

#endif //PROJET_QT_LISTTACHE_H

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

    explicit ListTache(uint64_t idInteraction);

    ~ListTache();

    ListTache(const ListTache &listTache);

    enum Sort {Ancien, Recent};

private:
    std::list<Tache *> *lstTache{};
    uint64_t idInteraction{};

public:

    friend std::ostream &operator<<(std::ostream &, const ListTache &);

    [[nodiscard]] uint64_t getIdInteraction() const;

    void setIdInteraction(uint64_t);

    [[nodiscard]] std::list<Tache *> *getLstTache() const;

    void setLstTache(std::list<Tache *> *);

    void addTache(const Tache &);

    void addTache(Tache *);

    void suppTache(Tache *);

    void removeTache(Tache *);

    int size();

    void sort(Sort type);

};

#endif //PROJET_QT_LISTTACHE_H

//
// Created by Rahman  Yilmaz on 14/10/2022.
//

#ifndef PROJET_QT_LISTMODIFICATION_H
#define PROJET_QT_LISTMODIFICATION_H

#include <iostream>
#include <list>
#include "Modification.h"

class ListModification
{
public:
    explicit ListModification();

    ~ListModification();

    void addModif(const Modification &modification);

    void addModif(Modification *modification);

    void sort();

private:
    std::list<Modification *> lst;

};


#endif //PROJET_QT_LISTMODIFICATION_H

//
// Created by Rahman  Yilmaz on 14/10/2022.
//

#ifndef PROJET_QT_MODIFICATIONMAP_H
#define PROJET_QT_MODIFICATIONMAP_H

#include <iostream>
#include <map>
#include "Modification.h"

class ModificationMap
{
public:
    explicit ModificationMap();
    ~ModificationMap();

    void addModif(const Modification &modification);

private:
    std::map<time_t, Modification*> lst;

};


#endif //PROJET_QT_MODIFICATIONMAP_H

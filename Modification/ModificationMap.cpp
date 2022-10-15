//
// Created by Rahman  Yilmaz on 14/10/2022.
//

#include "ModificationMap.h"

ModificationMap::ModificationMap(){}

void ModificationMap::addModif(const Modification &modification)
{
    lst.insert_or_assign(time(nullptr),new Modification(modification));
}

ModificationMap::~ModificationMap()
{

    for(auto [key, elmt] : lst){
        delete elmt;
    }
}

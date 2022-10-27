//
// Created by rahman on 08/10/22.
//

#ifndef PROJET_QT_TRADUCTIONQTSTD_H
#define PROJET_QT_TRADUCTIONQTSTD_H

#include "QtContact.h"
#include "StdContact.h"

class TraductionQtStd
{

public:
    static StdContact QtFicheContactToStdFicheContact(const QtContact &);

    static QtContact StdFicheContacttoQtFicheContact(const StdContact &);

};


#endif //PROJET_QT_TRADUCTIONQTSTD_H

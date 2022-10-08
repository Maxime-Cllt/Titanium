//
// Created by rahman on 08/10/22.
//

#ifndef UNTITLED2_TRADUCTIONQTSTD_H
#define UNTITLED2_TRADUCTIONQTSTD_H

#include "QtFicheContact.h"
#include "StdFicheContact.h"

class TraductionQtStd
{

public:
    static StdFicheContact QtFicheContactToStdFicheContact(const QtFicheContact &contact);

    static QtFicheContact StdFicheContacttoQtFicheContact(const StdFicheContact &contact);

};


#endif //UNTITLED2_TRADUCTIONQTSTD_H

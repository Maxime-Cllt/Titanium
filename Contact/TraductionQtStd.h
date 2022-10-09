//
// Created by rahman on 08/10/22.
//

#ifndef UNTITLED2_TRADUCTIONQTSTD_H
#define UNTITLED2_TRADUCTIONQTSTD_H

#include "QtContact.h"
#include "StdContact.h"

class TraductionQtStd
{

public:
    static StdContact QtFicheContactToStdFicheContact(const QtContact &contact);

    static QtContact StdFicheContacttoQtFicheContact(const StdContact &contact);

};


#endif //UNTITLED2_TRADUCTIONQTSTD_H

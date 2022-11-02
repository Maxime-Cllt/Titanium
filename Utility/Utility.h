//
// Created by rahman on 31/10/22.
//

#ifndef PROJET_QT_UTILITY_H
#define PROJET_QT_UTILITY_H

#include <QWidget>
#include "../Contact/StdContact.h"
#include "../Contact/QtContact.h"

class Utility
{
public:
    explicit Utility();

    static QtContact StdFicheContacttoQtFicheContact(const StdContact &contact);

    static StdContact QtFicheContactToStdFicheContact(const QtContact &contact);

    static QWidget *getMainWindow(QWidget *);

    static QWidget *getWidget(QWidget *, char *);


};


#endif //PROJET_QT_UTILITY_H

//
// Created by rahman on 31/10/22.
//

#ifndef PROJET_QT_UTILITY_H
#define PROJET_QT_UTILITY_H

#include <QWidget>

class Utility
{
public:
    explicit Utility();

    static QWidget *getMainWindow(QWidget *);
    static QWidget *getLstInteractionWidget(QWidget *);


};


#endif //PROJET_QT_UTILITY_H

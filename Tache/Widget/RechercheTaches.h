//
// Created by rahman on 03/11/22.
//

#ifndef PROJET_QT_RECHERCHETACHES_H
#define PROJET_QT_RECHERCHETACHES_H


#include <QDialog>
#include <QGridLayout>
#include <QDateTimeEdit>
#include <QTextEdit>
#include "../../Interaction/ListInteraction.h"

/**
 * @details Classe RechercheTaches qui sert à chercher toutes les taches d'un contact dans un intervalle et les affiche à l’écran.
 */
class RechercheTaches : public QDialog
{
Q_OBJECT

public:
    explicit RechercheTaches(ListInteraction *listInteraction, QWidget *parent = nullptr);

private:
    ListInteraction *lstInteraction{};
    QGridLayout *layout{};
    QDateTimeEdit *debut{};
    QDateTimeEdit *fin{};
    QTextEdit *textEdit{};

    void remplirTextEdit();

};


#endif //PROJET_QT_RECHERCHETACHES_H

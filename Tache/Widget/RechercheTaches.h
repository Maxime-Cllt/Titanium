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

    enum Sort { Recent, Ancien };

private:
    ListInteraction *lstInteraction{};
    QGridLayout *layout{};
    QDateTimeEdit *debut{};
    QDateTimeEdit *fin{};
    QTextEdit *textEdit{};
    int sort = 0;
    bool afficheTachePasse = true;

protected:
    void mousePressEvent(QMouseEvent *event);

private:

    void remplirTextEdit();

public:
    void setSortMode(Sort);

};


#endif //PROJET_QT_RECHERCHETACHES_H

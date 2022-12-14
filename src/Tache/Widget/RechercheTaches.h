//
// Created by rahman on 03/11/22.
//

#ifndef PROJET_QT_RECHERCHETACHES_H
#define PROJET_QT_RECHERCHETACHES_H


#include <QDialog>
#include <QGridLayout>
#include <QDateTimeEdit>
#include <QTextEdit>
#include <QTreeWidget>
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
    /**
     * @brief Classe TreeWidget qui gere l'affichage des taches d'un contact.
     */
    class TreeWidget : public QTreeWidget
    {
    public:
        explicit TreeWidget(ListInteraction *listInteraction, QWidget *parent = nullptr);

        enum Sort
        {
            Recent, Ancien
        };


        void setSortMode(Sort);

        void remplirTextEdit();

        void initDebFin(QDateTime deb, QDateTime fin);

    private:
        ListInteraction *lstInteraction{};
        int sort = 0;
        bool afficheTachePasse = true;

        QDateTime deb;
        QDateTime fin;


    protected:
        void mousePressEvent(QMouseEvent *event) override;

    public:
        void setDeb(QDateTime d);

        void setFin(QDateTime d);

    };

private:
    ListInteraction *lstInteraction{};
    QGridLayout *layout{};
    QDateTimeEdit *debut{};
    QDateTimeEdit *fin{};
    TreeWidget *listWidget{};


};


#endif //PROJET_QT_RECHERCHETACHES_H

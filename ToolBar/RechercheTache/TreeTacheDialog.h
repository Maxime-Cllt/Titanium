//
// Created by rahman on 15/11/22.
//

#ifndef PROJET_QT_TREETACHEDIALOG_H
#define PROJET_QT_TREETACHEDIALOG_H

#include <QTreeWidget>
#include <QDialog>
#include <QGridLayout>
#include "../../Contact/StdListContact.h"

/**
 * @details Classe qui affiche toutes les taches de tous les contacts triés.
 */
class TreeTacheDialog : public QDialog
{
Q_OBJECT

public:
    explicit TreeTacheDialog(StdListContact *lst, QWidget *parent = nullptr);

private:
    /**
     * @brief Classe TreeWidget qui gere l'affichage des taches de tous les contacts.
     */
    class TreeWidget : public QTreeWidget
    {
    public:
        explicit TreeWidget(StdListContact *lst, QWidget *parent = nullptr);

    private:
        StdListContact *listContact;

        bool cachePasse = false;

        void createTache();

    protected:

        void mouseReleaseEvent(QMouseEvent *event) override;
    };

private:

    QGridLayout *lay{};

    StdListContact *listContact{};

    TreeWidget *tree{};


};


#endif //PROJET_QT_TREETACHEDIALOG_H

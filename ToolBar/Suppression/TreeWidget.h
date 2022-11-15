//
// Created by rahman on 15/11/22.
//

#ifndef PROJET_QT_TREEWIDGET_H
#define PROJET_QT_TREEWIDGET_H

#include <QTreeWidget>
#include "../../Contact/StdListContact.h"

/**
 * @details Classe TreeWidget qui gere l’affichage de tous les contacts et de leurs interactions
 * et taches, chaque contact, interaction ou tache peut être supprimé individuellement ou par multi selection.
 */
class TreeWidget : public QTreeWidget
{
Q_OBJECT

public:
    explicit TreeWidget(StdListContact *lst, QWidget *parent = nullptr);

private:
    class TreeItemTache : public QTreeWidgetItem
    {
    public:
        explicit TreeItemTache(Tache *tache, QTreeWidget *parent = nullptr);

    private:
        Tache *tache;
    public:
        Tache *getTache();
    };

    class TreeItemInteraction : public QTreeWidgetItem
    {
    public:
        explicit TreeItemInteraction(Interaction *interaction, QTreeWidget *parent = nullptr);

    private:
        Interaction *interaction;
    public:
        QList<TreeItemTache *> lst;

        Interaction *getInteraction();

        void unselectChild();

    };

    class TreeItemContact : public QTreeWidgetItem
    {
    public:
        explicit TreeItemContact(StdContact *contact, QTreeWidget *parent = nullptr);

    private:
        StdContact *contact;
    public:
        QList<TreeItemInteraction *> lst;

        StdContact *getContact();

        void unselectChild();
    };

private:
    StdListContact *listContact{};

    void addOnTree();

protected:
    void mouseReleaseEvent(QMouseEvent *event) override;

signals:

    void suppClicked(StdListContact *lst);
};

#endif //PROJET_QT_TREEWIDGET_H

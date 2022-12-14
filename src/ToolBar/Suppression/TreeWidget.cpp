//
// Created by rahman on 15/11/22.
//

#include "TreeWidget.h"
#include <QDateTime>
#include <QMenu>
#include <QMouseEvent>
#include <QDebug>
#include "../../BaseDeDonnees/BD.h"
#include "../../MainWindow/MainWindow.h"
#include "../../Utility/Utility.h"

/**
 * @details Constructeur par défaut.
 * @param lst
 * @param parent
 */
TreeWidget::TreeWidget(StdListContact *lst, QWidget *parent) : QTreeWidget(parent), listContact(lst)
{
    setAlternatingRowColors(true);

    setHeaderLabels({"Nom/Contenu", "Prénom", "Téléphone", "Mail", "Date"});
    setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);

    connect(this, &QTreeWidget::itemSelectionChanged, this, [=, this]()
    {
        for (auto item: selectedItems())
        {
            // item Contact
            if (!item->parent())
                reinterpret_cast<TreeItemContact *>(item)->unselectChild();
            else
            {
                // item interaction
                if (!item->parent()->parent())
                {
                    if (!item->parent()->isSelected())
                        reinterpret_cast<TreeItemInteraction *>(item)->unselectChild();
                }
            }
        }
    });

    addOnTree();
}

/**
 * @details Surcharge évènement souris qui fait apparaitre un menu avec un click droit.
 * @param event
 */
void TreeWidget::mouseReleaseEvent(QMouseEvent *event)
{
    QTreeView::mouseReleaseEvent(event);
    if (event->button() == Qt::RightButton)
    {
        if (!selectedItems().empty())
        {
            QMenu menu;

            QAction act1("Supprimer");
            connect(&act1, &QAction::triggered, this, [=, this]()
            {
                StdListContact lst;
                for (auto item: selectedItems())
                {
                    // item Contact
                    if (!item->parent())
                    {
                        lst.addContact(reinterpret_cast<TreeItemContact *>(item)->getContact());
                    } else
                    {
                        // item interaction
                        if (!item->parent()->parent())
                        {
                            if (!item->parent()->isSelected())
                            {
                                BD::supInteraction(*reinterpret_cast<TreeItemInteraction *>(item)->getInteraction());
                                qobject_cast<MainWindow *>(Utility::getMainWindow(this))->getHistorique()->addLog(
                                        ListHistorique::SuppressionInteraction,
                                        *reinterpret_cast<TreeItemInteraction *>(item)->getInteraction());
                                reinterpret_cast<TreeItemContact *>(item->parent())->getContact()->getLstInteraction()->supInteraction(
                                        reinterpret_cast<TreeItemInteraction *>(item)->getInteraction());
                            }

                            // item tache
                        } else
                        {
                            if (!item->parent()->isSelected() and !item->parent()->parent()->isSelected())
                            {
                                BD::supTache(*reinterpret_cast<TreeItemTache *>(item)->getTache());
                                reinterpret_cast<TreeItemInteraction *>(item->parent())->getInteraction()->getLstTache()->suppTache(
                                        reinterpret_cast<TreeItemTache *>(item)->getTache());
                            }
                        }
                    }
                }
                emit suppClicked(&lst);
                lst.clear();
                addOnTree();
            });

            menu.addAction(&act1);
            menu.exec(event->globalPos());

        }
    }
}

/**
 * @details Fonction qui ajoute au QTreeWidget tous les contacts, les interactions de chaque contact et les tache de chaque interaction.
 */
void TreeWidget::addOnTree()
{
    clear();

    // on tri pour que les contacts en haut de la list se retrouve en haut de QTreeWidget
    listContact->sort(StdListContact::Sort::DateCroissant);

    for (auto contact: *listContact->getLstContact())
    {
        auto *item = new TreeItemContact(contact, this);

        for (auto interaction: *contact->getLstInteraction()->getListInteraction())
        {
            auto *item1 = new TreeItemInteraction(interaction);

            for (auto tache: *interaction->getLstTache()->getLstTache())
            {
                auto *item2 = new TreeItemTache(tache);
                item1->lst.append(item2);
                item1->addChild(item2);
            }
            item->addChild(item1);
            item->lst.append(item1);
        }
        addTopLevelItem(item);
    }

}

/**
 * @details Constructeur par défaut de TreeItemContact.
 * @param contact
 * @param parent
 */
TreeWidget::TreeItemContact::TreeItemContact(StdContact *contact, QTreeWidget *parent) : contact(contact),
                                                                                         QTreeWidgetItem(parent)
{
    setText(0, QString::fromStdString(contact->getNom()));
    setText(1, QString::fromStdString(contact->getPrenom()));
    setText(2, QString::fromStdString(contact->getTelephone()));
    setText(3, QString::fromStdString(contact->getMail()));
    QDateTime date;
    date.setMSecsSinceEpoch((qint64) contact->getDateCreation() / 1000);
    setText(4, date.toString("dd/MM/yyyy hh:mm:ss"));
}

/**
 * @brief Getter de contact.
 * @return
 */
StdContact *TreeWidget::TreeItemContact::getContact()
{
    return contact;
}

/**
 * @brief Fonction qui désélectionne tous les enfants item de l'item.
 */
void TreeWidget::TreeItemContact::unselectChild()
{
    for (auto item: lst)
    {
        item->setSelected(false);
        reinterpret_cast<TreeItemInteraction *>(item)->unselectChild();
    }

}

/**
 * @details Constructeur par défaut de TreeItemInteraction.
 * @param interaction
 * @param parent
 */
TreeWidget::TreeItemInteraction::TreeItemInteraction(Interaction *interaction, QTreeWidget *parent) : interaction(
        interaction),
                                                                                                      QTreeWidgetItem(
                                                                                                              parent)
{
    setText(0, QString::fromStdString(interaction->getContenu()));
    QDateTime date;
    date.setMSecsSinceEpoch((qint64) interaction->getDateCreation() / 1000);
    setText(4, date.toString("dd/MM/yyyy hh:mm:ss"));
}

/**
 * @brief Fonction qui désélectionne tous les enfants item de l'item.
 */
void TreeWidget::TreeItemInteraction::unselectChild()
{
    for (auto item: lst)
    {
        item->setSelected(false);
    }
}

/**
 * @brief Getter de interaction.
 * @return
 */
Interaction *TreeWidget::TreeItemInteraction::getInteraction()
{
    return interaction;
}

/**
 * @details Constructeur de TreeItemTache.
 * @param tache
 * @param parent
 */
TreeWidget::TreeItemTache::TreeItemTache(Tache *tache, QTreeWidget *parent) : tache(tache),
                                                                              QTreeWidgetItem(
                                                                                      parent)
{

    setText(0, QString::fromStdString(tache->getContenuWithoutTodo()));
    QDateTime date;
    date.setMSecsSinceEpoch((qint64) tache->getdate() / 1000);
    setText(4, date.toString("dd/MM/yyyy hh:mm:ss"));

}

/**
 * @brief Getter de Tache.
 * @return
 */
Tache *TreeWidget::TreeItemTache::getTache()
{
    return tache;
}

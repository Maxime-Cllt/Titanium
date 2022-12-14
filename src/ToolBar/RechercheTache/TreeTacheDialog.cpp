//
// Created by rahman on 15/11/22.
//

#include "TreeTacheDialog.h"
#include <QDateTime>
#include <map>
#include <QMouseEvent>
#include <QMenu>
#include <QApplication>

/**
 * @brief Constructeur par défaut.
 * @param lst
 * @param parent
 */
TreeTacheDialog::TreeTacheDialog(StdListContact *lst, QWidget *parent) : QDialog(parent), listContact(lst)
{
    setWindowTitle("Recherche de tache");

    lay = new QGridLayout(this);

    tree = new TreeWidget(lst, this);

    lay->addWidget(tree, 0, 0);

}

/**
 * @brief Constructeur par défaut de TreeWidget .
 * @param lst
 * @param parent
 */
TreeTacheDialog::TreeWidget::TreeWidget(StdListContact *lst, QWidget *parent) : QTreeWidget(parent), listContact(lst)
{
    setAlternatingRowColors(true);
    setHeaderLabels({"Contenu", "Date"});
    setMinimumSize(500, 400);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setColumnWidth(0, 300);

    createTache();
}

/**
 * @details Fonction qui ajoute au treeWidget les taches de tous les contacts.
 */
void TreeTacheDialog::TreeWidget::createTache()
{
    std::map<Tache *, StdContact *> map;

    // parcours de tous les contacts
    for (auto contact: *listContact->getLstContact())
    {
        for (auto interaction: *contact->getLstInteraction()->getListInteraction())
        {
            for (auto tache: *interaction->getLstTache()->getLstTache())
            {
                // si l'option cacher les taches passées est activé on n’ajoute pas la tache à la map.
                if (cachePasse)
                    if ((QDateTime::currentMSecsSinceEpoch() * 1000) > tache->getdate())
                        continue;
                map.emplace(tache, contact);
            }
        }
    }
    // declaration d’une liste pour trier toutes les taches.
    std::list<std::pair<Tache *, StdContact *> > pairs;

    for (auto pair: map)
    {
        pairs.emplace_back(pair);
    }

    // tri
    pairs.sort([=](std::pair<Tache *, StdContact *> &a, std::pair<Tache *, StdContact *> &b)
               {
                   return *a.first < *b.first;
               });

    QDateTime date;
    // creation des treeWidgetItems
    for (auto pair: pairs)
    {
        auto *item = new QTreeWidgetItem(this);
        item->setText(0, QString::fromStdString(pair.first->getContenuWithoutTodo()));
        date.setMSecsSinceEpoch((qint64) pair.first->getdate() / 1000);
        item->setText(1, date.toString("dd/MM/yyyy hh:mm:ss"));
        addTopLevelItem(item);

        auto *item1 = new QTreeWidgetItem;
        item1->setText(0, QString::fromStdString(pair.second->getNom() + " | " + pair.second->getPrenom()));
        item1->setText(1, QString::fromStdString(pair.second->getMail()));
        item->addChild(item1);
    }
}

/**
 * @details Surcharge de la souris. Un click droit d’éclanche un menu dans lequel il
 * est possible de choisir d’afficher ou non les taches passées.
 * @param event
 */
void TreeTacheDialog::TreeWidget::mouseReleaseEvent(QMouseEvent *event)
{
    QTreeView::mouseReleaseEvent(event);
    if (event->button() == Qt::MouseButton::RightButton)
    {
        QMenu menu;

        QAction act1("Cacher les tâches passées.");

        if (cachePasse)
            act1.setIcon(QApplication::style()->standardIcon(QStyle::SP_DialogApplyButton));

        connect(&act1, &QAction::triggered, this, [=, this]()
        {
            cachePasse = !cachePasse;
            this->clear();
            createTache();
        });

        menu.addAction(&act1);

        menu.exec(event->globalPos());
    }
}

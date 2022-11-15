//
// Created by rahman on 15/11/22.
//

#include "TreeWidget.h"
#include <QDateTime>
#include <QMenu>
#include <QMouseEvent>
#include <QDebug>


TreeWidget::TreeWidget(StdListContact *lst, QWidget *parent) : QTreeWidget(parent) , listContact(lst)
{
    setAlternatingRowColors(true);

    setHeaderLabels({"Nom", "Prénom", "Téléphone", "Mail", "Date"});
    setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);

    addOnTree();
}

void TreeWidget::mouseReleaseEvent(QMouseEvent *event)
{
    QTreeView::mouseReleaseEvent(event);
    if(event->button() == Qt::RightButton){
        if(!selectedItems().empty()){
            QMenu menu;

            QAction act1("Supprimer");
            connect(&act1,&QAction::triggered, this,[=,this](){
                StdListContact lst;
                for( auto item : selectedItems())
                    lst.addContact(reinterpret_cast<TreeItemContact *>(item)->getContact());
                emit suppClicked(&lst);
                lst.getLstContact()->clear();
                addOnTree();
            });

            menu.addAction(&act1);
            menu.exec(event->globalPos());

        }
    }
}

void TreeWidget::addOnTree()
{
    clear();

    for(auto contact : *listContact->getLstContact()){
        auto *item = new TreeItemContact(contact, this);
        item->setText(0,QString::fromStdString(contact->getNom()));
        item->setText(1,QString::fromStdString(contact->getPrenom()));
        item->setText(2,QString::fromStdString(contact->getTelephone()));
        item->setText(3,QString::fromStdString(contact->getMail()));
        QDateTime date;
        date.setMSecsSinceEpoch((qint64) contact->getDateCreation() /1000);
        item->setText(4,date.toString("dd/MM/yyyy hh:mm:ss"));

        addTopLevelItem(item);
    }

}

TreeWidget::TreeItemContact::TreeItemContact(StdContact *contact, QTreeWidget *parent) : contact(contact),
                                                                             QTreeWidgetItem(parent)
{
}

StdContact *TreeWidget::TreeItemContact::getContact() const
{
    return contact;
}


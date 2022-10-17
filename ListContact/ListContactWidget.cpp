//
// Created by Rahman  Yilmaz on 06/10/2022.
//

#include "GroupeBoxContact.h"
#include "ListContactWidget.h"
#include "../MainWindow/MainWindow.h"

#include <QLabel>
#include <QLineEdit>


/**
 *  @details Constructeur de la classe ListContactWidget
 * @param parent
 */
ListContactWidget::ListContactWidget(QWidget *parent) : QWidget(parent)
{

    lay = new QVBoxLayout(this);

    scrollArea = new QScrollArea(this);
    scrollArea->setStyleSheet("QScrollArea{border: none;}");
    scrollAreaWidget = new QWidget;
    layScrollArea = new QVBoxLayout(scrollAreaWidget);

    scrollArea->setWidget(scrollAreaWidget);
    scrollArea->setWidgetResizable(true);
    scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    lay->addWidget(scrollArea);


    for (auto contact: *(qobject_cast<MainWindow *>(parent)->getLstContact())->getLstContact())
    {
        layScrollArea->addWidget(new GroupeBoxContact(contact, this));
    }

}

/**
 * @param contact
 */
void ListContactWidget::addContactBox(StdContact *contact)
{
    layScrollArea->addWidget(new GroupeBoxContact(contact, scrollArea));
}

/**
 * @details Fonction qui cache la Liste des interactions d'un contact s'il n'est plus selectionné, et envoie au MainWindow
 * la nouvelle liste de inetraction du contact selectionné.
 * @param lastConctactselected
 */
void ListContactWidget::setLastConctactselected(GroupeBoxContact *lastConctactselected)
{
    //on regarde que la liste des inetractions qui est deja afficher est differente de lastConctactselected.
    if (this->lastConctactselected != lastConctactselected)
    {
        // si le pointeur n'est pas null on cache le widget.
        if (this->lastConctactselected)
        {
            this->lastConctactselected->cache();
        }
        // envoie au MainWindow qui set charge de l'ajouter a son propre layout.
        qobject_cast<MainWindow *>(parentWidget()->parentWidget())->setListInteractionWidget(
                lastConctactselected->getListInteractionWidget());
        //on remplace la liste des interaction par la nouvelle du contact selectionné
        this->lastConctactselected = lastConctactselected;
    }
}

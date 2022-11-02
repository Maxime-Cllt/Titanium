//
// Created by Rahman  Yilmaz on 06/10/2022.
//

#include "GroupeBoxContact.h"
#include "ListContactWidget.h"
#include "../../MainWindow/MainWindow.h"
#include "../../Utility/Utility.h"

#include <QLabel>
#include <QLineEdit>


/**
 *  @details Constructeur de la classe ListContactWidget
 * @param parent
 */
ListContactWidget::ListContactWidget(StdListContact *lst, QWidget *parent) : QWidget(parent) {
    lstContact = lst;

    setMinimumWidth(500);
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
    layScrollArea->setSpacing(30);


    recreateGroupeBoxContact();

}

/**
 * @brief Ajoute un GroupeBoxContact crée à partir du contact en parameter au layout.
 * @param contact
 */
void ListContactWidget::addContactBox(StdContact *contact) {
    auto *box = new GroupeBoxContact(contact, this);
    layScrollArea->insertWidget(0, box);
    connect(box, &GroupeBoxContact::supBtnClicled, this, [=, this](StdContact *contact) {
        lstContact->removeContact(contact);
    });
}

/**
 * @details Fonction qui cacheInteractions la Liste des interactions d'un contact s'il n'est plus sélectionné, et envoie au MainWindow
 * la nouvelle liste des interactions du contact sélectionné.
 * @param lastConctactselected
 */
void ListContactWidget::setLastConctactselected(GroupeBoxContact *lastConctactselected) {
    //on regarde que la liste des interactions qui est deja afficher est differente de lastConctactselected.
    if (this->lastConctactselected != lastConctactselected) {
        // si le pointeur n'est pas null on cache le widget.
        if (this->lastConctactselected) {
            this->lastConctactselected->cacheInteractions();
        }
        // envoie au MainWindow qui se charge de l'ajouter a son propre layout.
        qobject_cast<MainWindow *>(Utility::getMainWindow(this))->setListInteractionWidget(
                lastConctactselected->getListInteractionWidget());
        //on remplace la liste des interactions par la nouvelle du contact selectionné
        this->lastConctactselected = lastConctactselected;
        this->lastConctactselected->afficheInteractions();
    } else {
        this->lastConctactselected->cacheOuAfficheInteractions();
    }
}

/**
 * @brief Setter de lstContact.
 * @return lstContact
 */
StdListContact *ListContactWidget::getLstContact() const {
    return lstContact;
}

/**
 * @brief Cache les groupeBoxContact qui ont un contact contenu dans la liste de contacts lst en paramètre.
 * @param lst
 */
void ListContactWidget::cacheGroupeBox(StdListContact *lst) {
    lstWidget.clear();
    for (auto contact: *lst->getLstContact()) {
        for (auto widget: findChildren<GroupeBoxContact *>()) {
            if (widget->getContact() == contact) {
                widget->show();
                lstWidget << widget;
                break;
            }
        }
    }

    for (auto widget: findChildren<GroupeBoxContact *>()) {
        if (!lstWidget.contains(widget)) {
            widget->hide();
        }
    }
}

/**
 * @brief Affiche tous les groupeBoxContact.
 */
void ListContactWidget::afficheAllGroupeBox() {

    for (auto widget: findChildren<GroupeBoxContact *>())
        widget->show();
}

void ListContactWidget::recreateGroupeBoxContact() {

    for (auto widget: findChildren<GroupeBoxContact *>())
        delete widget;

    for (auto contact: *lstContact->getLstContact()) {
        auto *box = new GroupeBoxContact(contact, this);
        layScrollArea->addWidget(box);
        connect(box, &GroupeBoxContact::supBtnClicled, this, [=, this](StdContact *contact) {
            lstContact->removeContact(contact);
        });
    }
}

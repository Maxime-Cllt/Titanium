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
ListContactWidget::ListContactWidget(StdListContact *lst, QWidget *parent) : lstContact(lst), QWidget(parent)
{
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
void ListContactWidget::addContactBox(StdContact *contact, bool visibility)
{
    auto *box = new GroupeBoxContact(contact, this);
    box->setVisible(visibility);
    layScrollArea->insertWidget(0, box);
    connect(box, &GroupeBoxContact::supBtnClicled, this, [=, this](StdContact *contact)
    {
        emit suppContact(contact);
    });
    connect(box, &GroupeBoxContact::resetLastConctactselected, this, &ListContactWidget::resetLastConctactselected);
    connect(box, &GroupeBoxContact::setContactSelected, this, &ListContactWidget::setLastConctactselected);
    connect(box, &GroupeBoxContact::interactionShowedOrHided, this, &ListContactWidget::interactionWidgetsHideOrShow);
}

/**
 * @details Fonction qui cacheInteractions la Liste des interactions d'un contact s'il n'est plus sélectionné, et envoie au MainWindow
 * la nouvelle liste des interactions du contact sélectionné.
 * @param lastConctactselected
 */
void ListContactWidget::setLastConctactselected(GroupeBoxContact *lastConctactselected)
{

    // si le GroupeBoxContact a été supprimer, il ne faut pas cacher un Widget qui n'existe plus.
    if (lastConctactselected == nullptr)
    {
        this->lastConctactselected = nullptr;
        return;
    }
    //on regarde que la liste des interactions qui est deja afficher est differente de lastConctactselected.
    if (this->lastConctactselected != lastConctactselected)
    {
        // si le pointeur n'est pas null on cache le Widget.
        if (this->lastConctactselected)
            this->lastConctactselected->cacheInteractions();

        // envoie au MainWindow qui se charge de l'ajouter a son propre layout.
        emit contactSelected(lastConctactselected);

        //on remplace la liste des interactions par la nouvelle du contact selectionné
        this->lastConctactselected = lastConctactselected;
        this->lastConctactselected->afficheInteractions();
    } else
    {
        this->lastConctactselected->cacheOuAfficheInteractions();
    }
}

/**
 * @brief Setter de lstContact.
 * @return lstContact
 */
StdListContact *ListContactWidget::getLstContact() const
{
    return lstContact;
}

/**
 * @brief Cache les groupeBoxContact qui ont un contact contenu dans la liste de contacts lst en paramètre.
 * @param lst
 */
void ListContactWidget::cacheGroupeBox(StdListContact *lst)
{
    QWidgetList lstWidget;
    for (auto contact: *lst->getLstContact())
    {
        for (auto widget: findChildren<GroupeBoxContact *>())
        {
            if (widget->getContact() == contact)
            {
                widget->show();
                lstWidget << widget;
                break;
            }
        }
    }

    for (auto widget: findChildren<GroupeBoxContact *>())
    {
        if (!lstWidget.contains(widget))
        {
            widget->hide();
        }
    }
}

/**
 * @brief Affiche tous les groupeBoxContact.
 */
void ListContactWidget::afficheAllGroupeBox()
{

    for (auto widget: findChildren<GroupeBoxContact *>())
        widget->show();
}

/**
 * @brief Focntion qui supprime les GroupeBoxContact actuelle, puis en recréer des nouvelles et les ajoute au layout,
 * cette fonction est appelé quand on tri la liste et que l'on doit réafficher correctement les contacts.
 */
void ListContactWidget::recreateGroupeBoxContact()
{
    // comme tous les GroupeBoxContact vont etre supprimé ont reset le pointeur du dernier contact selectionné.
    resetLastConctactselected();

    QList<StdContact *> lst;

    for (auto widget: findChildren<GroupeBoxContact *>())
    {
        if (widget->isHidden())
            lst << widget->getContact();
        widget->close();
    }

    for (auto contact: *lstContact->getLstContact())
        addContactBox(contact, !lst.contains(contact));
}

/**
 * @brief Fonction qui remet a nullptr lastConctactselected et cache la liste des interactions du dernier contact selectionné s’il existe.
 */
void ListContactWidget::resetLastConctactselected()
{
    if (lastConctactselected)
    {
//        this->lastConctactselected->getListInteractionWidget()->hide();
        this->lastConctactselected->resetStyleSheet();
        emit resetLastConctact();
    }
    this->lastConctactselected = nullptr;
}

/**
 * @brief Fonction qui envoie un signal, avec true si le widget des interactions est affiché ou false s’il n'est pas affiché.
 * @param show
 */
void ListContactWidget::interactionWidgetsHideOrShow(bool show)
{
    emit interactionWidgetsHidedOrShowed(show);
}


/**
 * @details Retourne le nombre de GroupeBoxContact visible.
 * @return compteur
 */
size_t ListContactWidget::getNbGroupeBoxVisible() const
{
    size_t compteur = 0;

    for (auto widget: findChildren<GroupeBoxContact *>())
    {
        if (widget->isVisible())
            compteur++;
    }
    return compteur;
}

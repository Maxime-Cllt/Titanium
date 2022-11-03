//
// Created by Rahman  Yilmaz on 06/10/2022.
//

#include "GroupeBoxContact.h"

#include <QLabel>
#include "../../ContactDialog/ModifContactDialog.h"
#include "../../Interaction/Widget/CreationInteractionDialog.h"
#include "../../BaseDeDonne/BD.h"
#include "../../MainWindow/MainWindow.h"
#include "ListContactWidget.h"
#include "../../Tache/Widget/RechercheTaches.h"


/**
 * @details Constructeur de la classe GroupeBoxContact
 * @param contact
 * @param parent
 */
GroupeBoxContact::GroupeBoxContact(StdContact *contact, QWidget *parent) : QGroupBox(parent), contact(contact)
{

    QLocale local(QLocale::Language::French);
    QDateTime date;
    date.setMSecsSinceEpoch(this->contact->getDateCreation() / 1000);
    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);


    setObjectName("GroupBoxContact");


    layout = new QGridLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    layout->setSpacing(20);

    auto *labTitre = new QLabel("Date de creation : " + local.toString(date, "dddd, d MMMM yyyy hh:mm:ss"), this);
    labTitre->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    labTitre->setWordWrap(false);
    labTitre->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    layout->addWidget(labTitre, 0, 0, 1, 3);


    createUi();

    for (auto lab: findChildren<QLabel *>())
    {
        lab->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        lab->setWordWrap(true);
        lab->setMinimumWidth(150);
    }
    findChildren<QLabel *>()[1]->setFixedWidth(75);

}


/**
 *
 * @param event
 */
void GroupeBoxContact::mousePressEvent(QMouseEvent *event)
{
    QGroupBox::mousePressEvent(event);
    setStyleSheet(
            "QGroupBox#GroupBoxContact{background-color: gray;color : white;border-radius : 10px;}");
    for (auto lab: findChildren<QLabel *>()){
        if(lab->parent() == this)
            lab->setStyleSheet("color : white;");
    }

    if (event->button() == Qt::RightButton)
    {
        if (listInteractionWidget != nullptr)
            listInteractionWidget->cache();

        auto *menu = new QMenu(this);

        auto *action1 = new QAction("Ajouter une interaction");

        auto *action2 = new QAction("Modifier");

        auto *action3 = new QAction("Supprimer");

        auto *action4 = new QAction("Chercher un todo");

        menu->addAction(action1);
        menu->addAction(action2);
        menu->addAction(action3);
        menu->addAction(action4);

        connect(action1, &QAction::triggered, this, [=, this]()
        {
            if(!listInteractionWidget)
                listInteractionWidget = new ListInteractionWidget(contact->getLstInteraction(), this);
            CreationInteractionDialog diag(this);
            connect(&diag, &CreationInteractionDialog::addInteractionClicked, listInteractionWidget,
                    &ListInteractionWidget::addInteraction1);
            diag.exec();
        });

        connect(action2, &QAction::triggered, this, [=, this]()
        {
            ModifContactDialog modif(this->contact, this);
            modif.exec();
        });

        connect(action3, &QAction::triggered, this, [=, this]()
        {
            BD::supContact(*contact);
            qobject_cast<MainWindow *>(Utility::getMainWindow(this))->suppContact(contact);
            emit supBtnClicled(contact);
            qobject_cast<ListContactWidget *>(
                    Utility::getWidget(this, (char *) "ListContactWidget"))->resetLastConctactselected();
            close();
        });

        connect(action4, &QAction::triggered, this, [=, this]()
        {
            RechercheTaches diag(contact->getLstInteraction(), this);
            diag.exec();
        });

        menu->exec(event->globalPos());

        setStyleSheet("");
        for (auto lab: findChildren<QLabel *>())
            lab->setStyleSheet("");
    }
}


/**
 * @details Quand le click gauche est release,
 * On creé une listInteractionWidget si elle pas deja été crée,
 * si elle existe deja on l'affiche par la fonction show.
 * @param event
 */
void GroupeBoxContact::mouseReleaseEvent(QMouseEvent *event)
{
    QGroupBox::mouseReleaseEvent(event);
    if (event->button() == Qt::LeftButton)
    {
        if (!listInteractionWidget)
            listInteractionWidget = new ListInteractionWidget(contact->getLstInteraction(), this);

        qobject_cast<ListContactWidget *>(
                Utility::getWidget(this, (char *) "ListContactWidget"))->setLastConctactselected(this);
    }

}

/**
 * @details Actualise les donnés
 */
void GroupeBoxContact::reactualiseDonne()
{
    QtContact qtContact(Utility::StdFicheContacttoQtFicheContact(*contact));

    if(QFile(qtContact.getPhoto()).exists()){
        QPixmap im(qtContact.getPhoto());
        findChildren<QLabel *>()[0]->setPixmap(im.scaled(50, 50, Qt::KeepAspectRatio));
    }
    findChildren<QLabel *>()[1]->setText("Nom Prénom : " + qtContact.getNom() + " " + qtContact.getPrenom());
    findChildren<QLabel *>()[2]->setText("Entreprise : " + qtContact.getEntreprise());
    findChildren<QLabel *>()[3]->setText("Mail : " + qtContact.getMail());
    findChildren<QLabel *>()[4]->setText("Téléphone : " + qtContact.getTelephone());

}

/**
 * @details Creation de l'interface pour la fiche d'un contact
 */
void GroupeBoxContact::createUi()
{
    QtContact qtContact(Utility::StdFicheContacttoQtFicheContact(*contact));

    if(QFile(qtContact.getPhoto()).exists())
    {
        QPixmap im(qtContact.getPhoto());
        auto *labIm = new QLabel(this);
        labIm->setPixmap(im.scaled(75, 75, Qt::KeepAspectRatio));
        layout->addWidget(labIm, 1, 0, 2, 1);
    }
    layout->addWidget(new QLabel("Nom Prénom : " + qtContact.getNom() + " " + qtContact.getPrenom(), this), 1, 1, 1, 1);
    layout->addWidget(new QLabel("Entreprise : " + qtContact.getEntreprise(), this), 1, 2, 1, 1);
    layout->addWidget(new QLabel("Mail : " + qtContact.getMail(), this), 2, 1, 1, 1);
    layout->addWidget(new QLabel("Téléphone : " + qtContact.getTelephone(), this), 2, 2, 1, 1);

}

/**
 * @details Fonction qui cacheInteractions le Widget des Interactions.
 * @return Retourne vrais si le Widget est caché, non si elle est visible.
 */
void GroupeBoxContact::cacheOuAfficheInteractions()
{
    if (listInteractionWidget->isVisible())
        cacheInteractions();
    else
        afficheInteractions();
}

/**
 *
 * @return listInteractionWidget
 */
ListInteractionWidget *GroupeBoxContact::getListInteractionWidget()
{
    return listInteractionWidget;
}

StdContact *GroupeBoxContact::getContact() const
{
    return contact;
}

void GroupeBoxContact::cacheInteractions()
{
    listInteractionWidget->setVisible(false);
    setStyleSheet("");
    for (auto lab: findChildren<QLabel *>())
        lab->setStyleSheet("");
    qobject_cast<MainWindow *>(Utility::getMainWindow(this))->setNbInteraction("");

}

void GroupeBoxContact::afficheInteractions()
{
    listInteractionWidget->setVisible(true);
    qobject_cast<MainWindow *>(Utility::getMainWindow(this))->setNbInteraction(
            QString::number(getContact()->getLstInteraction()->size()));
}


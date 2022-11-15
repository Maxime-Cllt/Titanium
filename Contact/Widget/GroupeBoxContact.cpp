//
// Created by Rahman  Yilmaz on 06/10/2022.
//

#include "GroupeBoxContact.h"

#include <QLabel>
#include "../../ContactDialog/ModifContactDialog.h"
#include "../../Interaction/Widget/CreationInteractionDialog.h"
#include "../../BaseDeDonnees/BD.h"
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

    setAttribute(Qt::WA_DeleteOnClose);

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
    labImage->setFixedWidth(75);

}


/**
 *@brief Capture des click de la souris.
 * @param event
 */
void GroupeBoxContact::mousePressEvent(QMouseEvent *event)
{
    QGroupBox::mousePressEvent(event);
    setStyleSheet(
            "QGroupBox#GroupBoxContact{background-color: gray;color : white;border-radius : 10px;}");
    for (auto lab: findChildren<QLabel *>())
    {
        if (lab->parent() == this)
            lab->setStyleSheet("color : white;");
    }

    if (event->button() == Qt::RightButton)
    {
        if (listInteractionWidget != nullptr)
            listInteractionWidget->cache();

        emit resetLastConctactselected();

        setStyleSheet(
                "QGroupBox#GroupBoxContact{background-color: gray;color : white;border-radius : 10px;}");
        for (auto lab: findChildren<QLabel *>())
        {
            if (lab->parent() == this)
                lab->setStyleSheet("color : white;");
        }

        auto *menu = new QMenu(this);

        auto *action1 = new QAction("Ajouter une interaction");

        auto *action2 = new QAction("Modifier");

        auto *action3 = new QAction("Supprimer");

        auto *action4 = new QAction("Chercher un todo");

        menu->addAction(action1);
        menu->addAction(action2);
        menu->addAction(action3);
        menu->addAction(action4);

        connect(action1, &QAction::triggered, this, &GroupeBoxContact::menu1Triggered);

        connect(action2, &QAction::triggered, this, [=, this]()
        {
            ModifContactDialog modif(this->contact, this);
            connect(&modif, &ModifContactDialog::dataModified, this, &GroupeBoxContact::reactualiseDonne);
            modif.exec();
        });

        connect(action3, &QAction::triggered, this, &GroupeBoxContact::menu3Triggered);

        connect(action4, &QAction::triggered, this, [=, this]()
        {
            RechercheTaches diag(contact->getLstInteraction(), this);
            diag.exec();
        });

        menu->exec(event->globalPos());

        resetStyleSheet();
    }
}


/**
 * @details Quand le click gauche est release,
 * On crée une listInteractionWidget si elle n’est pas deja été crée,
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

        emit setContactSelected(this);

    }

}

/**
 * @details Actualise les donnés et modifie les labels en consequence.
 */
void GroupeBoxContact::reactualiseDonne()
{
    QtContact qtContact(Utility::StdFicheContacttoQtFicheContact(*contact));

    if (QFile(qtContact.getPhoto()).exists())
    {
        QPixmap im(qtContact.getPhoto());
        labImage->setPixmap(im.scaled(50, 50, Qt::KeepAspectRatio));
    }
    labNomPrenom->setText("Nom Prénom : " + qtContact.getNom() + " " + qtContact.getPrenom());
    labEntreprise->setText("Entreprise : " + qtContact.getEntreprise());
    labMail->setText("Mail : " + qtContact.getMail());
    labTel->setText("Téléphone : " + qtContact.getTelephone());

}

/**
 * @details Creation de l'interface pour la fiche d'un contact
 */
void GroupeBoxContact::createUi()
{
    QtContact qtContact(Utility::StdFicheContacttoQtFicheContact(*contact));

    labImage = new QLabel(this);
    if (QFile(qtContact.getPhoto()).exists())
    {
        QPixmap im(qtContact.getPhoto());
        labImage->setPixmap(im.scaled(75, 75, Qt::KeepAspectRatio));
    }
    layout->addWidget(labImage, 1, 0, 2, 1);

    labNomPrenom = new QLabel("Nom Prénom : " + qtContact.getNom() + " " + qtContact.getPrenom(), this);
    layout->addWidget(labNomPrenom, 1, 1, 1, 1);

    labEntreprise = new QLabel("Entreprise : " + qtContact.getEntreprise(), this);
    layout->addWidget(labEntreprise, 1, 2, 1, 1);

    labMail = new QLabel("Mail : " + qtContact.getMail(), this);
    layout->addWidget(labMail, 2, 1, 1, 1);

    labTel = new QLabel("Téléphone : " + qtContact.getTelephone(), this);
    layout->addWidget(labTel, 2, 2, 1, 1);

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

/**
 * @brief Getter de contact.
 * @return
 */
StdContact *GroupeBoxContact::getContact() const
{
    return contact;
}

/**
 * @brief Cache le widget des interactions.
 */
void GroupeBoxContact::cacheInteractions()
{
    listInteractionWidget->hide();
    resetStyleSheet();
    emit interactionShowedOrHided(false);
}

/**
 * @brief Affiche le widget des interactions.
 */
void GroupeBoxContact::afficheInteractions()
{
    listInteractionWidget->show();
    emit interactionShowedOrHided(true);
}

/**
 * @brief Remet à zero le stylesheet du widget et de ses QLabels.
 */
void GroupeBoxContact::resetStyleSheet()
{
    setStyleSheet("");
    for (auto lab: findChildren<QLabel *>())
        lab->setStyleSheet("");
}

/**
 * @brief Click sur l'action "Ajouter une interaction"
 */
void GroupeBoxContact::menu1Triggered()
{
    if (!listInteractionWidget)
        listInteractionWidget = new ListInteractionWidget(contact->getLstInteraction(), this);
    CreationInteractionDialog diag(this);
    connect(&diag, &CreationInteractionDialog::addInteractionClicked, listInteractionWidget,
            &ListInteractionWidget::addInteraction1);
    diag.exec();
}

/**
 * @brief Click sur l'action "Supprimer"
 */
void GroupeBoxContact::menu3Triggered()
{
    BD::supContact(*contact);
    emit supBtnClicled(contact);
    emit resetLastConctactselected();
    QMessageBox::information(nullptr, "Suppression", "Suppression réalisée avec succès.");
    close();
}

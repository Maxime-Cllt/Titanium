//
// Created by rahman on 01/11/22.
//

#include "TollBar.h"
#include "../ContactDialog/CreationContactDialog.h"
#include "RechercheContact/RechercheContactDialog.h"
#include "../Utility/Utility.h"


/**
 * @brief Constructeur par défaut de la classe TollBar.
 * @param parent
 */
TollBar::TollBar(QWidget *parent) : QToolBar(parent)
{

    setContextMenuPolicy(Qt::ActionsContextMenu);

    ajouter = new QAction("Ajouter un contact", this);
    ajouter->setIcon(QIcon("../src/ajouter.png"));
    ajouter->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_A));
    addAction(ajouter);

    connect(ajouter, &QAction::triggered, this, &TollBar::ajouterContact);

    addSeparator();

    chercher = new QAction("Chercher un contact", this);
    chercher->setIcon(QIcon("../src/chercher.png"));
    addAction(chercher);

    connect(chercher, &QAction::triggered, this, &TollBar::chercherContact);

    addSeparator();

    createTriBtn();

    addSeparator();

    resetListContactsWidget = new QAction("Afficher tous les contacts", this);
    resetListContactsWidget->setIcon(QIcon("../src/reset.png"));
    addAction(resetListContactsWidget);

    connect(resetListContactsWidget, &QAction::triggered, this, &TollBar::resetActionTriggered);

    addSeparator();

    historique = new QAction("Historique", this);
    historique->setIcon(QIcon("../src/historique.png"));


}

/**
 * @brief Ouvre une fenêtre de dialog pour ajouter un contact.
 */
void TollBar::ajouterContact()
{
    CreationContactDialog dialog(this);
    dialog.exec();
}

/**
 * @brief Ouvre une fenêtre de dialog pour la recherche de contact.
 */
void TollBar::chercherContact()
{

    resetActionTriggered();
    auto *dialog = new RechercheContactDialog(this);
    chercher->setDisabled(true);
    connect(dialog, &RechercheContactDialog::closeDialog, this, [this]()
    {
        chercher->setDisabled(false);
        resetActionTriggered();
    });
    dialog->show();

}

/**
 * @brief Remet a zero le Widget des contacts dans la mainWindow.
 */
void TollBar::resetActionTriggered()
{
    qobject_cast<MainWindow *>(Utility::getMainWindow(this))->resetListContactWidget();
}


/**
 * @brief Creation du menu pour le tri.
 */
void TollBar::createTriBtn()
{

    tri = new QToolButton(this);

    tri->setPopupMode(QToolButton::MenuButtonPopup);

    auto *menu = new QMenu(tri);

    auto *triNom = new QAction("Tri nom", menu);
    triNom->setIcon(QIcon("../src/tri.png"));

    auto *triDate = new QAction("Tri date", menu);
    triDate->setIcon(QIcon("../src/tri.png"));

    menu->addAction(triNom);
    menu->addAction(triDate);

    tri->setMenu(menu);

    tri->setDefaultAction(triDate);

    addWidget(tri);


    // tri par nom (ordre croissant).
    connect(triNom, &QAction::triggered, this, [this]()
    {
        qobject_cast<MainWindow *>(Utility::getMainWindow(this))->getLstContact()->sortNom();
        qobject_cast<MainWindow *>(
                Utility::getMainWindow(this))->findChildren<ListContactWidget *>().first()->recreateGroupeBoxContact();
    });

    // tri par date de creation le plus recent crée.
    connect(triDate, &QAction::triggered, this, [this]()
    {
        qobject_cast<MainWindow *>(Utility::getMainWindow(this))->getLstContact()->reverseDateCreation();
        qobject_cast<MainWindow *>(
                Utility::getMainWindow(this))->findChildren<ListContactWidget *>().first()->recreateGroupeBoxContact();
    });
}

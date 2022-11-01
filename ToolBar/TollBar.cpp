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

    ajouter = new QAction(this);
    ajouter->setIcon(QIcon("../src/ajouter.png"));
    ajouter->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_A));
    addAction(ajouter);

    connect(ajouter, &QAction::triggered, this, &TollBar::ajouterContact);

    addSeparator();

    chercher = new QAction(this);
    chercher->setIcon(QIcon("../src/chercher.png"));
    addAction(chercher);

    connect(chercher, &QAction::triggered, this, &TollBar::chercherContact);

    addSeparator();

    tri = new QAction(this);
    tri->setIcon(QIcon("../src/tri.png"));
    addAction(tri);

    addSeparator();

    resetListContactsWidget = new QAction(this);
    resetListContactsWidget->setIcon(QIcon("../src/reset.png"));
    addAction(resetListContactsWidget);

    connect(resetListContactsWidget, &QAction::triggered, this, &TollBar::resetActionTriggered);


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
    });
    dialog->show();

}

/**
 * @brief Remet a zero le widget des contacts dans la mainWindow.
 */
void TollBar::resetActionTriggered()
{
    qobject_cast<MainWindow *>(Utility::getMainWindow(this))->resetListContactWidget();
}

void TollBar::triContacts()
{

}

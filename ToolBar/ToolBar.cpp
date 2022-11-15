//
// Created by rahman on 01/11/22.
//

#include "ToolBar.h"
#include "../ContactDialog/CreationContactDialog.h"
#include "RechercheContact/RechercheContactDialog.h"
#include "RechercheTache/TreeTacheDialog.h"
#include "Suppression/SuppressionDialog.h"
#include <QTextEdit>
#include <QLayout>
#include <QListWidget>
#include <QApplication>


/**
 * @brief Constructeur par défaut de la classe ToolBar.
 * @param parent
 */
ToolBar::ToolBar(QWidget *parent) : QToolBar(parent)
{

    setContextMenuPolicy(Qt::ActionsContextMenu);

    ajouter = new QAction("Ajouter un contact", this);
    ajouter->setIcon(QIcon("src/ajouter.png"));
    ajouter->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_A));
    addAction(ajouter);

    connect(ajouter, &QAction::triggered, this, &ToolBar::ajouterContact);

    addSeparator();

    createFindBtn();

    addSeparator();

    createTriBtn();

    addSeparator();

    resetListContactsWidget = new QAction("Afficher tous les contacts", this);
    resetListContactsWidget->setIcon(QIcon("src/reset.png"));
    addAction(resetListContactsWidget);

    //Remet à zero le Widget des contacts dans la mainWindow.
    connect(resetListContactsWidget, &QAction::triggered, this, [=, this]()
    {
        emit resetActionTriggered();
    });

    addSeparator();

    historique = new QAction("Historique", this);
    historique->setIcon(QIcon("src/historique.png"));

    connect(historique, &QAction::triggered, this, &ToolBar::afficheHistorique);

    addAction(historique);

    addSeparator();

    suppression = new QAction(QApplication::style()->standardIcon(QStyle::SP_DialogDiscardButton), "Suppression");

    connect(suppression, &QAction::triggered, this, &ToolBar::supprimer);

    addAction(suppression);


}

/**
 * @brief Ouvre une fenêtre de dialog pour ajouter un contact.
 */
void ToolBar::ajouterContact()
{
    CreationContactDialog dialog(this);
    connect(&dialog, &CreationContactDialog::btnActionClicked, this, [this](StdContact *contact)
    {
        emit addContact(contact);
    });
    dialog.exec();
}

/**
 * @brief Ouvre une fenêtre de dialog pour la recherche de contact.
 */
void ToolBar::chercherContact()
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
 * @brief Creation du menu pour le tri.
 */
void ToolBar::createTriBtn()
{

    tri = new QToolButton(this);

    tri->setPopupMode(QToolButton::MenuButtonPopup);

    auto *menu = new QMenu(tri);

    auto *triNom = new QAction("Tri nom", menu);
    triNom->setIcon(QIcon("src/tri.png"));

    auto *triDate = new QAction("Tri date", menu);
    triDate->setIcon(QIcon("src/tri.png"));

    menu->addAction(triNom);
    menu->addAction(triDate);

    tri->setMenu(menu);

    tri->setDefaultAction(triDate);

    addWidget(tri);


    // tri par nom (ordre croissant).
    connect(triNom, &QAction::triggered, this, [this]()
    {
        qobject_cast<MainWindow *>(Utility::getMainWindow(this))->getLstContact()->sort(StdListContact::Nom);
        qobject_cast<MainWindow *>(
                Utility::getMainWindow(this))->findChildren<ListContactWidget *>().first()->recreateGroupeBoxContact();
    });

    // tri par date de creation le plus recent crée.
    connect(triDate, &QAction::triggered, this, [this]()
    {
        qobject_cast<MainWindow *>(Utility::getMainWindow(this))->getLstContact()->sort(StdListContact::Date);
        qobject_cast<MainWindow *>(
                Utility::getMainWindow(this))->findChildren<ListContactWidget *>().first()->recreateGroupeBoxContact();
    });
}

/**
 * @details Click sur l'action historique, qui affiche une fenêtre qui contient tous les historiques.
 */
void ToolBar::afficheHistorique()
{


    QDialog dialog;
    dialog.setWindowTitle("Historique");

    QGridLayout layout(&dialog);

    QListWidget wid;
    wid.setAlternatingRowColors(true);

    for (const auto &str: *qobject_cast<MainWindow *>(Utility::getMainWindow(this))->getHistorique())
        wid.addItem(QString::fromStdString(str).replace("\n", " | "));


    QPushButton effaceHistorique("Effacer l’historique", &dialog);

    connect(&effaceHistorique, &QPushButton::clicked, this, [&, this]()
    {
        emit clearHistoriqueClicked();
        wid.clear();
    });

    layout.addWidget(&wid);

    layout.addWidget(&effaceHistorique);

    dialog.exec();

}

/**
 * @brief Creation du menu pour la recherche.
 */
void ToolBar::createFindBtn()
{
    chercher = new QToolButton(this);
    chercher->setIcon(QIcon("src/chercher.png"));
    addWidget(chercher);

    chercher->setPopupMode(QToolButton::MenuButtonPopup);

    auto *findContact = new QAction("Chercher contact", this);
    findContact->setIcon(QIcon("src/contact.png"));
    connect(findContact, &QAction::triggered, this, &ToolBar::chercherContact);

    chercher->addAction(findContact);

    auto *findTache = new QAction("Chercher taches", this);
    findTache->setIcon(QIcon("src/todo.png"));
    connect(findTache, &QAction::triggered, this, &ToolBar::chercherTache);

    chercher->addAction(findTache);

}

/**
 * @brief Click sur le boutton de recherche d'une tache.
 */
void ToolBar::chercherTache()
{
    TreeTacheDialog diag(qobject_cast<MainWindow *>(
            Utility::getMainWindow(this))->getLstContact());

    diag.exec();
}


/**
 * @brief Click sur le boutton suppression.
 */
void ToolBar::supprimer()
{
    SuppressionDialog dialog(qobject_cast<MainWindow *>(
            Utility::getMainWindow(this))->getLstContact());
    connect(&dialog, &SuppressionDialog::contactSupprimer, this, [=, this](StdListContact *lst){
        emit suppContact(lst);
    });
    dialog.exec();

}

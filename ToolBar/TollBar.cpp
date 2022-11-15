//
// Created by rahman on 01/11/22.
//

#include "TollBar.h"
#include "../ContactDialog/CreationContactDialog.h"
#include "RechercheContact/RechercheContactDialog.h"
#include "RechercheTache/TreeTacheDialog.h"
#include <QTextEdit>
#include <QLayout>
#include <QCalendarWidget>


/**
 * @brief Constructeur par défaut de la classe TollBar.
 * @param parent
 */
TollBar::TollBar(QWidget *parent) : QToolBar(parent)
{

    setContextMenuPolicy(Qt::ActionsContextMenu);

    ajouter = new QAction("Ajouter un contact", this);
    ajouter->setIcon(QIcon("src/ajouter.png"));
    ajouter->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_A));
    addAction(ajouter);

    connect(ajouter, &QAction::triggered, this, &TollBar::ajouterContact);

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

    connect(historique, &QAction::triggered, this, &TollBar::afficheHistorique);

    addAction(historique);


}

/**
 * @brief Ouvre une fenêtre de dialog pour ajouter un contact.
 */
void TollBar::ajouterContact()
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
 * @brief Creation du menu pour le tri.
 */
void TollBar::createTriBtn()
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
void TollBar::afficheHistorique()
{
    QDialog dialog;
    dialog.setWindowTitle("Historique");

    QGridLayout layout(&dialog);

    QTextEdit textEdit(&dialog);
    textEdit.setReadOnly(true);

    QString contenu;

    int i = 1;
    for (const auto &str: *qobject_cast<MainWindow *>(Utility::getMainWindow(this))->getHistorique())
    {
        contenu += QString::number(i) + " : ";
        if (i % 2)
            contenu += "<font color=red>";
        else
            contenu += "<font color=blue>";
        contenu += QString::fromStdString(str).replace("\n", " | ") + "</font><br>";
        i++;
    }

    textEdit.insertHtml(contenu);

    QPushButton effaceHistorique("Effacer l’historique", &dialog);

    connect(&effaceHistorique, &QPushButton::clicked, this, [&, this]()
    {
        emit clearHistoriqueClicked();
        textEdit.clear();
    });

    layout.addWidget(&textEdit);

    layout.addWidget(&effaceHistorique);

    dialog.exec();

}

/**
 * @brief Creation du menu pour la recherche.
 */
void TollBar::createFindBtn()
{
    chercher = new QToolButton(this);
    chercher->setIcon(QIcon("src/chercher.png"));
    addWidget(chercher);

    chercher->setPopupMode(QToolButton::MenuButtonPopup);

    auto *findContact = new QAction("Chercher contact", this);
    findContact->setIcon(QIcon("src/contact.png"));
    connect(findContact, &QAction::triggered, this, &TollBar::chercherContact);

    chercher->addAction(findContact);

    auto *findTache = new QAction("Chercher taches", this);
    findTache->setIcon(QIcon("src/todo.png"));
    connect(findTache, &QAction::triggered, this, &TollBar::chercherTache);

    chercher->addAction(findTache);

}

/**
 * @brief Click sur le boutton de recherche d'une tache.
 */
void TollBar::chercherTache()
{
    TreeTacheDialog diag(qobject_cast<MainWindow *>(
            Utility::getMainWindow(this))->getLstContact());

    diag.exec();
}

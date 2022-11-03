//
// Created by Rahman  Yilmaz on 22/09/2022.
//

#include "MainWindow.h"
#include <QStatusBar>
#include "../ContactDialog/CreationContactDialog.h"
#include "../Menu/MenuBar.h"
#include "../ToolBar/TollBar.h"

/**
 * @details Constructeur de la classe MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setMinimumHeight(500);
    bd = new BD;

    lstContact = BD::getContactData();
    lstContact->reverseDateCreation();
    lstContactTmp = lstContact;

    setMenuBar(new MenuBar(this));


    layoutGauche = new QHBoxLayout;
    layoutDroit = new QHBoxLayout;


    setWindowTitle("Projet");
    auto *central = new QWidget;
    auto *layout = new QHBoxLayout(central);
    setCentralWidget(central);

    layout->addLayout(layoutGauche);
    layout->addLayout(layoutDroit);

    auto *status = new QStatusBar(this);


    nbContactLab = new QLabel("Nombre de contact : " + QString::number(lstContact->getLstContact()->size()));
    nbContactLab->setAlignment(Qt::AlignHCenter);
    status->addWidget(nbContactLab, 1);
    nbInetractionLab = new QLabel("Nombre d'interaction : ");
    status->addWidget(nbInetractionLab, 1);
    nbInetractionLab->setAlignment(Qt::AlignHCenter);

    setStatusBar(status);

    addToolBar(new TollBar(this));

    lstContact->reverseDateCreation();
    listContactWidget = new ListContactWidget(lstContact, this);
    layoutGauche->addWidget(listContactWidget);
}

/**
 * @brief Setter de lstContact qui est la liste de contact utilisé qui stock les contacts de recherche ou tous les contacts.
 * @return lstContact
 */
StdListContact *MainWindow::getLstContact() const
{
    return lstContact;
}

/**
 * @brief Setter de lstContactTmp qui est la liste de contact de base.
 * @return lstContactTmp
 */
StdListContact *MainWindow::getLstContactTmp() const
{
    return lstContactTmp;
}

/**
 *
 * @param event
 */
void MainWindow::closeEvent(QCloseEvent *event)
{
    QWidget::closeEvent(event);
    delete lstContact;
    delete bd;
    if (lstContactTmp != lstContact)
    {
        lstContactTmp->getLstContact()->clear();
        delete lstContactTmp;
    }

}

/**
 * Ajouter un StdContact dans la liste des contacts et dans le Widget des contacts pour l'afficher.
 * @param contact
 */
void MainWindow::addContact(const StdContact &contact)
{
    auto *c = new StdContact(contact);
    lstContact->addContact(c);
    if (lstContact != lstContactTmp)
        lstContactTmp->addContact(c);
    listContactWidget->addContactBox(c);
    BD::addContactOnBD(contact);
    updateNbContact();
}

void MainWindow::suppContact(StdContact *contact)
{
    lstContact->supContact(contact);
    lstContactTmp->removeContact(contact);
    updateNbContact();
}

void MainWindow::rechercheListContactWidget(StdListContact *lst)
{
    lstContact = lst;
    listContactWidget->cacheGroupeBox(lst);

    updateNbContact();

    removeListInteractionWidget();

    setNbInteraction("");

}

/**
 * Ajoute un Widget avec la liste d'interaction
 * @param widget
 */
void MainWindow::setListInteractionWidget(ListInteractionWidget *widget)
{
    removeListInteractionWidget();

    layoutDroit->addWidget(widget);
    listInteractionWidget = widget;


    connect(listInteractionWidget, &ListInteractionWidget::updateNbInteraction, this, &MainWindow::setNbInteraction);
    setNbInteraction(QString::number(listInteractionWidget->getLstInteraction()->size()));
}

/**
 * @details Remet à 0 le Widget qui affiche les contacts, c'est-à-dire supprime l'ancien listContactWidget,
 * recrée une nouvelle listContactWidget avec les contacts dans lstContact, enlève aussi le Widget qui affiche les interactions d'un contact s'il est affiché.
 */
void MainWindow::resetListContactWidget()
{
    lstContact = lstContactTmp;
    lstContact->reverseDateCreation();
    reactualise();
}

/**
 * @brief Fonction qui met à jour la valeur de nbContactLab qui indique le nombre de contacts visible.
 */
void MainWindow::updateNbContact()
{
    nbContactLab->setText("Nombre de contact : " + QString::number(lstContact->size()));
}

/**
 * @brief Fonction qui met à jour la valeur de nbInetractionLab qui indique le nombre de d'interaction du contact sélectionné.
 */
void MainWindow::setNbInteraction(const QString &number)
{
    nbInetractionLab->setText("Nombre d'interaction : " + number);
}


void MainWindow::reactualise()
{
    removeListInteractionWidget();

    listContactWidget->afficheAllGroupeBox();

    setNbInteraction("");
    updateNbContact();
}

void MainWindow::removeListInteractionWidget()
{

    if (listInteractionWidget)
        listInteractionWidget->hide();
}
